/*
 * dio.h
 *
 * Created: 10/19/2022 4:51:46 PM
 *  Author: ahmed
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utils/helpers.h"
#include "../../Utils/registers.h"

typedef enum EN_direction_t
{
	IN,
	OUT
} EN_direction_t;

typedef enum EN_pin_t
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7
} EN_pin_t;

typedef enum EN_port_t
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
} EN_port_t;

EN_error_state DIO_init(EN_port_t port, EN_pin_t pin, EN_direction_t direction); 
EN_error_state DIO_write(EN_port_t port, EN_pin_t pin, uint8_t value); 
EN_error_state DIO_toggle(EN_port_t port, EN_pin_t pin); 
EN_error_state DIO_read(EN_port_t port, EN_pin_t pin, uint8_t *value);

#endif /* DIO_H_ */