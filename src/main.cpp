#include <Arduino.h>
#include "DHT.h"
#include "Adafruit_Sensor.h"

#define DHTPIN 2 // Arduino pin connected to the sensor
#define DHTTYPE DHT11 //We're using DHT11 sensor

//Sensor inizialization
DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("Temperature and Humidity sensor test.");

  dht.begin();
}

void loop() {
  float temp;
  float hum;

  delay(5000); //Wait 5 seconds between 2 measurements

  temp = dht.readTemperature(); //read temperature (Celsius as default)
  hum = dht.readHumidity();

  if(isnan(temp)||isnan(hum)){
    Serial.println("ERROR: FAILED TO READ FROM SENSOR!!!");
    return;
  }
  Serial.println("--------------------------------------");
  Serial.print("Temperature: ");
  Serial.println(temp);
  Serial.print("Humidity: ");
  Serial.println(hum);
  Serial.println("--------------------------------------");
}