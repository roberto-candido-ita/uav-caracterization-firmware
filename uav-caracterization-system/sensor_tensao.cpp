#include "sensor_tensao.h"
float tensao= 0; 

float lerTensao(int pino){
  float tensaoEntrada = 0.0; //VARIÁVEL PARA ARMAZENAR O VALOR DE TENSÃO DE ENTRADA DO SENSOR
  float tensaoMedida = 0.0; //VARIÁVEL PARA ARMAZENAR O VALOR DA TENSÃO MEDIDA PELO SENSOR

  float valorR1 = 30060.0; //VALOR DO RESISTOR 1 DO DIVISOR DE TENSÃO
  float valorR2 = 7500.0; // VALOR DO RESISTOR 2 DO DIVISOR DE TENSÃO
  long int leituraSensor = 0; //VARIÁVEL PARA ARMAZENAR A LEITURA DO PINO ANALÓGICO

   

   for (int i = 0; i < 30; i++){
      leituraSensor += analogRead(pino); //FAZ A LEITURA DO PINO ANALÓGICO E ARMAZENA NA VARIÁVEL O VALOR LIDO
   }

   leituraSensor = leituraSensor/30;

   tensaoEntrada = (leituraSensor * 5.038) / 1023.0; //VARIÁVEL RECEBE O RESULTADO DO CÁLCULO
   return (tensaoEntrada / (valorR2/(valorR1+valorR2))); //VARIÁVEL RECEBE O VALOR DE TENSÃO DC MEDIDA PELO SENSOR

}

bool inicializarSensorTensao(int pino){
  for (int i = 0; i < 5; i++) {
    tensao += (analogRead(pino));
  }
  tensao = tensao/5;

  if(tensao == 0)
    return false;

  return true;
}