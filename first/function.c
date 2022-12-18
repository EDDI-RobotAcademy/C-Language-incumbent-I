#include <stdio.h>

int multiply_two (int num)
{
	return num << 1;
}

int main (void)
{
	int num = 3, result;
	result = multiply_two(num);

	printf("result = %d\n", result);

	return 0;
}
