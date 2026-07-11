# 🏠 Project 4 – Edge Computing Smart Home Safety System

## Objective

To develop a smart home safety system using ESP32 that detects motion, monitors gas leakage, and performs immediate emergency actions using interrupt-driven edge computing.

## Components Used

- ESP32
- PIR Motion Sensor
- Potentiometer (Gas Sensor Simulation)
- Green LED
- Red LED
- Buzzer
- Wokwi Simulator

## Features

- Motion Detection using PIR Sensor
- Hardware Interrupt (ISR)
- Smart Lighting Control
- Gas Leak Monitoring
- Emergency Safety Override
- Buzzer Alarm
- Red Alert LED
- Edge Computing Decision Making
- Multi-Sensor Integration
- Wokwi Simulation

## Working

- PIR sensor detects motion and triggers an interrupt.
- ESP32 turns ON the green LED when motion is detected.
- The gas sensor continuously monitors gas levels.
- If gas exceeds the threshold, the system immediately enters Emergency Mode.
- The green LED turns OFF.
- The red LED flashes and the buzzer sounds.
- Emergency Mode overrides all normal operations to ensure safety.

## Software Used

- Arduino IDE
- Wokwi Simulator

## Author

Navyasri Korada

