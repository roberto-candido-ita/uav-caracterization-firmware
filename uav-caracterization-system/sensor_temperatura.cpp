#include "sensor_temperatura.h"

 //PINO ANALÓGICO UTILIZADO PELO SENSOR
float temperatura = 0; //VARIÁVEL DO TIPO FLOAT
               

 float lerTemperatura(int sensorPin){
  for (int i = 0; i < 30; i++) {
    temperatura += (analogRead(sensorPin));
  }
  temperatura = temperatura/30;
  
  return temperatura * 0.0048828125 * 100;

}

bool inicializarSensorTemperatura(int sensorPin){
  for (int i = 0; i < 5; i++) {
    temperatura += (analogRead(sensorPin));
  }
  temperatura = temperatura/5;

  if(temperatura == 0)
    return false;

  return true;
}