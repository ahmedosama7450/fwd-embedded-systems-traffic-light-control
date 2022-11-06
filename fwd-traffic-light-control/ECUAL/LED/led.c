/*
 * led.c
 *
 * Created: 10/19/2022 4:50:20 PM
 *  Author: ahmed
 */ 

#include "led.h"

void LEDS_init() {
	DIO_init(LED_CARS_PORT, LED_RED_PIN, OUT);
	DIO_init(LED_CARS_PORT, LED_YELLOW_PIN, OUT);
	DIO_init(LED_CARS_PORT, LED_GREEN_PIN, OUT);

	DIO_init(LED_PEDESTRIANS_PORT, LED_RED_PIN, OUT);
	DIO_init(LED_PEDESTRIANS_PORT, LED_YELLOW_PIN, OUT);
	DIO_init(LED_PEDESTRIANS_PORT, LED_GREEN_PIN, OUT);
}

EN_error_state LED_on(EN_port_t port, EN_pin_t pin) {
	return DIO_write(port, pin, HIGH);
}

EN_error_state LED_off(EN_port_t port, EN_pin_t pin) {
	return DIO_write(port, pin, LOW);
}

EN_error_state LED_toggle(EN_port_t port, EN_pin_t pin) {
	return DIO_toggle(port, pin);
}

EN_error_state LED_blink(EN_port_t port, EN_pin_t pin) {
	EN_error_state errorState = LED_on(port, pin);
	
	if(errorState != ERR) {
		for(int i = 0; i < 5; i++) {
			errorState = ACCUMULATE_ERROR(TIMER_delay_1s(), errorState);
			errorState = ACCUMULATE_ERROR(LED_toggle(port, pin), errorState);
			if(errorState == ERR) break;
		}
	}
	
	return errorState;
}

EN_error_state LED_double_blink(EN_port_t port1, EN_pin_t pin1, EN_port_t port2, EN_pin_t pin2) {
	EN_error_state errorState = OK;

	errorState = ACCUMULATE_ERROR(LED_on(port1, pin1), errorState);
	errorState = ACCUMULATE_ERROR(LED_on(port2, pin2), errorState);
	for(int i = 0; i < 5; i++) {
		errorState = ACCUMULATE_ERROR(TIMER_delay_1s(), errorState);
		errorState = ACCUMULATE_ERROR(LED_toggle(port1, pin1), errorState);
		errorState = ACCUMULATE_ERROR(LED_toggle(port2, pin2), errorState);
		if(errorState == ERR) break;
	}
	
	return errorState;
}

EN_error_state LED_on_only(EN_port_t port, EN_pin_t pin) {
	EN_error_state errorState = LED_on(port, pin);

	if(pin == LED_RED_PIN) {
		errorState = ACCUMULATE_ERROR(LED_off(port, LED_GREEN_PIN), errorState);
		errorState = ACCUMULATE_ERROR(LED_off(port, LED_YELLOW_PIN), errorState);
	} else if(pin == LED_GREEN_PIN) {
		errorState = ACCUMULATE_ERROR(LED_off(port, LED_RED_PIN), errorState);
		errorState = ACCUMULATE_ERROR(LED_off(port, LED_YELLOW_PIN), errorState);
	} else if(pin == LED_YELLOW_PIN) {
		errorState = ACCUMULATE_ERROR(LED_off(port, LED_RED_PIN), errorState);
		errorState = ACCUMULATE_ERROR(LED_off(port, LED_GREEN_PIN), errorState);
	}
	
	return errorState;
}