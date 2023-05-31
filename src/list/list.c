// Author: James M
// 25/05/2023
// Library for a standard List data structure

#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int intSize = sizeof(int);

// Create a default list on the heap
List* create_list()
{
    List* list = (List*) malloc(sizeof(List));
    list->length = 0;
    list->size = 0;
    list->elements = 0;
    return list;
}

// Attempt to free a list and it's elements
void free_list(List* list)
{
    free(list->elements);
    free(list);
}

// Add an element to a list
int add_list(List* list, int element)
{    
    list->size += intSize;
    
    if (list->length == 0)
    {
        list->elements = malloc(list->size);
        list->elements[0] = element;
        list->length++;
        return 1;
    }

    list->elements = realloc(list->elements, list->size);
    list->elements[list->length] = element;
    list->length++;
    return 1;
}

// Remove index from a list
int remove_list(List* list, int index)
{
    if (list->length <= index)
    {
        // index is outside list
        return 0;
    }
    
    list->length--;
    list->size -= intSize;
    
    if (list->length == index)
    {
        // removes last element in list
        list->elements = realloc(list->elements, list->size);
        return 1;
    }

    // shift elements down and resize memory
    for(int i = index+1; i <= list->length; i++)
    {
        list->elements[index++] = list->elements[i];
    }
    list->elements = realloc(list->elements, list->size);
    
    return 1;
}
