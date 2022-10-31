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

void LED_on(EN_port_t port, EN_pin_t pin) {
	DIO_write(port, pin, HIGH);
}

void LED_off(EN_port_t port, EN_pin_t pin) {
	DIO_write(port, pin, LOW);
}

void LED_toggle(EN_port_t port, EN_pin_t pin) {
	DIO_toggle(port, pin);
}

void LED_blink(EN_port_t port, EN_pin_t pin) {
	LED_on(port, pin);
	for(int i = 0; i < 5; i++) {
		TIMER_delay_1s();
		LED_toggle(port, pin);
	}
}

void LED_double_blink(EN_port_t port1, EN_pin_t pin1, EN_port_t port2, EN_pin_t pin2) {
	LED_on(port1, pin1);
	LED_on(port2, pin2);
	for(int i = 0; i < 5; i++) {
		TIMER_delay_1s();
		LED_toggle(port1, pin1);
		LED_toggle(port2, pin2);
	}
}

void LED_on_only(EN_port_t port, EN_pin_t pin) {
	LED_on(port, pin);
	if(pin == LED_RED_PIN) {
		LED_off(port, LED_GREEN_PIN);
		LED_off(port, LED_YELLOW_PIN); 
	} else if(pin == LED_GREEN_PIN) {
		LED_off(port, LED_RED_PIN); 
		LED_off(port, LED_YELLOW_PIN); 
	} else if(pin == LED_YELLOW_PIN) {
		LED_off(port, LED_RED_PIN);
		LED_off(port, LED_GREEN_PIN); 
	}
}