#include <stdio.h>

float pf_test(int num, char *p)
{
	printf("p = %s\n", p);
	printf("num = %d\n", num);

	return 3.3f;
}

float pf_test2(int num, char *p)
{
	printf("p = %s\n", p);
	printf("num = %d\n", num * 2);

	return 7.7f;
}

int main(void)
{
	// float (*) (int num, char *p)
	float (* fp)(int num, char *p) = pf_test;
	printf("%f\n", fp(3, "안녕"));

	fp = pf_test2;
	printf("%f\n", fp(3, "곤치니와"));
}
