/*
 * interrupts.h
 *
 * Created: 10/19/2022 5:17:16 PM
 *  Author: ahmed
 */ 


#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

#include "../../Utils/helpers.h"
#include "../../Utils/registers.h"

// External interrupts vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2
#define EXT_INT_2 __vector_3

// Macro to enable global interrupts
#define  sei() __asm__ __volatile__ ("sei" ::: "memory")

// ISR definition
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal, used));\
void INT_VECT(void)

void INTERRUPTS_init();

#endif /* INTERRUPTS_H_ */