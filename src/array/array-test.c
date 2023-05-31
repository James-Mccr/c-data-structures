// Author: James M
// 31/05/2023
// Program to test array.c

#include <stdio.h>
#include "array.h"

static unsigned char debug = 1;

int assert_equal(Array* expected, Array* actual)
{

	if (expected == NULL || actual == NULL)
	{
		if (debug)
		{
			printf("FAIL: Null pointer. Expected: %d Actual %d\n", expected, actual);	
		}
		return 0;
	}
	
	if (expected->length != actual->length)
	{
		if (debug)
		{
			printf("FAIL: Lengths not equal. Expected: %d Actual %d\n", expected->length, actual->length);	
		}
		return 0;
	}

	if (expected->elements == NULL || actual->elements == NULL)
	{
		if (debug)
		{
			printf("FAIL: Null elements pointer. Expected %d Actual %d\n", expected->elements, actual->elements);
		}
		return 0;
	}

	for (int i = 0; i < expected->length; i++)
	{
		if (expected->elements[i] != actual->elements[i])
		{
			if (debug)
			{
				printf("assert_equal: Elements not equal. Expected: [%d] %d Actual [%d] %d\n", i, expected->elements[i], i, actual->elements[i]);	
			}
			return 0;
		}
	}


	printf("PASS\n");	
	return 1;
}

void test_create_array()
{
	printf("test_create_array...");
	int ints[3] = { 0 };
	Array* actual = create_array(3);
	Array expected = { 3, ints };

	assert_equal(&expected, actual);

	free_array(actual);
}


void test_set_array_element()
{
	printf("test_set_array_element...");
	int ints[5] = { 1, 2, 3, 4, 5 };
	Array* actual = create_array(5);
	Array expected = { 5, ints };

	for (int i = 0; i < 5; i++)
	{
		set_array_element(actual, i+1, i);
	}

	assert_equal(&expected, actual);

	free_array(actual);
}

void test_assert_equal()
{
	printf("test_assert_equal...");
    
    int elements[3] = { -1, 0, 1 };
    int elements2[3] = { 5, 4, 3 };
    Array actual = { 3, elements };
    Array wrongLength = { 2, elements };
    Array wrongElements = { 3, elements2 };

    debug = 0;
    
    if (!assert_equal(&actual, &actual)
        || assert_equal(&actual, &wrongLength)
        || assert_equal(&actual, &wrongElements))
        {
            printf("FAIL\n");
        }

   	debug = 1;
}

void main()
{
	printf("Running tests...\n");

	test_assert_equal();

	test_create_array();

	test_set_array_element();
}