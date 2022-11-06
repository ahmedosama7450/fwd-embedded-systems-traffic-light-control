/*
 * timer.h
 *
 * Created: 10/19/2022 4:51:58 PM
 *  Author: ahmed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utils/helpers.h"
#include "../../Utils/registers.h"

void TIMER_init();
EN_error_state TIMER_start(uint16_t prescaler, uint8_t initialValue);
void TIMER_stop();
EN_error_state TIMER_delay(float delay_in_ms, uint16_t prescaler);
EN_error_state TIMER_delay_5s();
EN_error_state TIMER_delay_1s();

#endif /* TIMER_H_ */