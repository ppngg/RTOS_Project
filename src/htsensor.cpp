#include "htsensor.h"
#include <Arduino.h>
#include <Wire.h>

float currentTemperature = 0.0;
float currentHumidity = 0.0;

DHT20 dht20;
void HTSensor_Init(void) {
    Wire.begin(GPIO_NUM_11, GPIO_NUM_12);
    dht20.begin();
    Serial.println("DHT20 sensor initialized successfully!");
}

void HTSensor_Read(void) {
    // Read temperature and humidity
    int status = dht20.read();
    
    if (status == DHT20_OK) {
        currentTemperature = dht20.getTemperature();
        currentHumidity = dht20.getHumidity();
        
        // Print to Serial Monitor
        Serial.print("Temperature: ");
        Serial.print(currentTemperature);
        Serial.print("°C\t");
        Serial.print("Humidity: ");
        Serial.print(currentHumidity);
        Serial.println("%");
    } else {
        Serial.print("Error reading DHT20 sensor: ");
        Serial.println(status);
    }
}