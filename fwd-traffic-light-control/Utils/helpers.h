/*
 * types.h
 *
 * Created: 10/19/2022 2:58:26 PM
 *  Author: ahmed
 */ 


#ifndef TYPES_H_
#define TYPES_H_

#define SET_BIT(X, BIT_NO) X |= (1 << BIT_NO)
#define CLR_BIT(X, BIT_NO) X &= ~(1 << BIT_NO)
#define TOGGLE_BIT(X, BIT_NO) X ^= (1 << BIT_NO)
#define GET_BIT(X, Y, BIT_NO) X = (Y & (1 << BIT_NO)) >> BIT_NO

#define HIGH 1
#define LOW 0

typedef enum EN_error_state
{
	OK,
	ERR
} EN_error_state;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#endif /* TYPES_H_ */