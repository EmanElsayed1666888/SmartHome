/*
 * LED.h
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed 
 */

#ifndef LED_H_
#define LED_H_
#include "std_types.h"
#define  LED_STATE LOGIC_HIGH


#define LED_POSITIVE_LOGIC LOGIC_HIGH
#define LED_NEGITIVE_LOGIC LOGIC_LOW
#define led_red		PIN5_ID
#define led_green 	PIN6_ID
#define led_blue	PIN7_ID
void LEDS_init(void) ;
void LED_on(uint8 LED_ID_id) ;
void LED_off(uint8 LED_ID_id) ;
#endif /* LED_H_ */
