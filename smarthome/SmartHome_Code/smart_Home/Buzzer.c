/*
 * Buzzer.c
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed
 */
#include"Buzzer.h"
#include"gpio.h"
void Buzzer_init(void){
//Initializes the buzzer pin direction and turn off the buzzer.
	GPIO_setupPinDirection(PORTD_ID , PIN3_ID , PIN_OUTPUT);
}
void Buzzer_on(void){
//Activates the buzzer.
	GPIO_writePin(PORTD_ID,PIN3_ID,LOGIC_HIGH);
}
void Buzzer_off(void){
	//Deactivates the buzzer.
	GPIO_writePin(PORTD_ID,PIN3_ID,LOGIC_LOW);
}

