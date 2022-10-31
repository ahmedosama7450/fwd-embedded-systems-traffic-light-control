/*
 * test.c
 *
 * Created: 10/19/2022 8:05:43 PM
 *  Author: ahmed
 */ 

#include "timer.h"
#include "../DIO/dio.h"

int testTimer(void)
{
	TIMER_init();
	DIO_init(PORTA, PIN0, OUT);
	while(1)
	{
		TIMER_delay_1s();
		DIO_toggle(PORT_A, PIN0);
	}
}
