/*
 * Application.c
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed
 */
#include"gpio.h"
#include"MOTOR.h"
#include"PWM.h"
#include"LCD_driver.h"
#include"LDR.h"
#include"LED.h"
#include"Flame_sensor.h"
#include"Buzzer.h"
#include"ADC.h"
#include<util/delay.h>
uint8 Read_Intensity , Read_Flame_Value , read_temp ;
int main(){
	init_Hardware_drivers();
	while(TRUE){
		Read_Flame_Value=FlameSensor_getValue();
		if(Read_Flame_Value ){
			Buzzer_on();
			LCD_Display_String_ROW_COL(0,0,"Critical alert! ");
			LCD_Display_String_ROW_COL(1,0,"                ");
		}else{
			Buzzer_off();
			Read_Intensity=LDR_getLightIntensity();
			read_temp = LM35_getTemperature();
			LDR_LIGHT(Read_Intensity);
			CONTROL_FAN_BY_TEMP(read_temp);
			display(read_temp,Read_Intensity);

		}


	}
	return 0 ;
}
void init_Hardware_drivers(void){
	LEDS_init();
	LCD_init();
	ADC_init();
	Buzzer_init();
	FlameSensor_init();
	DcMotor_Init();
}
void display(uint8 TEMP , uint8 LIGHT){
	LCD_Display_String_ROW_COL(0,0,"   ");
	LCD_Display_String_ROW_COL(0,14," ");
	LCD_Display_String_ROW_COL(1,0,"TEMP=");
	LCD_Display_String_ROW_COL(1,8,"LDR=");
	LCD_MOVE_Cursor(1,15);
	LCD_displayCharacter('%');
	LCD_MOVE_Cursor(1,5);
	LCD_Intger_TO_String(TEMP);
	LCD_MOVE_Cursor(1,12);
	LCD_Intger_TO_String(LIGHT);

}
void CONTROL_FAN_BY_TEMP(uint8 value_temp){
	if( read_temp >=100){
		LCD_MOVE_Cursor(1,5);
		LCD_Intger_TO_String(read_temp);
	}
	else{
		LCD_MOVE_Cursor(1,5);
		LCD_Intger_TO_String(read_temp);
		LCD_displayCharacter(' ');
	}
	if((value_temp >=25)&&(value_temp <30)){
		LCD_Display_String_ROW_COL(0,3,"FAN IS ON");
		LCD_displayCharacter(' ');
		DcMotor_Rotate(A_CW ,25);
	}
	else if((value_temp >=30)&&(value_temp <35)){
		LCD_Display_String_ROW_COL(0,3,"FAN IS ON");
		LCD_displayCharacter(' ');
		DcMotor_Rotate(A_CW ,50);
	}
	else if((value_temp >=35)&&(value_temp <40)){
		LCD_Display_String_ROW_COL(0,3,"FAN IS ON");
		LCD_displayCharacter(' ');
		DcMotor_Rotate(A_CW ,75);
	}
	else if((value_temp >=40)){
		LCD_Display_String_ROW_COL(0,3,"FAN IS ON");
		LCD_displayCharacter(' ');
		DcMotor_Rotate(A_CW ,100);
	}
	else if(value_temp<25){
		LCD_Display_String_ROW_COL(0,3,"FAN IS OFF");
		LCD_displayCharacter(' ');
		DcMotor_Rotate(A_CW ,0);
	}
}


void LDR_LIGHT(uint8 value){
	if( Read_Intensity >=100){
		LCD_MOVE_Cursor(1,12);
		LCD_Intger_TO_String(Read_Intensity);
	}
	else{
		LCD_MOVE_Cursor(1,12);
		LCD_Intger_TO_String(Read_Intensity);
		LCD_displayCharacter(' ');
	}
	if(Read_Intensity < 15){
		
		LED_on(led_red);
		LED_on(led_green);
		LED_on(led_blue);

	}
	else if((Read_Intensity >= 16) && (Read_Intensity <= 50)){
		LED_on(led_red);
		LED_on(led_green);
		LED_off(led_blue);
	}
	else if((Read_Intensity >=51) && (Read_Intensity <= 70)){
		LED_on(led_red);
		LED_off(led_green);
		LED_off(led_blue);
	}else if (Read_Intensity >70){
		LED_off(led_red);
		LED_off(led_green);
		LED_off(led_blue);
	}
}

