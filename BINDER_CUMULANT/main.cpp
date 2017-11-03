
#include "header.h"
#include <fstream>


/* Main Function to Evolve Ising Model and Return list of States */
int main(int argc, char** argv)
{

	// First get lattice size and temperature
	int n_rows;
	int n_cols;
	double T;
	if(argc == 1){
		n_rows = 3;
		n_cols = 3;
		T = 2.0;
	}else{
		n_rows = atoi(argv[1]);
		n_cols = atoi(argv[1]);
		T = atof(argv[2]);
	}

	long N_steps = 1e7;  // Number of steps to take in a given simulation
	long N_sims = 1; // Number of times to reinitialize and run a simulation

	std::map<unsigned long long,unsigned long long> compression_map; // map storing minimal representation of state space
	std::vector<unsigned long long> state_array; // holds the state trajectory

	/* Make Sure Input Params are valid */
	try{
		if(n_rows != n_cols){
			throw std::runtime_error("SQUARE LATTICES ONLY - N_ROWS MUST MATCH N_COLS. CHECK VALUES IN MAIN.CPP");  // raise error if lattice isn't square
		}
		if(T <= 0.){
			throw std::runtime_error("TEMPERATURE MUST BE POSITIVE!");
		}
	}catch(std::runtime_error &e){
		std::cerr << "RUNTIME ERROR: " << e.what() << std::endl;
		return 1;
	}

	std::cout << "Starting...\n";

	/* Store parameters in file */
	std::ofstream params("params.txt");
	params << "n_rows\tn_cols\tTemperature\tSteps\t\n";
	params << n_rows << "\t" << n_cols << "\t" << T << "\t" << N_steps<< "\n";
	params.close();


	/* Initialize and run simulations */
	std::ofstream magnetization("magnetization.txt");

	//std::cout << "N_rows:\t" << n_rows << std::endl;
	//std::cout << "N_cols:\t" << n_cols << std::endl;
	std::cout << "T:\t" << T << std::endl;
	//std::cout << "Size of state space: " << pow(2.,n_rows*n_cols) << std::endl;\
	std::cout << "Realized States\n"; // write some general info to screen

	for(int n=0;n<N_sims;n++){

		Ising_Model model = Ising_Model(n_rows,n_cols,T,N_steps); // Initialize new model at T
		
		// save magnetization in file
		int M = 0;
		for(int i=0;i<n_rows;i++){
			for(int j=0;j<n_rows;j++){
				M += model.spin_matrix[i][j];
			}
		}
		magnetization << M << "\n";	

		// evolve
		model.evolve(magnetization);

		// Update our compression map	
		compression_map = update_map(model.states,compression_map);

		// Write states of current model to file and update state array
		for(long j=0;j<N_steps;j++){
			state_array.push_back(compression_map[model.states[j]]); // add the compressed state to the state array
		}


		std::cout << compression_map.size() << std::endl;

	
	}

	/* Close open files */
	magnetization.close();
	std::cout << "Done.\n"; // End Main

}