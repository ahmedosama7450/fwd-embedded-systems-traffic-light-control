/*
 * test.c
 *
 * Created: 10/19/2022 8:16:55 PM
 *  Author: ahmed
 */ 


#include "led.h"
#include "../../MCAL/Timer/timer.h"

int testLED(void)
{
	LEDS_init();
	TIMER_init();
	while(1)
	{
		
		LED_on(LED_CARS_PORT, LED_GREEN_PIN);
		LED_on(LED_CARS_PORT, LED_GREEN_PIN);
		
		TIMER_delay(100, 256);
		
		LED_off(LED_CARS_PORT, LED_GREEN_PIN);
		LED_off(LED_CARS_PORT, LED_GREEN_PIN);	
	}
}
