#include <Arduino.h>
#include "DHT.h"
#include "Adafruit_Sensor.h"
#include "LiquidCrystal_I2C.h"
#include "Wire.h"

#define DHTPIN 2 // Arduino pin connected to the sensor
#define DHTTYPE DHT11 //We're using DHT11 sensor

LiquidCrystal_I2C lcd(0x3F,16,2); //set LCD address

//Sensor inizialization
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature and Humidity sensor test.");

  lcd.init(); // initialize the lcd 
  lcd.backlight();

  lcd.print("Temp [C]: ");
  lcd.setCursor(0,1);
  lcd.print("Umidit [%]: ");

  dht.begin();
}

void loop() {
  float temp;
  float hum;

  delay(5000); //Wait 5 seconds between 2 measurements

  temp = dht.readTemperature(); //read temperature (Celsius as default)
  hum = dht.readHumidity(); //read humidity

  if(isnan(temp)||isnan(hum)){
    Serial.println("ERROR: FAILED TO READ FROM SENSOR!!!");
    return;
  }
  lcd.setCursor(10,0);
  lcd.print(temp,1);
  lcd.setCursor(12,1);
  lcd.print(hum,0);
}