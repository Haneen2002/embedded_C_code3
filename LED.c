/*
 * CFile1.c
 *
 * Created: 4/14/2023 4:51:47 PM
 *  Author: hanee
 */ 
#include "LED.h"
#define F_CPU (16000000UL)
#include<util/delay.h>
#include "BIT_MATH.h"
#include "ATmega32_Rrgiosters.h"
#include "std_types.h"

void led_init(uint8_t pin_num) {
	if(pin_num == pin7)
	  {
		  LED_DDRB |= (1 << pin_num); // Set the pin direction as output
	  }
	else
	  LED_DDRA |= (1 << pin_num); // Set the pin direction as output
	
}

void led_on(uint8_t pin_num) {
	if(pin_num == pin7)
     { 
		 LED_PORTB |= (1 << pin_num); // Set the pin HIGH to turn on the LED
	 }
	 else
	   LED_PORTA |= (1 << pin_num); // Set the pin HIGH to turn on the LED
}

void led_off(uint8_t pin_num) {
	if(pin_num == pin7)
	{
		LED_PORTB &= ~(1 << pin_num); // Set the pin LOW to turn off the LED
	}
	else
	  LED_PORTA &= ~(1 << pin_num); // Set the pin LOW to turn off the LED
	
}

void led_toggle(uint8_t pin_num) {
	if(pin_num == pin7)
	{
	  LED_PORTB ^= (1 << pin_num); // Toggle the pin to switch the LED state
	}
	else
	  LED_PORTA ^= (1 << pin_num); // Toggle the pin to switch the LED state
}