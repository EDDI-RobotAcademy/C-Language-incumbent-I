#include <stdio.h>

#define FIRST_NUMBER			3

int main (void)
{
	int number = FIRST_NUMBER;
	int *pointer = &number;
	int **double_pointer = &pointer;

	printf("**double_pointer = %d, number = %d\n", **double_pointer, number);
	printf("double_pointer = %p, &pointer = %p\n", double_pointer, &pointer);
	printf("pointer = %p, &number = %p\n", pointer, &number);

	return 0;
}
