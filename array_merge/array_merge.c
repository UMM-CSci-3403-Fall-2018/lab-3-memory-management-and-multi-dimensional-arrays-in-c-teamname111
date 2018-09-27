#include <stdlib.h>
#include <stdbool.h>

#include "mergesort.h"
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values){
	int j = 0;
	for(int k = 0; k < sizes; ++k){
		j = j + sizes[k];	
			}
	int* found_values = calloc(j+1, sizeof(int))
	found_values[0]= '\0';
	int current_location_of_null = 0;
	for(int i = 0; i < num_arrays; i++){
		for(int k = 0; k< size[i]; k++){
				bool l = true;
				while(found_values[n] != '\0'){
					if(values[i][k] == found_values[n]){
					l = false;
					}
					n++;
				}
				if(m){
				found_values[current_location_of_null] = values[i][k];
				++current_location_of_null;
				found_values[current_location_of_null] = '\0';
				}
				}
	}

	int* tempArray = calloc(current_location_of_null, sizeof(int));

	for(int i = 0; i < current_location_of_null; i++){
		tempArray[i] = found_values[i];
	}
	free(found_values);
	mergesort(tempArray, current_location_of_null);
	int* result = calloc(current_location_of_null+1, sizeof(int));
	result[0] = current_location_of_null;
	for(int i = 0; i < current_location_of_null+1; i++){
		result[i+1] = tempArray[i];
	}
	return *result;
}
