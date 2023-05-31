// Author: James M
// 26/05/2023
// Program to test list.c

#include <stdio.h>
#include "list.h"

int assert_equal(List* actual, List* expected)
{
    if (actual->length != expected->length)
    {
        printf("List length not equal. Actual %d. Expected %d.\n", actual->length, expected->length);
        return 0;
    }
    
    if (actual->size != expected->size)
    {
        printf("List size not equal. Actual %d. Expected %d.\n", actual->size, expected->size);
        return 0;
    }
    
    for (int i = 0; i < actual->length; i++)
    {
        if (actual->elements[i] != expected->elements[i])
        {
            printf("Lists not equal. Actual[%d] = %d. Expected[%d] = %d.\n", i, actual->elements[i], i, expected->elements[i]);
            return 0;
        }
    }
    
    printf("PASS\n");
    return 1;
}

void test_remove_list()
{
    printf("test_remove_list...");
    int elements[5] = { 1,2,3,4,5 };
    int elements2[4] = { 1,2,4,5 };
    List expected = { 4, 16, elements2 };
    List* actual = create_list();
    add_list(actual, 1);
    add_list(actual, 2);
    add_list(actual, 3);
    add_list(actual, 4);
    add_list(actual, 5);
    remove_list(actual, 2);
    
    assert_equal(actual, &expected);
}

void test_add_list()
{
    printf("test_add_list...");
    List* actual = create_list();
    add_list(actual, -1);
    add_list(actual, 0);
    add_list(actual, 1);

    int elements[3] = { -1, 0, 1 };
    List expected = { 3, 12, elements };
    
    assert_equal(actual, &expected);
    
    free_list(actual);
}

void test_create_list()
{
    printf("test_create_list...");
    List* actual = create_list();
    List expected = { 0, 0, 0 };
    
    assert_equal(actual, &expected);
    
    free_list(actual);
}

void test_assert_equal()
{
    printf("test_assert_equal...");
    
    int elements[3] = { -1, 0, 1 };
    int elements2[3] = { 5, 4, 3 };
    List actual = { 3, 12, elements };
    List wrongLength = { 2, 12, elements };
    List wrongSize = { 3, 1, elements };
    List wrongElements = { 3, 12, elements2 };
    
    if (!assert_equal(&actual, &actual)
        || assert_equal(&actual, &wrongLength)
        || assert_equal(&actual, &wrongSize)
        || assert_equal(&actual, &wrongElements))
        {
            printf("FAIL\n");
        }
}

void main()
{
    printf("Running tests...\n");
    
    test_assert_equal();

    test_create_list();
    
    test_add_list();
    
    test_remove_list();
}
