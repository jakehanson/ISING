#pragma once
#include <vector>
#include <iostream>
#include <random>

/* Structure to hold the current properties of the Ising Model */
struct Ising_Model
{
	Ising_Model(int n_rows, int n_cols, double T, long N_steps);  // signature for constructor, construct instance of class

	std::vector<int> states; // 1d array to hold the binary name of all states
	std::vector<std::vector<int>> spin_matrix;	// 2d array for the current spin matrix
	int current_step; // integer denoting the number of steps taken
	int num_rows; // number of rows
	int num_cols; //number of columns
	int num_steps; // number of simulation steps
	double temp; // temperature of the model

	/* Define Methods */
	void evolve();
};


/* Overload '<<' to easily write spin_matrix data to file */
std::ostream &operator<<(std::ostream &out, std::vector<std::vector<int>> spin_matrix);

/* Other Functions */
int get_state(std::vector<std::vector<int>> spin_matrix, int num_rows, int num_cols);