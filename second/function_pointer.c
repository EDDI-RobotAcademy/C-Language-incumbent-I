#include <time.h>
#include <stdio.h>
#include <stdlib.h>

enum test_values
{
	BLDC_MOTOR = 1,
	CAMERA = 2,
	PMSM_MOTOR = 3,
	RADAR = 4
};

void (* global_function_pointer_handler) (void);

void bldc_motor_control (void)
{
	printf("bldc motor control\n");
}

void camera_control (void)
{
	printf("camera control\n");
}

void pmsm_motor_control (void)
{
	printf("pmsm motor control\n");
}

void radar_control (void)
{
	printf("radar control\n");
}

int custom_random (int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void select_global_function_pointer (int selected_number)
{
	if (selected_number == BLDC_MOTOR)
	{
		global_function_pointer_handler = bldc_motor_control;
	}
	else if (selected_number == CAMERA)
	{
		global_function_pointer_handler = camera_control;
	}
	else if (selected_number == PMSM_MOTOR)
	{
		global_function_pointer_handler = pmsm_motor_control;
	}
	else if (selected_number == RADAR)
	{
		global_function_pointer_handler = radar_control;
	}
}

void call_global_function_pointer (int selected_number)
{
	global_function_pointer_handler();
}

int main (void)
{
	int random_number;

	srand(time(NULL));

	random_number = custom_random(BLDC_MOTOR, RADAR);
	select_global_function_pointer(random_number);
	call_global_function_pointer(random_number);

	return 0;
}
