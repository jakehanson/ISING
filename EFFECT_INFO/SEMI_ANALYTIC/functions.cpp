#include "header.h"

/* Function to get nearest neighbors on a lattice using 1d index */
std::tuple<int, int, int, int> get_nn(int index,int n_rows,int n_cols){
	int left_index,right_index,up_index,down_index;

	// get left nearest neighbor
	left_index = index - 1;
	if(index%n_cols == 0){
		left_index = left_index + n_cols;
	}
	// get right nearest neighbor
	right_index = index + 1;
	if((index+1)%n_cols == 0){
		right_index = right_index - n_cols;
	}
	// get above nearest neighbor
	if(index>(n_cols-1)){
		up_index = index-n_cols;
	}else{
		up_index = index+(n_rows-1)*n_cols;
	}
	// get below nearest neighbor
	if(index+n_cols < n_rows*n_cols){
		down_index = index+n_cols;
	}else{
		down_index = (index+n_cols)%(n_rows*n_cols);
	}

	return std::make_tuple(left_index, right_index, up_index, down_index);
}