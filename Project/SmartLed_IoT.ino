/*************************************************************
  Download desse projeto no GitHub
https://github.com/gabrielkenji12/Projeto_SmartLamp

Biblioteca utilizada BLynk- IFTTT

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

*/
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//Define o LDR
const int LDRPin = A0;  
//define o pino do LED
#define ledPin D1 
//define a variavel para do LDR
int sensorValue = 0; 
//define um contador
int count=0; 
// Utilize Api Key gerada pelo blynk.
char auth[] = "54fdc59952b541b286382a20289fd95a";

// Insira seu Wifi.
char ssid[] = "iPhone";
// Coloque a senha do Wifi
char pass[] = "nawf1997";

void setup()
{
  // Debugg do console
  //debugging  serial communcation
  Serial.begin(9600);  
  pinMode( ledPin, OUTPUT ); 
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  
  Blynk.run();
  //Ler o valor do LDR
  sensorValue=analogRead(A0); 
  // Valor do LDR para o Monitor 
  Serial.println(sensorValue);  
  Blynk.virtualWrite(ledPin,HIGH);
  if(sensorValue<100){
    if(count==0){
      Blynk.notify("Está escuro"); 
      count = 1;
    }
  } else {         
      count = 0;                                           
  }
    
   
}

