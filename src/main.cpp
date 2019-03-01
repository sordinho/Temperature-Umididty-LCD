#include <Arduino.h>
#include "DHT.h"
#include "Adafruit_Sensor.h"
#include "LiquidCrystal_I2C.h"

#define DHTPIN 2 // Arduino pin connected to the sensor
#define DHTTYPE DHT11 //We're using DHT11 sensor

LiquidCrystal_I2C lcd(0x3F,16,2); // lcd(addr,col,row)
/*
If LCD i2c is PCF8574, address is 0x27
If LCD i2c is PCF8574A, address is 0x3F
*/

//Sensor inizialization
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature and Humidity sensor test.");

  lcd.init(); // initialize the lcd 
  lcd.backlight(); //enable lcd backlight

  lcd.print("Temp [C]: "); //initialize lcd writing
  lcd.setCursor(0,1); //setCursor(col,row)
  lcd.print("Umidit [%]: ");

  dht.begin(); //start reading from sensor
}

void loop() {
  float temp;
  float hum;

  delay(5000); //Wait 5 seconds between 2 measurements

  temp = dht.readTemperature(); //read temperature (Celsius as default)
  hum = dht.readHumidity(); //read humidity

  // check error while reading from sensor
  if(isnan(temp)||isnan(hum)){
    Serial.println("ERROR: FAILED TO READ FROM SENSOR!!!");
    return;
  }
  //print on LCD
  lcd.setCursor(10,0);
  lcd.print(temp,1); //1 decimal digit
  lcd.setCursor(12,1);
  lcd.print(hum,0); // no decimal digits
}