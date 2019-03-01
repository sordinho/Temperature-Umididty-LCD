# Temperature-Umididty-LCD

## Overview
This is a simple project for measuring temperature and humidity with arduino and a digital sensor. We will write the results on al 16x2 lcd screen

## Needed Material
* Arduino UNO
* DHT11 Digital Temperature and Humidity sensor (I used the one with 3 pin and integrated 10k resistor)
* I2C LCD screen 16x2

## Pin Connection

Arduino | DHT11 | LCD
--------|-------|-----
5V | VCC/+| VCC
GND | GND/- | GND
2 |OUT/DATA
A4 | | SDA
A5 | | SCL


## Notes
* Created with [VSCode](https://code.visualstudio.com/) and [Platformio](https://platformio.org/)
* If you want only source code copy main.cpp in a .ino file
* Needed libraries:
  * [DHT.h](https://platformio.org/lib/show/19/DHT%20sensor%20library)
  * [LiquidCrystal_I2C.h](https://platformio.org/lib/show/576/LiquidCrystal_I2C)
  * [Adafruit_Sensor.h](https://platformio.org/lib/show/31/Adafruit%20Unified%20Sensor/examples)
* DHT11 can also be connected to 3.3V instead of 5V
* If not integrated, you need a 10k resistor for the DHT11 