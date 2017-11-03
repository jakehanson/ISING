#pragma once
#include <vector>
#include <iostream>
#include <random>
#include <stdio.h>
#include <map>


/* Structure to hold the current properties of the Ising Model */
struct Ising_Model
{
	Ising_Model(int n_rows, int n_cols, double T, long N_steps);  // signature for constructor, construct instance of class

	std::vector<unsigned long long> states; // 1d array to hold the name of all states
	std::vector<std::vector<int>> spin_matrix;	// 2d array for the current spin matrix
	long current_step; // integer denoting the number of steps taken
	int num_rows; // number of rows
	int num_cols; //number of columns
	long num_steps; // number of simulation steps
	double temp; // temperature of the model

	/* Define Methods */
	void evolve(std::ostream &time_series);
	void evolve(void);
};

std::tuple<int, int, int, int> get_nn(int index,int n_rows,int n_cols);

/* Overload '<<' to easily write spin_matrix data to file */
std::ostream &operator<<(std::ostream &out, std::vector<std::vector<int>> spin_matrix);

/* Function to convert spin state to integer using binary representaion */
unsigned long long get_state(std::vector<std::vector<int>> spin_matrix, int num_rows, int num_cols);

/* Function to create a map for compressing the large state space into as small of a state space as possible */
std::map<unsigned long long,unsigned long long> update_map(std::vector<unsigned long long> states,std::map<unsigned long long,unsigned long long> compression_map);

/* Function to calculate the Effective Information (EI) of a sequence of states assuming ID = H_max (Hoel 2017) */
std::vector<std::vector<double>> get_TPM(std::vector<unsigned long long> state_array,unsigned long long compressed_size,long N_steps);

/* Function to calculate EI using mutual info */
double get_EI(std::vector<double> ID,std::vector<double> ED,std::vector<std::vector<double>> TPM);

/* Function to calculate energy of a spin state */
template <size_t bitsetsize>
double get_E(std::bitset<bitsetsize> state){
	
	int n_rows = sqrt(state.size());
	int n_cols = sqrt(state.size());

	double E_tot; // energy value
	int left_nn,right_nn,up_nn,down_nn; // nearest neighbor values
	int left_index,right_index,up_index,down_index; // nearest neighbor indices

	/* For each state find the local energy and add it to the total */
	E_tot = 0;
	double nn_sum = 0;
	double value = 0; // holds the value of the spin matrix at the location of the index in question
	for(int index=0;index<state.size();index++){
		std::tie(left_index, right_index, up_index, down_index) = get_nn(index,n_rows,n_cols); // gets nn indices
		
		//switch 0's to -1's
		if(state[left_index]==0){
			left_nn = -1;
		}else{
			left_nn = 1;
		}
		if(state[right_index]==0){
			right_nn = -1;
		}else{
			right_nn = 1;
		}	
		if(state[up_index]==0){
			up_nn = -1;
		}else{
			up_nn = 1;
		}
		if(state[down_index]==0){
			down_nn = -1;
		}else{
			down_nn = 1;
		}
		if(state[index]==0){
			value = -1;
		}else{
			value = 1;
		}

		// calculate energy sum over nearest neighbors
		nn_sum = value*(left_nn+right_nn+up_nn+down_nn);
		E_tot = E_tot - 1/2.*nn_sum*value;
	}

	return E_tot;
}
