#include <stdio.h>

void test_function(int **number_double_pointer)
{
	**number_double_pointer = 7;
}

int main (void)
{
	int number = 3;
	int *number_pointer = &number;

	test_function(&number_pointer);
	printf("number = %d\n", number);

	return 0;
}
