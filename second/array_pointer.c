#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MIN			3
#define MAX			7

int custom_random (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void alloc_variant_array(int *array[MAX])
{
	int i, j, random_number;

	for (i = 0; i < MAX; i++)
	{
		random_number = custom_random(MIN, MAX);
		array[i] = (int *)malloc(sizeof(int) * random_number);

		for (j = 0; j < random_number; j++)
		{
			array[i][j] = custom_random(MIN, MAX);
			printf("array[%d][%d] = %d\n", i, j, array[i][j]);
		}
		printf("\n");
	}
}

int main (void)
{
	srand(time(NULL));

	int *integer_array[MAX] = { 0 };

	alloc_variant_array(integer_array);

	return 0;
}
