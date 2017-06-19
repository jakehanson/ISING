
#include "header.h"
#include <fstream>


/* Main Function to Evolve Ising Model and Return list of States */
int main(int argc, char** argv)
{
	int n_rows = 3; // number of rows
	int n_cols = 3; // number of columns
	double T = 0.00001;  // Temperature of the ising model
	int N_steps = 10;


	/* Create a Model */
	try{
		Ising_Model model = Ising_Model(n_rows,n_cols,T,N_steps); // create Ising Model named 'model'
		std::cout << model;
	}
	catch(std::runtime_error &e){
		std::cerr << "RUNTIME ERROR: " << e.what() << std::endl;
		return 1;
	}

	
	std::cout << "Done.\n";
}