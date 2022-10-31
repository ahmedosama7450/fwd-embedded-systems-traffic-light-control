/*
 * interrupts.c
 *
 * Created: 10/19/2022 5:17:28 PM
 *  Author: ahmed
 */ 

#include "interrupts.h"

void INTERRUPTS_init() {
	// Enable global interrupt
	sei();
	
	// Set INT0 sense to rising edge
	MCUCR |= (1 << 0) | (1 << 1);
	
	// Enable INT0
	SET_BIT(GICR, 6);
}