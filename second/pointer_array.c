#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define	DIMENSION			3

#define MIN					1
#define MAX					7

int custom_random (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void init_matrix (int (*mat)[3])
{
	int i, j;

	for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
			mat[i][j] = custom_random(MIN, MAX);
		}
	}
}

void print_matrix (int (*mat)[3])
{
	int i, j;

	printf("matrix:\n");

	for (i = 0; i < DIMENSION; i++)
	{
		for (j = 0; j < DIMENSION; j++)
		{
			printf("%3d", mat[i][j]);
		}
		printf("\n");
	}
}

int main (void)
{
	int matrix_A[3][3] = { 0 };
	int matrix_B[3][3] = { 0 };

	srand(time(NULL));

	init_matrix(matrix_A);
	init_matrix(matrix_B);

	print_matrix(matrix_A);
	print_matrix(matrix_B);
}
