#include "WString.h"
#include "Arduino.h"
#include "cartao_sd.h"
#include <SD.h>
#include <SPI.h>



int pinoSS = 53; // Pin 53 para Mega / Pin 10 para UNO

bool inicializarSD(){
  pinMode(pinoSS, OUTPUT); // Declara pinoSS como saída
  return SD.begin(); // Inicializa o SD Card
}

int numberOfFiles(){
  int fileCountOnSD = 0;
  File root;
  root = SD.open("/");

  while (true) {

    File entry =  root.openNextFile();

    if (! entry) {
      // no more files
      break;
    }

     // for each file count it
    fileCountOnSD++;

    entry.close();

  }

  return fileCountOnSD;
}

void criarArquivo(String nome){
    File myFile;
    myFile = SD.open(nome, FILE_WRITE);
    myFile.print("Tensao"); // Escreve no Arquivo
    myFile.print(","); // Escreve no Arquivo
    myFile.print("Corrente"); // Escreve no Arquivo
    myFile.print("\n");
    myFile.close(); // Fecha o Arquivo após escrever
}

void gravarNoArquivo(String nome, String tensao, String corrente){
  File myFile;

  myFile = SD.open(nome, FILE_WRITE);

  
  if (myFile) { // Se o Arquivo abrir imprime:
    myFile.print(tensao); // Escreve no Arquivo
    myFile.print(","); // Escreve no Arquivo
    myFile.print(corrente);
    myFile.print("\n"); 
    myFile.close(); // Fecha o Arquivo após escrever
  }
}