/*
 * LED.h
 *
 * Created: 4/14/2023 4:51:32 PM
 *  Author: hanee
 */ 
#ifndef LED_H_
#define LED_H_


#include "std_types.h"

#define LED_DDRB DDRB
#define LED_PORTB PORTB
#define LED_DDRA DDRA
#define LED_PORTA PORTA

void led_init(uint8 pin_num);
void led_on(uint8 pin_num);
void led_off(uint8 pin_num);
void led_toggle(uint8 pin_num);



#endif /* LED_H_ */