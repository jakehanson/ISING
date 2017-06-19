#include "header.h"
#include <stdio.h>
#include <cmath>
#include <stdexcept>

/* Define our constructor. Pass Args to this to create an instance of Ising Model Class */
/* Note: Its a constructor because there's no return type and method name 'Ising_Model' matches class name. */

Ising_Model::Ising_Model(int n_rows, int n_cols, double T, int N_steps){

	if(n_rows != n_cols){
		throw std::runtime_error("SQUARE LATTICES ONLY - N_ROWS MUST MATCH N_COLS. CHECK VALUES IN MAIN.CPP");  // raise error if lattice isn't square
	}else{
		num_rows = n_rows;
		num_cols = n_cols;
	}

	states = std::vector<int>(N_steps,0);
	current_state = 0;
	current_step = 0;
	spin_matrix = std::vector<std::vector<int>>(n_rows,std::vector<int>(n_cols,0)); // initialize 2d matrix with null spins

}

/* Define function to overload the operator "<<" such that if the input 
is std:ostream &out and &Ising_Model it prints the relevant info */
std::ostream &operator<<(std::ostream &out, Ising_Model const &model){
	
	out << "n_rows\t" << "n_cols\t" << "current step\n" << "spin matrix\n";

	for(int i=0;i<model.num_rows;i++){
		for(int j=0;j<model.num_cols;j++){
			if((j+1)%(model.num_cols) == 0){
				out << model.spin_matrix[i][j] << "\n";
			}else{
				out << model.spin_matrix[i][j] << "\t";	
			}
		}
	}
	out << std::endl;
	// double phi,r,mu;
	// phi = 0;
	// for(int i=0;i<Haumea.mu_size;i++){
	// 	mu = Haumea.mu_array[i];
	// 	for(int k=0;k<Haumea.r_size;k++){
	// 		r = Haumea.r_array[k];
	// 		out << Haumea.iter << "\t" << phi << "\t" << mu << "\t" << r << "\t" << Haumea.density[0][i][k] << 
	// 		"\t" << Haumea.g_potential[0][i][k] << std::endl;
	// 	}
	// }

	return out;
}
