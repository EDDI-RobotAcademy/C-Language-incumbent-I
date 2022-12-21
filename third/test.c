#include <stdio.h>

void (* signal(int, void *))(void);

int main (void)
{
	printf("test\n");
	return 0;
}
