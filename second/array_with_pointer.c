#include <stdio.h>

#define MAX				7

void init_array(int *array)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		array[i] = i + 1;
	}
}

void print_array(int *array)
{
	int i;

	for (i = 0; i < MAX; i++)
	{
		printf("array[%d] = %d\n", i, array[i]);
	}
}

int main (void)
{
	int array[MAX] = {};

	init_array(array);
	print_array(array);

	return 0;
}
