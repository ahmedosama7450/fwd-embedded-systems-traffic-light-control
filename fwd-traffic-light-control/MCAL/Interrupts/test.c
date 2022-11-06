/*
 * test.c
 *
 * Created: 10/19/2022 6:41:33 PM
 *  Author: ahmed
 */ 


#include "interrupts.h"
#include "../DIO/dio.h"
#include "../Timer/timer.h"

int pressed = 0;

int testInterrupts()
{
	INTERRUPTS_init();
	DIO_init(PORT_A, PIN0, OUT);
	// DIO_init(PORT_D, PIN2, IN);
	
	while(1) {
		if(pressed) {
			DIO_write(PORT_A, PIN0, HIGH);
			TIMER_delay_1s();
			pressed = 0;
		} else {
			DIO_write(PORT_A, PIN0, LOW);
		}
	}
	
	return 0;
}

ISR(EXT_INT_0) {
	pressed = 1;
}
