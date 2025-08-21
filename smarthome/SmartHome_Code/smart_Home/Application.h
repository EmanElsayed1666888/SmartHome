/*
 * Application.h
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed
 */

#ifndef APPLICATION_H_
#define APPLICATION_H_
#include"std_types.h"
void init_functions_drivers(void)
void display(uint8 TEMP , uint8 LIGHT);
void CONTROL_FAN_BY_TEMP(uint8 value_temp);
void LDR_LIGHT(uint8 value);

#endif /* APPLICATION_H_ */
