#pragma once
#include <vector>
#include <iostream>
#include <random>

/* Structure to hold the current properties of the Ising Model */
struct Ising_Model
{
	Ising_Model(int n_rows, int n_cols, double T, int N_steps);  // signature for constructor, construct instance of class

	std::vector<int> states; // 1d array to hold the binary name of all states
	std::vector<std::vector<int>> spin_matrix;	// 2d array for the current spin matrix
	int current_state; // the integer value of the current state
	int current_step; // integer denoting the number of steps taken
	int num_rows; // number of rows
	int num_cols; //number of columns

	/* Define Methods */
	// void initialize(void); // Call to randomly initialize model w/o insisting a seed or random device
	//void initialize(int seed); // Call to random initialize model using a random int seed
	//void initialize(std::randome_device &rd); // Call to random initialize model using a random device
	//void evolve(int n_steps); // function to evolve the system through a given number of steps

};


/* Overload "<<" to easily write density data to file */
std::ostream &operator<<(std::ostream &out, Ising_Model const &model);

/* Operator overload to write Model to output stream */
//std::ostream &operator<<(std::ostream &out, Ising_Model const &Model);

// /* Functions that take Ising Model as argument */
// double get_t_wall(Ants ants,double L,double H,double r_enc, int &index1);
// double get_t_ant(Ants ants,double r_enc,double t_wall, int &index2, int &index3);