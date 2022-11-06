/*
 * button.h
 *
 * Created: 10/19/2022 4:50:51 PM
 *  Author: ahmed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"
#include "../../MCAL/Interrupts/interrupts.h"

#define BUTTON_PORT PORT_D
#define BUTTON_PIN PIN2

void BUTTON_init();

#endif /* BUTTON_H_ */