/*
 * application.c
 *
 * Created: 10/19/2022 2:56:52 PM
 *  Author: ahmed
 */ 

#include "app.h"

uint8_t isNormalMode = 1;
uint8_t wasRedLedOn = 0;
uint8_t buttonPressed = 0;

void normalMode() {
	// For pedestrians, turn on red
	LED_on_only(LED_PEDESTRIANS_PORT, LED_RED_PIN);

	// For cars, turn on green at first
	LED_on_only(LED_CARS_PORT, LED_GREEN_PIN);
	TIMER_delay_5s();
	wasRedLedOn = 0;
	if(buttonPressed) return;

	// Then, turn off green => blink yellow
	LED_off(LED_CARS_PORT, LED_GREEN_PIN);
	LED_blink(LED_CARS_PORT, LED_YELLOW_PIN);
	wasRedLedOn = 0;
	if(buttonPressed) return;

	// Lastly, turn off yellow => turn on red
	LED_off(LED_CARS_PORT, LED_YELLOW_PIN);
	LED_on(LED_CARS_PORT, LED_RED_PIN);
	TIMER_delay_5s();
	wasRedLedOn = 1;
	if(buttonPressed) return;
}

void pedestrianMode() {
	if(wasRedLedOn) {
		// For cars, turn on red
		LED_on_only(LED_CARS_PORT, LED_RED_PIN);

		// For pedestrians, turn on green
		LED_on_only(LED_PEDESTRIANS_PORT, LED_GREEN_PIN);
	} else {
		// For cars and pedestrians, blink both yellow
		LED_off(LED_CARS_PORT, LED_RED_PIN);
		LED_off(LED_CARS_PORT, LED_GREEN_PIN);
		LED_off(LED_PEDESTRIANS_PORT, LED_RED_PIN);
		LED_off(LED_PEDESTRIANS_PORT, LED_GREEN_PIN);
		LED_double_blink(LED_CARS_PORT, LED_YELLOW_PIN, LED_PEDESTRIANS_PORT, LED_YELLOW_PIN);
		
		// The, turn off both yellow => turn on cars red led and pedestrians green led
		LED_off(LED_CARS_PORT, LED_YELLOW_PIN);
		LED_off(LED_PEDESTRIANS_PORT, LED_YELLOW_PIN);
		LED_on(LED_CARS_PORT, LED_RED_PIN);
		LED_on(LED_PEDESTRIANS_PORT, LED_GREEN_PIN);
	}
	
	TIMER_delay_5s();
	
	// Turn off cars red => Blink both yellow
	LED_off(LED_CARS_PORT, LED_RED_PIN);
	LED_double_blink(LED_CARS_PORT, LED_YELLOW_PIN, LED_PEDESTRIANS_PORT, LED_YELLOW_PIN);
	
	isNormalMode = 1;
	wasRedLedOn = 0;
	buttonPressed = 0;
}

void APP_init() {
	LEDS_init();
	BUTTON_init();
	TIMER_init();
}

void APP_start() {
	if(isNormalMode) {
		normalMode();
	} else {
		pedestrianMode();
	}
}

ISR(EXT_INT_0) {
	if(!buttonPressed) {
		isNormalMode = 0;
		buttonPressed = 1;
	}
}
