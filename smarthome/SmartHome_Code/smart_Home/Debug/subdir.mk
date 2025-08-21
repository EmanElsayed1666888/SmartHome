################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../Application.c \
../Buzzer.c \
../Flame_sensor.c \
../LCD_driver.c \
../LDR.c \
../LED.c \
../MOTOR.c \
../PWM.c \
../gpio.c \
../lm35_sensor.c 

OBJS += \
./ADC.o \
./Application.o \
./Buzzer.o \
./Flame_sensor.o \
./LCD_driver.o \
./LDR.o \
./LED.o \
./MOTOR.o \
./PWM.o \
./gpio.o \
./lm35_sensor.o 

C_DEPS += \
./ADC.d \
./Application.d \
./Buzzer.d \
./Flame_sensor.d \
./LCD_driver.d \
./LDR.d \
./LED.d \
./MOTOR.d \
./PWM.d \
./gpio.d \
./lm35_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


