/*
 * timer.c
 *
 * Created: 10/19/2022 4:52:07 PM
 *  Author: ahmed
 */ 

#include "timer.h"
#include <math.h>

void TIMER_init() {
	// Set timer mode to normal
	TCCR0 = 0X00;
	
	// Set timer initial value to 0
	TCNT0 = 0x00;
}

EN_error_state TIMER_start(uint16_t prescaler, uint8_t initialValue)
{
	// Set initial value
	TCNT0 = initialValue;
	
	// Set prescaler, after which the timer starts
	switch (prescaler) {
		case 1:
			// Set pin0
			SET_BIT(TCCR0, 0);
			break;
		case 8:
			// Set pin1
			SET_BIT(TCCR0, 1);
			break;
		case 64:
			// set pin0 and pin1
			TCCR0 |= 3;
			break;
		case 256:
			// Set pin2
			SET_BIT(TCCR0, 2);
			break;
		case 1024:
			// Set pin0 and pin2
			TCCR0 |= 5;
			break;
		default:
			return ERR;
			break;
	}
	
	return OK;
	
}

void TIMER_stop()
{
	// Set prescaler to zero
	TCCR0 = 0x00;
}

EN_error_state TIMER_delay(float delay_in_ms, uint16_t prescaler)
{		
	// Timer calculations
	double clk_freq = 1000000; // 10^6
	int timer_max_count = 256; // 8^2

	double tick = ((double) prescaler / clk_freq) * 1000;
	double max_delay = tick * timer_max_count;
	int num_overflows = (int) ceil(delay_in_ms / max_delay);
	int initial_value = (int)(timer_max_count - (delay_in_ms / tick) / 2);
	
	// Start timer and count overflows until given delay
	EN_error_state errorState = TIMER_start(prescaler, initial_value);
	
	if(errorState == OK) {
		uint32_t overflow_counter = 0;
		while (overflow_counter < num_overflows)
		{
			// Wait for the overflow flag to be set
			while ((TIFR & (1 << 0)) == 0) {}
			
			// Clear the overflow flag
			TIFR |= (1 << 0);
		
			overflow_counter++;
		}
	
		TIMER_stop();
	}
	
	return errorState;
}

EN_error_state TIMER_delay_5s() {
	return TIMER_delay(5000, 1024);
}

EN_error_state TIMER_delay_1s() {
	return TIMER_delay(1000, 1024);
}
