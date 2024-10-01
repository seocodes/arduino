//AUGUSTO Z. VITALI E PEDRO HENRIQUE NASCIMENTO URBANO -- 2190

const int ledEsteira = 13;
int pecasGrandes = 0;   //Contagem das peças
int pecasPequenas = 0;  //Contagem das peças
#include <Servo.h>      //Adicionando biblioteca Servo para simular o o componente que empurra as peças
Servo myservo;
#include <Ultrasonic.h>  //Adicionando a biblioteca ultrasonic para medir o tamanho das peças
Ultrasonic ultrasonic(5, 6);
int tamanho;
const int altura = 45;             //Altura máxima
const int interruptPin_botao = 2;  //Botão de emergência

void setup() {
  Serial.begin(9600);                         //Inicia a serial
  myservo.attach(8);                          //Pino do servo
  pinMode(interruptPin_botao, INPUT_PULLUP);  //Define o botao com input
  pinMode(ledEsteira, OUTPUT);                //Define o led como output
}

void loop() {
  bool but = !digitalRead(interruptPin_botao);  //Lê o botão
  tamanho = ultrasonic.read();                  //Lê o ultrasonic

  if (but == HIGH) {
    myservo.write(0);               //Mantem o servo no grau zero
    pecasGrandes = 0;               //Zera a contagem de peças
    pecasPequenas = 0;              //Zera a contagem de peças
    digitalWrite(ledEsteira, LOW);  //Se apertado, desliga o led

  } else {
    digitalWrite(ledEsteira, HIGH);                           //Caso botão não pressionado, deixa o led ligado
    if (tamanho < 45) {                                       //Se o tamanho medido for menor que 45, quer dizer que há uma peça, e começam os IFs
      myservo.write(90);                                      //Coloca o servo a 90 graus pois há peças/servo empurra a peça
      if (altura - tamanho >= 30 && altura - tamanho < 45) {  //Se for maior igual a 30 e menor que 40, conta como peça pequena (1cm a 15cm)
        pecasPequenas++;                                      //Adiciona uma peça pequena
        myservo.write(120);                                   //Muda o ângulo do servo para 120 graus, pois é o requerido para peças pequenas
      }
      if (altura - tamanho <= 29 && altura - tamanho >= 15) {  //Se altura menor igual a 29 e maior igual a 15, conta como peça grande
        pecasGrandes++;                                        //Adiciona uma peça grande à contagem
        myservo.write(60);                                     //Muda o angulo para 60 graus pois é o requerido para peças grandes
      }
    } else if (tamanho >= 45) {  //Caso seja maior ou igual a 45, indica que não há nada
      myservo.write(0);          //Zera a angulação, modo descanso, uma vez que não há peça para ser empurrada
    }

    Serial.print("Tamanho/altura da peça: ");
    Serial.println(tamanho);  //Printa o tamanho, para verificar se a contagem está correta
    Serial.print("Peças pequenas: ");
    Serial.println(pecasPequenas);  //Printa a contagem de peças pequenas
    Serial.print("Peças grandes: ");
    Serial.println(pecasGrandes);  //Printa a contagem de peças grandes
  }
}
