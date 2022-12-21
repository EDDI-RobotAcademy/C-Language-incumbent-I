#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

typedef struct _i2c_data i2c_data;

#define TWO_BYTE			2

#define MIN					0x68
#define MAX					0xcc

struct _i2c_data
{
	int speed;
	char *rx_buf;
	char *tx_buf;
};

int custom_random (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void init_i2c_device (i2c_data *i2c_device_data)
{
	// 포인터 타입인 경우 구조체 내부에 접근한다면 -> 연산자를 사용합니다.
	i2c_device_data->speed = 100000;
	i2c_device_data->rx_buf = (char *)malloc(sizeof(char) * TWO_BYTE);
	i2c_device_data->tx_buf = malloc(sizeof(char) * TWO_BYTE);
	// malloc()의 리턴 타입은 기본적으로 void *에 해당합니다.
}

void init_other_i2c_mechanism(i2c_data test)
{
	test.speed = 100000;
	test.rx_buf = (char *)malloc(sizeof(char) * TWO_BYTE);
	printf("test speed = %d\n", test.speed);
}

void receive_i2c_data (i2c_data *i2c_device_data)
{
	int i;

	for (i = 0; i < TWO_BYTE; i++)
	{
		i2c_device_data->rx_buf[i] = custom_random(MIN, MAX);
	}
}

void print_i2c_data (i2c_data i2c_device_data)
{
	int i;

	printf("i2c speed: %d\n", i2c_device_data.speed);
	printf("receive data: ");

	for (i = 0; i < TWO_BYTE; i++)
	{
		printf("0x%2x ", i2c_device_data.rx_buf[i] & 0xff);
	}
	printf("\n");
}

void finish_program (i2c_data i2c_device_data)
{
	// 포인터가 아닌 구조체 내부에 접근할 때는 '.' 연산자를 사용합니다.
	free(i2c_device_data.rx_buf);
	free(i2c_device_data.tx_buf);
}

int main (void)
{
	srand(time(NULL));

	// typedef struct _i2c_data i2c_data;
	// 구조체 변수 선언
	i2c_data i2c_device_data;
	i2c_data test;

	init_i2c_device(&i2c_device_data);
	receive_i2c_data(&i2c_device_data);
	print_i2c_data(i2c_device_data);
	finish_program(i2c_device_data);

	init_other_i2c_mechanism(test);
	printf("test speed = %d\n", test.speed);

	return 0;
}
