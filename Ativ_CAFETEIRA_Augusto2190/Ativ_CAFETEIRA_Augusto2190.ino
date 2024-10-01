//AUGUSTO Z. VITALI - 2190
#include <Ultrasonic.h>  //Declaração de bibliotecas
#include "DHT.h"

#define DHTPIN 5       //Declara o pino do dht
#define DHTTYPE DHT11  //Declaro o tipo do dht
DHT sensorTemp(DHTPIN, DHTTYPE);
Ultrasonic sensorCopo(2, 3);  //Declara os pinos do ultrasonic

float temperatura;
const int ledAquecimento = 8;
const int ledCafeDespejando = 9;  //Declaração de variáveis
const int ledSonoro = 10;
const int but = 13;
unsigned long tempoAnt;
int presencaCopo;
int estado = 0;

void setup() {
  pinMode(ledAquecimento, OUTPUT);  //Define o modo dos pinos
  pinMode(ledSonoro, OUTPUT);
  pinMode(ledCafeDespejando, OUTPUT);
  pinMode(but, INPUT_PULLUP);
  sensorTemp.begin();  //Começa o sensor de temperatura (dht)
  Serial.begin(9600);  //Inicia a serial
}

void loop() {
  bool botaoIniciar = !digitalRead(but);       //Lê o botão
  presencaCopo = sensorCopo.read();            //Lê o ultrasonic
  temperatura = sensorTemp.readTemperature();  //Lê o DHT
  Serial.println(temperatura);
  Serial.println(presencaCopo);
  switch (estado) {  //FINITE STATE MACHINE
    case 0:
      digitalWrite(ledSonoro, LOW);
      if (botaoIniciar == HIGH) {  //Se apertado, estado vira 1
        estado = 1;
      }
      break;
    case 1:
      digitalWrite(ledAquecimento, HIGH);  //Liga o aquecimento
      if (temperatura >= 26) {             //Caso a temperatura fique maior que 26
      digitalWrite(ledAquecimento, LOW);  //Desliga o aquecimento
      tempoAnt = millis();                //Começa a contar o tempoAnt e já para pois o case não vai mais ser verdade (estado vira 3)
      estado = 2;
      }
      break;
    case 2:
      if (presencaCopo <= 10) {
        digitalWrite(ledCafeDespejando, HIGH);
        unsigned long tempoAtual = millis();   //Atribui uma variável para o tempo contado
        if (tempoAtual - tempoAnt >= 10000) {  //Após 10 segundos/100000 ms, desliga o despejador de café
          digitalWrite(ledCafeDespejando, LOW);
          estado = 3;
        }
      }
      else{
        digitalWrite(ledCafeDespejando, LOW);
      }
      break;
    case 3:
      digitalWrite(ledSonoro, HIGH);  //Liga o led sonoro para avisar que o café foi servido
      estado = 0;                     //Estado vira 0 para conseguir utilizar a cafeteira novamente
      break;
    default:  //Caso ocorra algum erro, reinicia a cafeteira, ou seja, estado = 0
      Serial.println("Erro.");
      estado = 0;
  }
}
