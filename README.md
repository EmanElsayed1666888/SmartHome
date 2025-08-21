# SmartHome
Smart Home Automation System (ATmega32 Project)
📌 Project Overview

The Smart Home Automation System is built on the ATmega32 microcontroller and integrates multiple sensors and actuators to automate home functionalities. The system dynamically adjusts lighting and fan speed based on environmental conditions, while also providing fire detection and safety alerts.

The project showcases the integration of sensors, actuators, LCD interface, and PWM motor control using C programming and a layered driver architecture.

✨ Features

Automatic Lighting Control

Controlled by an LDR sensor and displayed via LEDs.

Light intensity thresholds:

< 15% → All LEDs ON (Red, Green, Blue).

16–50% → Red + Green LEDs ON.

51–70% → Red LED ON only.

> 70% → All LEDs OFF.

Temperature-Based Fan Control

LM35 sensor measures temperature.

Fan speed controlled via PWM:

≥ 40°C → 100% speed.

35–39°C → 75% speed.

30–34°C → 50% speed.

25–29°C → 25% speed.

< 25°C → Fan OFF.

Fire Detection & Alert

Flame sensor detects fire and activates a buzzer.

LCD displays “Critical alert!” until fire is cleared.

Real-Time LCD Display

First Row: Fan status (“FAN is ON” / “FAN is OFF”).

Second Row: Temperature (°C) and light intensity (%).

🛠️ Hardware Components

Microcontroller: ATmega32 (16 MHz)

Sensors:

LM35 Temperature Sensor (ADC Channel 1)

LDR Light Sensor (ADC Channel 0)

Flame Sensor (Digital Input PD2)

Actuators:

DC Motor with H-Bridge Driver (Fan Control)

Buzzer (PD3)

LEDs (Red – PB5, Green – PB6, Blue – PB7)

Display: 16x2 LCD (8-bit mode, PORTC data lines, RS=PD0, E=PD1)

📂 Software Architecture

Drivers Implemented:

GPIO Driver

ADC Driver (for LM35 & LDR)

PWM Driver (for fan motor speed)

LCD Driver (8-bit mode)

DC Motor Driver

Flame Sensor Driver
⚡ System Operation

Lighting Control: Adjusts LEDs based on LDR readings.

Fan Control: PWM regulates fan speed according to LM35 temperature values.

Fire Safety: Flame sensor triggers buzzer and LCD “Critical alert.”

Status Display: LCD continuously shows temperature, fan state, and light intensity.
Buzzer Driver

LED Driver
