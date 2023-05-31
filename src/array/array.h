// Author: James M
// 31/05/2023
// Header for an array

#ifndef ARRAY_H
#define ARRAY_H


typedef struct array
{
	int length;
	int* elements;
} Array;

// Create a default array
// @param length Number of elements to allocate memory for
Array* create_array(int length);

// Free memory used by array including the elements
// @param array Reference to the array to free
void free_array(Array* array);

// Assign array element at given index
// @param array Reference to array
// @param element Data to store
// @param index Position in array to store at
// @returns Zero on failure. One on success.
int set_array_element(Array* array, int element, int index);

#endif