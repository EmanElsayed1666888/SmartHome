/*
 * ADC.c
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed
 */
#include"common_macros.h"
#include"gpio.h"
#include"ADC.h"
#include<avr/io.h>
void ADC_init(void){
	// internal 2.56V Reference
	SET_BIT(ADMUX,REFS0); //BIT 6
	SET_BIT(ADMUX,REFS1); //BIT 7

	// choose channel__ 1
	SET_BIT(ADMUX,MUX0); //BIT 0
	SET_BIT(ADCSRA ,ADEN);// Enable ADC
	CLEAR_BIT(ADCSRA , ADIE); //  ADC Interrupt DisEnable

    // ADC Prescaler Selections
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
}
uint16 ADC_readChannel(uint8 ch_num){
	ADMUX = (ADMUX & 0xE0)|(ch_num & 0X07);
	/*ch_num &=0x07;
	ADMUX = 0xE0 ;//        1110 0000
	ADMUX = ADMUX | ch_num ;*/

	SET_BIT(ADCSRA , ADSC);// ADC Start Conversion

	while(BIT_IS_CLEAR(ADCSRA, ADIF));

	CLEAR_BIT(ADCSRA,ADIF);// ADC Interrupt Flag

	return ADC ;
}
