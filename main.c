#include <avr/interrupt.h>
#include "EXT_INT1.h"
#include "BIT_MATH.h"

#include "std_types.h"
#include "LED.h"
#define F_CPU (16000000UL)
#include "util/delay.h"

volatile uint8_t count=0;
#define LED_1 PIN7
#define LED_2 PIN6
#define LED_3 PIN5
#define LED_4 PIN4


void roll_leds()
{
	SET_BIT(DDRB,LED_1);
	SET_BIT(DDRA,LED_2);
	SET_BIT(DDRA,LED_3);
	SET_BIT(DDRA,LED_4);
	
	if(count==0)
	{
		led_on(LED_1);
		led_off(LED_4);
		count++;
	}
	else if(count==1)
	{
		led_on(LED_2);
		led_off(LED_1);
		
		count++;
	}
	else if(count==2)
	{
		led_on(LED_3);
		led_off(LED_2);
		count++;
	}
	else if(count==3)
	{
		led_on(LED_4);
		led_off(LED_3);
		count=0;
	}
	
}

void flash_leds(void)
{
	 // flash the LEDs five times
	 for (int i = 0; i < 5; i++) {

		// turn on all LEDs
		led_on(LED_1);
		led_on(LED_2);
		led_on(LED_3);
		led_on(LED_4);
		
		_delay_ms(500);
		
		// turn off all LEDs
		led_off(LED_1);
		led_off(LED_2);
		led_off(LED_3);
		led_off(LED_4);
		_delay_ms(500);
	 }
	
}


int main(void)
{
	
    INT1_Init();
	led_init(LED_1);
	led_init(LED_2);
	led_init(LED_3);
	led_init(LED_4);
	
	INT1_setCallBack(&flash_leds);
	
	
	while (1) {
		// roll the LEDs every half second
		_delay_ms(500);
		roll_leds();
		
		
	}
}








