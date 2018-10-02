#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "mergesort.c"
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	int j = 0;
	//adding all the sizes together and storing in j
	for(int k = 0; k < num_arrays; ++k){
		j = j + sizes[k];	
			}
	//makes an array the length of the sum of the sizes to store
	//one of each value
	int* found_values = (int*) calloc(j+1, sizeof(int));
	found_values[0]= 0;
	//loops over the values array to put values into found_values
	for(int i = 0; i < num_arrays; i++){
		for(int k = 0; k< sizes[i]; k++){
			bool l = true;
			//checking if values[i][k] is in found_values yet
			for(int n = 1 ; n <= found_values[0]; n++){
				if(values[i][k] == found_values[n]){
				l = false;
				}
			}
			//if l is still true increments the first value of found_values
			//and sets the the index of the first value of found_values
			//to be values[i][k]
			if(l){
				found_values[0] = found_values[0] + 1;	
				found_values[found_values[0]] = values[i][k];
			}
		}
	}
	//creates a temp array to store all the values from index 1
	//to found_values[0]+1 in found_values
	int* tempArray = (int*) calloc(found_values[0]+1, sizeof(int));
	for(int i = 1; i <= found_values[0]; i++){
		tempArray[i] = found_values[i];
		}
	//sorts tempArray
	mergesort(found_values[0]+1, tempArray);
	//creates the result array which puts found_values[0] in index
	//1 and puts the sorted values of tempArray in the remaining 
	//positions
	int* result = (int*) calloc(found_values[0]+1, sizeof(int));
	result[0] = found_values [0];
	for(int i = 1; i <= found_values[0]; i++){
		result[i] = tempArray[i];
		}
	//frees memory and returns
 	free(found_values);
	free(tempArray);	
	return result;
}
