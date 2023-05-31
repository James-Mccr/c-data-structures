// Author: James M
// 31/05/2023
// Library for a standard array

#include <stdlib.h>
#include "array.h"

Array* create_array(int length)
{
	Array* array = malloc(sizeof(Array));
	array->length = length;
	array->elements = calloc(length, sizeof(int));
	return array;
}


void free_array(Array* array)
{
	free(array->elements);
	free(array);
}


int set_array_element(Array* array, int element, int index)
{
	if (array == NULL)
	{
		return 0;	// no array
	}

	if (index < 0 || index > array->length)
	{
		return 0;	// index out of bounds
	}

	array->elements[index] = element;

	return 1;
}