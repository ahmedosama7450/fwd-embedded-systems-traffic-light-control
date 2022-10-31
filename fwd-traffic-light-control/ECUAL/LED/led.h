/*
 * led.h
 *
 * Created: 10/19/2022 4:50:30 PM
 *  Author: ahmed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Timer/timer.h"

// LEDs ports & pins
#define LED_CARS_PORT PORT_A
#define LED_PEDESTRIANS_PORT PORT_B

#define LED_RED_PIN PIN2
#define LED_YELLOW_PIN PIN1
#define LED_GREEN_PIN PIN0

void LEDS_init();
void LED_on(EN_port_t port, EN_pin_t pin);
void LED_off(EN_port_t port, EN_pin_t pin);
void LED_toggle(EN_port_t port, EN_pin_t pin);
void LED_blink(EN_port_t port, EN_pin_t pin);
void LED_double_blink(EN_port_t port1, EN_pin_t pin1, EN_port_t port2, EN_pin_t pin2);
void LED_on_only(EN_port_t port, EN_pin_t pin);

#endif /* LED_H_ */