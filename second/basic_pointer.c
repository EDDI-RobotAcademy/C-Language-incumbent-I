#include <stdio.h>

#define FIRST_NUMBER			3

int main (void)
{
	int number = FIRST_NUMBER;
	int *pointer = &number;

	printf("*pointer = %d, number = %d\n", *pointer, number);
	printf("pointer = %p, &number = %p\n", pointer, &number);

	return 0;
}
