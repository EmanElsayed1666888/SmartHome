/*
 * LDR.c
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed 
 */
#include"LDR.h"
#include"ADC.h"
uint16 LDR_getLightIntensity(void){
//Reads the LDR sensor value and returns the light intensity.
	uint8 LDR_value = 0;

	uint16 adc_value = 0;
	adc_value = ADC_readChannel(LDR_SENSOR_CHANNEL_ID);
	LDR_value = (uint8)(((uint32)adc_value*LDR_SENSOR_MAX_LIGHT_INTENSITY*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*LDR_SENSOR_MAX_VOLT_VALUE));

	return LDR_value ;
}

