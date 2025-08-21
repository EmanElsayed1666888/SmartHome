/*
 * MOTOR.h
 *
 *  Created on: Jun 20, 2025
 *      Author: Eman Sayed 
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "std_types.h"
typedef enum
{
	STOP ,CW ,A_CW
}DcMotor_State;
void DcMotor_Init(void);
void DcMotor_Rotate(DcMotor_State state, uint8 speed);

#endif /* MOTOR_H_ */
