/*
 * LED.c
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed 
 */
#include"LED.h"
#include"gpio.h"
#include"LDR.h"

void LEDS_init(void){
/*
 * Initializes all Leds (red, green, blue) pins direction.
   Turn off all the Leds
 * */
	GPIO_setupPinDirection(PORTB_ID,PIN5_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN6_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(PORTB_ID,PIN7_ID,PIN_OUTPUT);
	GPIO_writePin(PORTB_ID,led_red,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,led_green,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,led_blue,LOGIC_LOW);
}
void LED_on(uint8 LED_ID_id) {
	//Turns on the specified LED.
#if(LED_STATE == LED_NEGITIVE_LOGIC)
	//LED connect NEGITIVE logic
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_LOW);
#elif(LED_STATE == LED_POSITIVE_LOGIC)
	//LED is connect Positive Logic
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_HIGH);
#endif

}
void LED_off(uint8 LED_ID_id) {
//Turns off the specified LED.
#if(LED_STATE == LED_NEGITIVE_LOGIC)
	//LED connect NEGITIVE logic
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_HIGH);
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_HIGH);
#elif(LED_STATE == LED_POSITIVE_LOGIC)
	//LED is connect Positive Logic
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_LOW);
	GPIO_writePin(PORTB_ID,LED_ID_id,LOGIC_LOW);
#endif
}
