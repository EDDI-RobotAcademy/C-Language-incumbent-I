#include <stdio.h>

int check_calling_convention (int num1, int num2, int num3, int num4,
							int num5, int num6, int num7, int num8)
{
	return num1 + num2 + num3 + num4 + num5 + num6 + num7 + num8;
}

int main (void)
{
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4;
	int num5 = 5, num6 = 6, num7 = 7, num8 = 8, result;

	result = check_calling_convention(
		num1, num2, num3, num4, num5, num6, num7, num8);

	printf("result = %d\n", result);

	return 0;
}
