
#include "header.h"
#include <fstream>


/* Main Function to Evolve Ising Model and Return list of States */
int main(int argc, char** argv)
{
	int n_rows = 3; // number of rows
	int n_cols = 3; // number of columns
	double T = 1.0e-10;  // Temperature of the ising model
	long N_steps = 10000;
	
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

	/* Store parameters in file */
	std::ofstream params("params.txt");
	params << "n_rows = " << n_rows << "\t" << "n_cols = " << n_cols << "\t" << "Temperature = " << T << "\t" 
				<< "Total Steps = " << N_steps<< "\n";
	params.close();


	/* Initialize Simulation */
	Ising_Model model = Ising_Model(n_rows,n_cols,T,N_steps); // create Ising Model named 'model'
	
	/* Run Sim and Store Spin Matrices in File */
	//std::ofstream time_series("time_series.txt");
	model.evolve(); // evolve it through N_steps and
	//time_series.close();

	/* Write time series of states to output file */
	std::ofstream states("states.txt");
	for(int i=0;i<N_steps;i++){
		states << model.states[i] << std::endl;
	}
	states.close();

	std::cout << "Done.\n"; // End Main

}