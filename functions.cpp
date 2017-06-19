#include "header.h"
#include <stdio.h>
#include <cmath>
#include <stdexcept>

/* Define our constructor. Pass Args to this to create an instance of Ising Model Class */
/* Note: Its a constructor because there's no return type and method name 'Ising_Model' matches class name. */

Ising_Model::Ising_Model(int n_rows, int n_cols, double T, int N_steps)
{
	states = std::vector<int>(N_steps,0);
	current_state = 0;
	current_step = 0;
}

void Ising_Model::init_matrix(int n_rows, int n_cols){
	spin_matrix = std::vector<std::vector<int>>(n_rows,std::vector<int>(n_cols,0)); // initialize 2d matrix with null spins
}