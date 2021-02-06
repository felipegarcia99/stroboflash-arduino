#include <math.h>
#include <SevSeg.h>

//DISPLAY
SevSeg display7seg;
char text_string[10];

//POTENCIÔMETRO
const int pinoPot = A5;
int leituraA5;

//LED
int ledPin = 0;
int delay_micro;

void setup() {
  //Selecao tipo de display cátodo comum
  int displayType = COMMON_CATHODE;   
    
  //Definicao dos pinos dos digitos
  int digit1 = 10; //Pino Digito1 do display
  int digit2 = 11; //Pino Digito2 do display
  int digit3 = 12; //Pino Digito3 do display
  int digit4 = 13; //Pino Digito4 do display
 
  //Pinos ligados aos segmentos A - H
  int segA = 2; //Pino segmento A  
  int segB = 3; //Pino segmento B
  int segC = 4; //Pino segmento C
  int segD = 5; //Pino segmento D
  int segE = 6; //Pino segmento E
  int segF = 7; //Pino segmento F
  int segG = 8; //Pino segmento G
  int segDP= 9; //Pino segmento H
  
  //Define o numero de digitos do display
  int numberOfDigits = 4;
 
  //Inicializa o display
  display7seg.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);
  
  //Nivel de brilho do display
  display7seg.SetBrightness(50);
  
  pinMode(pinoPot, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  leituraA5 = analogRead(pinoPot);

  delay_micro = round(((7950/491)*leituraA5)+100);
  
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(delay_micro);
  digitalWrite(ledPin, LOW);
  delayMicroseconds(delay_micro);

  sprintf(text_string, "%04d", delay_micro);

  if(delay_micro >= 10000)
  {
    display7seg.DisplayString(text_string, 2);
  }
  else
  {
    display7seg.DisplayString(text_string, 1);
  }
  
}
