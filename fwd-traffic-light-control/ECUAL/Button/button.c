/*
 * button.c
 *
 * Created: 10/19/2022 4:50:58 PM
 *  Author: ahmed
 */ 

#include "button.h"

void BUTTON_init() {
	DIO_init(BUTTON_PORT, BUTTON_PIN, IN);
}

//uint8_t BUTTON_pressed() {
	//uint8_t pressed;
	//DIO_read(BUTTON_PORT, BUTTON_PIN, &pressed);
	//return pressed;
//}
