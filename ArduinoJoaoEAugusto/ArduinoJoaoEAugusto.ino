//Augusto Z. Vitali e João Victor Benedet Machado - 1190

const int SNA_button = 4;  // declara os pinos de acordo com as entradas do arduino
const int SNB_button = 3;  
const int STP_button = 2;  

const int ERRO_led = 5;
const int IR_led = 10;  
const int BP_led = 9;  
const int BR_led = 8;  

void setup() { // configura os pinos como entrada ou saida
  pinMode(SNA_button, INPUT);
  pinMode(SNB_button, INPUT);
  pinMode(STP_button, INPUT);
  pinMode(IR_led, OUTPUT);
  pinMode(BP_led, OUTPUT);
  pinMode(BR_led, OUTPUT);
  pinMode(ERRO_led, OUTPUT);
}

void loop() {
  bool SNA_sensor = digitalRead(SNA_button); //Le os sensores do botoes
  bool SNB_sensor = digitalRead(SNB_button);
  bool STP_sensor = digitalRead(STP_button);

  if (SNA_sensor == 1 && SNB_sensor == 1) { //se ambos sensores estiverem ligado, tudo certo, tudo desliga
    digitalWrite(IR_led, LOW);
    digitalWrite(ERRO_led, LOW);
    digitalWrite(BP_led, LOW);
    digitalWrite(BR_led, LOW);
  }
  if (SNA_sensor == 1 && SNB_sensor == 0) { // checa se ha erro, no caso nao tem como ter agua apenas no nivel alto do tanque, caso erro, desliga tudo
    digitalWrite(BP_led, LOW);
    digitalWrite(BR_led, LOW);
    digitalWrite(ERRO_led, HIGH);
    digitalWrite(IR_led, LOW);
  } else if (SNA_sensor == 0 && SNB_sensor == 0) { // se ambos estiverem desligados ele executa o restante do codigo
    if ((SNA_sensor == 0) && (SNB_sensor == 1 || SNB_sensor == 0)) { // se nao tiver agua no nivel acima, e no de baixo tanto faz o nivel, ele checa o seguinte:
      digitalWrite(ERRO_led, LOW);
      if (STP_sensor == 1) { // se tiver agua na bomba principal, ele aciona a bomba reserva
        digitalWrite(BP_led, HIGH);
        digitalWrite(BR_led, LOW);
        digitalWrite(ERRO_led, LOW);
        digitalWrite(IR_led, LOW);
      } else { // caso desligado, ele liga o indicador de bomba e a bomba reserva
        digitalWrite(BP_led, LOW);
        digitalWrite(BR_led, HIGH);
        digitalWrite(IR_led, HIGH);
        digitalWrite(ERRO_led, LOW);
      }
    }
  }
}
