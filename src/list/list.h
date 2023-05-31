// Author: James M
// 25/05/2023
// Header for list

#ifndef LIST_H
#define LIST_H

typedef struct list
{
    int length;
    int size;
    int* elements;
} List;

List* create_list();

void free_list(List* list);

int add_list(List* list, int element);

int remove_list(List* list, int index);

#endif
