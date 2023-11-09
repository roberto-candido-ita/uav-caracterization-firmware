#ifndef SENSOR_TENSAO_H
#define SENSOR_TENSAO_H
#include <Arduino.h>

float lerTensao(int pino);
bool inicializarSensorTensao(int pino);

#endif