#include "header.h"


/* Main */
int main(int argc, char** argv)
{

	int n_rows = 3; // number of rows
	int n_cols = 3; // number of columns
	const int N_spins = 9; // total number of spins (MUST BE INITIALIZED MANUALLY)\

	if(N_spins != n_rows*n_cols){
		std::cout << "ERROR! N_spins must be equal to n_rows*n_cols.\n";
		return 0;
	}
	if(n_rows != n_cols){
		std::cout << "ERROR! Rows and columns must match.\n";
		return 0;
	}

	long int N_states = pow(2,n_rows*n_cols);
	std::vector<std::vector<double>> delta_E(N_states,std::vector<double>(N_states,0.)); // holds energy difference between state

	for(int i=0;i<N_states;i++){

		std::bitset<N_spins> state(i); // creates a binary string representing integer i
		std::cout << i << "=>" << state << std::endl;
		std::cout << "\t Energy = " << get_E(state) << std::endl;

		// Determine which states are one bit flip away and populate the delta_E matrix
	}

}



// /* Function to calculate energy of a spin state */
// template <size_t bitsetsize>
// double get_E(std::bitset<bitsetsize> state){
	
// 	int n_rows = sqrt(state.size());
// 	int n_cols = sqrt(state.size());

// 	double E_tot; // energy value
// 	int left_nn,right_nn,up_nn,down_nn; // nearest neighbor values
// 	int left_index,right_index,up_index,down_index; // nearest neighbor indices

// 	/* For each state find the local energy and add it to the total */
// 	E_tot = 0;
// 	double nn_sum = 0;
// 	double value = 0; // holds the value of the spin matrix at the location of the index in question
// 	for(int index=0;index<state.size();index++){
// 		std::tie(left_index, right_index, up_index, down_index) = get_nn(index,n_rows,n_cols); // gets nn indices
		
// 		//switch 0's to -1's
// 		if(state[left_index]==0){
// 			left_nn = -1;
// 		}else{
// 			left_nn = 1;
// 		}
// 		if(state[right_index]==0){
// 			right_nn = -1;
// 		}else{
// 			right_nn = 1;
// 		}	
// 		if(state[up_index]==0){
// 			up_nn = -1;
// 		}else{
// 			up_nn = 1;
// 		}
// 		if(state[down_index]==0){
// 			down_nn = -1;
// 		}else{
// 			down_nn = 1;
// 		}
// 		if(state[index]==0){
// 			value = -1;
// 		}else{
// 			value = 1;
// 		}

// 		// calculate energy sum over nearest neighbors
// 		nn_sum = value*(left_nn+right_nn+up_nn+down_nn);
// 		E_tot = E_tot - 1/2.*nn_sum*value;
// 	}

// 	return E_tot;
// }


// /* Function to get nearest neighbors on a lattice using 1d index */
// std::tuple<int, int, int, int> get_nn(int index,int n_rows,int n_cols){
// 	int left_index,right_index,up_index,down_index;

// 	// get left nearest neighbor
// 	left_index = index - 1;
// 	if(index%n_cols == 0){
// 		left_index = left_index + n_cols;
// 	}
// 	// get right nearest neighbor
// 	right_index = index + 1;
// 	if((index+1)%n_cols == 0){
// 		right_index = right_index - n_cols;
// 	}
// 	// get above nearest neighbor
// 	if(index>(n_cols-1)){
// 		up_index = index-n_cols;
// 	}else{
// 		up_index = index+(n_rows-1)*n_cols;
// 	}
// 	// get below nearest neighbor
// 	if(index+n_cols < n_rows*n_cols){
// 		down_index = index+n_cols;
// 	}else{
// 		down_index = (index+n_cols)%(n_rows*n_cols);
// 	}

// 	return std::make_tuple(left_index, right_index, up_index, down_index);
// }
