#include "sensor_tensao.h"
#include "sensor_corrente.h"
#include "sensor_temperatura.h"
#include "cartao_sd.h"
#include <Wire.h>
#include <Adafruit_INA219.h>


const int pinoSensorTensao = A2; 

int fileNumber;
String nome;

void setup(){
   pinMode(pinoSensorTensao, INPUT); //DEFINE O PINO COMO ENTRADA
   pinMode(LED_BUILTIN, OUTPUT);
   Serial.begin(9600); //INICIALIZA A SERIAL
   inicializaSensores();

   fileNumber = numberOfFiles();
   nome = "Medida" + String(fileNumber);
   criarArquivo(nome);
}

void loop(){
  
  float correnteMedida = lerCorrente();
  float tensao = lerTensao(pinoSensorTensao);
    
  gravarNoArquivo(nome, String(tensao), String(correnteMedida));
  
  Serial.println("Corrente: " + String(correnteMedida));
  Serial.println("Tensão: " + String(tensao));
  delay(100);
  
}

void inicializaSensores(){

  if(!inicializarSD()) {
     Serial.println("Failed to find SD card chip");
     while (1) {
      digitalWrite(LED_BUILTIN, HIGH);
    
     }
   }

   if(!inicializarINA219()) {
      Serial.println("Failed to find INA219 chip");
      while (1) {
       digitalWrite(LED_BUILTIN, HIGH);
     }
   }
}






