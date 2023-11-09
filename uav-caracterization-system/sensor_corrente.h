#ifndef SENSOR_CORRENTE_H
#define SENSOR_CORRENTE_H
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_INA219.h>

float lerCorrente();
bool inicializarINA219();

#endif