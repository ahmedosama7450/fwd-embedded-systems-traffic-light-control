/*
 * dio.c
 *
 * Created: 10/19/2022 4:51:40 PM
 *  Author: ahmed
 */ 

#include "dio.h"

EN_error_state DIO_init(EN_port_t port, EN_pin_t pin, EN_direction_t direction) {
	// Set the direction of the given pin
	
	switch (port) {
		case PORT_A:
			if (direction == IN) CLR_BIT(DDRA, pin); 
			else SET_BIT(DDRA, pin); 
			
			break;
		case PORT_B:
			if (direction == IN) CLR_BIT(DDRB, pin);
			else if (direction == OUT) SET_BIT(DDRB, pin);
			
			break;
		case PORT_C:
			if (direction == IN) CLR_BIT(DDRC, pin);
			else if (direction == OUT) SET_BIT(DDRC, pin);

			break;
		case PORT_D:
			if (direction == IN) CLR_BIT(DDRD, pin); 
			else if (direction == OUT) SET_BIT(DDRD, pin);

			break;
		default:
			return ERR;
	}
	
	return OK;
}

EN_error_state DIO_write(EN_port_t port, EN_pin_t pin, uint8_t value) {
	// Write HIGHT or LOW on the given pin
	
	switch (port) {
		case PORT_A:
			if (value == LOW) CLR_BIT(PORTA, pin);
			else if (value == HIGH) SET_BIT(PORTA, pin);

			break;
		case PORT_B:
			if (value == LOW) CLR_BIT(PORTB, pin);
			else if (value == HIGH) SET_BIT(PORTB, pin);

			break;
		case PORT_C:
			if (value == LOW)  CLR_BIT(PORTC, pin);
			else if (value == HIGH) SET_BIT(PORTC, pin);

			break;
		case PORT_D:
			if (value == LOW) CLR_BIT(PORTD, pin);
			else if (value == HIGH) SET_BIT(PORTD, pin);
			
			break;
		default:
			return ERR;
	}
	
	return OK;
}

EN_error_state DIO_toggle(EN_port_t port, EN_pin_t pin) {
	// Toggle the state of the given pin

	switch (port) {
		case PORT_A:
			TOGGLE_BIT(PORTA, pin);
			break;
		case PORT_B:
			TOGGLE_BIT(PORTB, pin);
			break;
		case PORT_C:
			TOGGLE_BIT(PORTC, pin);
			break;
		case PORT_D:
			TOGGLE_BIT(PORTD, pin);
			break;
		default:
			return ERR;
	}
	
	return OK;
}

EN_error_state DIO_read(EN_port_t port, EN_pin_t pin, uint8_t *value) {
	// Read the state of the given pin

	switch (port) {
		case PORT_A:
			GET_BIT(*value, PINA, pin);
			break;
		case PORT_B:
			GET_BIT(*value, PINB, pin);
			break;
		case PORT_C:
			GET_BIT(*value, PINC, pin);
			break;
		case PORT_D:
			GET_BIT(*value, PIND, pin);
			break;
		default:
			return ERR;
	}
	
	return OK;
}
