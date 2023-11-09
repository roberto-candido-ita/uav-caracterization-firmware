#include "WString.h"
#ifndef CARTAO_SD_H
#define CARTAO_SD_H
#include <Arduino.h>
#include <SD.h>
#include <SPI.h>

void criarArquivo(String nome);
bool inicializarSD();
void gravarNoArquivo(String nome, String tensao, String corrente);
int numberOfFiles();

#endif