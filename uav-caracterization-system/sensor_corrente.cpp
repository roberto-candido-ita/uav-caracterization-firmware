#include "Arduino.h"
#include "sensor_corrente.h"
#include <Wire.h>
#include <Adafruit_INA219.h>



uint32_t currentFrequency;
Adafruit_INA219 ina219;


//Adafruit_INA219 ina219_B(0x41);
//Adafruit_INA219 ina219_C(0x44);

float lerCorrente()
{
  
  float current_mA = 0;

    for (int i = 0; i < 30; i++) {
        current_mA += ina219.getCurrent_mA();
        delayMicroseconds(10);
    }

    return current_mA/30;
    
}

bool inicializarINA219(){
  return ina219.begin();
}