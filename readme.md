# IoT-Based Health Monitoring System Using ESP32

## Project Overview

This project is a Health Monitoring System developed using ESP32. It monitors body temperature using a DHT22 sensor and simulates heart rate and SpO₂ (blood oxygen level) values. The measured data is displayed on a 16x2 LCD, and a buzzer provides alerts when abnormal health conditions are detected.

## Features

* Real-time temperature monitoring
* Simulated heart rate monitoring
* Simulated SpO₂ monitoring
* LCD display for health parameters
* Buzzer alert for abnormal conditions
* Serial Monitor output for data logging
* ESP32-based IoT implementation

## Components Used

* ESP32 DevKit V1
* DHT22 Temperature Sensor
* 16x2 LCD Display (I2C)
* Buzzer
* Jumper Wires
* Breadboard (for hardware implementation)

## Circuit Connections

### DHT22 Sensor

| DHT22 Pin | ESP32 Pin |
| --------- | --------- |
| VCC       | 3.3V      |
| GND       | GND       |
| DATA      | GPIO 4    |

### LCD 16x2 (I2C)

| LCD Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 5V        |
| GND     | GND       |
| SDA     | GPIO 21   |
| SCL     | GPIO 22   |

### Buzzer

| Buzzer Pin   | ESP32 Pin |
| ------------ | --------- |
| Positive (+) | GPIO 15   |
| Negative (-) | GND       |

## Working Principle

1. The DHT22 sensor measures the ambient temperature.
2. Heart rate and SpO₂ values are simulated in software since the MAX30102 sensor is not available in Wokwi.
3. ESP32 processes the sensor data and updates the LCD display.
4. Health parameters are also printed on the Serial Monitor.
5. If any parameter exceeds the predefined threshold, the buzzer is activated to indicate an alert condition.

## Alert Conditions

* Heart Rate > 100 BPM
* SpO₂ < 95%
* Temperature > 37.5°C

## Sample Output

### Normal Condition

Heart Rate: 78 BPM
SpO₂: 98%
Temperature: 36.8°C
Status: OK

### Alert Condition

Heart Rate: 110 BPM
SpO₂: 92%
Temperature: 38.2°C
Status: ALERT

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* DHT Sensor Library
* LiquidCrystal I2C Library
* Wokwi Simulator

## Simulation

The project is simulated using Wokwi with the following components:

* ESP32 DevKit
* DHT22 Sensor
* LCD 16x2 I2C
* Buzzer

## Limitations

The MAX30102 pulse oximeter sensor is not currently supported in Wokwi. Therefore, heart rate and SpO₂ values are generated using software simulation for demonstration purposes.

## Future Enhancements

* Integration of MAX30102 sensor on real hardware
* Wi-Fi-based remote monitoring
* Cloud data storage
* Mobile application support
* Emergency notification system

## Author

**Monitha**


