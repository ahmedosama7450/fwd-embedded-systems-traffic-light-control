/*
 * test.c
 *
 * Created: 10/19/2022 6:31:04 PM
 *  Author: ahmed
 */ 

#include "dio.h"

int testDIO() {
	DIO_init(PORT_A, PIN0, IN);
	DIO_init(PORT_A, PIN1, OUT);
	
	while (1) {
		uint8_t value = 0;
		DIO_read(PORT_A, PIN0, &value);
		DIO_write(PORT_A, PIN1, value);
	}
}