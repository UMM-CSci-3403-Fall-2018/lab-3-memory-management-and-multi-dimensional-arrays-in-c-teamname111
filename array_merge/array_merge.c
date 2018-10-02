#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#include "mergesort.c"
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	int j = 0;
	for(int k = 0; k < num_arrays; ++k){
		j = j + sizes[k];	
			}
	int* found_values = (int*) calloc(j+1, sizeof(int));
	found_values[0]= 0;
	for(int i = 0; i < num_arrays; i++){
		for(int k = 0; k< sizes[i]; k++){
			bool l = true;
			for(int n = 1 ; n <= found_values[0]; n++){
				if(values[i][k] == found_values[n]){
				l = false;
				}
			}
			if(l){
				found_values[0] = found_values[0] + 1;	
				found_values[found_values[0]] = values[i][k];
			}
		}
	}
	int* tempArray = (int*) calloc(found_values[0] + 1, sizeof(int));
	for(int i = 1; i <= found_values[0]; i++){
		tempArray[i] = found_values[i];
		}
	mergesort(found_values[0]+1, tempArray);
	int* result = (int*) calloc(found_values[0]+1, sizeof(int));
	result[0] = found_values [0];
	for(int i = 1; i <= found_values[0]; i++){
		result[i] = tempArray[i];
		}
 	free(found_values);
	free(tempArray);	
	return result;
}
