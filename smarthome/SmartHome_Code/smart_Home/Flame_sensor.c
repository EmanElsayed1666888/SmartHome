/*
 * Flame_sensor.c
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed
 */
#include"Flame_sensor.h"
#include"gpio.h"
void FlameSensor_init(void){
	//Initializes the flame sensor pin direction.
	GPIO_setupPinDirection(PORTD_ID ,PIN2_ID,PIN_INPUT);
}
uint8 FlameSensor_getValue(void){
	//Reads the value from the flame sensor and returns it.
	uint8 read_value = GPIO_readPin(PORTD_ID ,PIN2_ID );
	return read_value;
}

