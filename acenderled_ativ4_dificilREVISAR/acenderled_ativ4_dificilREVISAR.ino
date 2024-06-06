const int pinup = 3; 
const int pindown = 2;
const int pinled1 = 4;
const int pinled2 = 5;
const int pinled3 = 6;
const int pinled4 = 7;
bool but0 = false;
bool but1 = false;
int estado = 0;
unsigned long tempoAnt = 0;

void setup() {
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
  pinMode(pinled4, OUTPUT);
  pinMode(pinup, INPUT);
  pinMode(pindown, INPUT);
}

void loop() {
  but0 = digitalRead(pinup);
  but1 = digitalRead(pindown);
  if (but0 == 1){
    if (estado == 0){
      tempoAnt = millis();       //tenta se lembrar da lógica disso tb
    }
    estado = 1;
  }
  unsigned long tempoAtual = millis();            //depois explicar pq declarei o tempoAtual aqui, pq reseta o tempoAnt a cada case, e pq 
                                                  // o if pra ir pro 0 está fora do switch, TENTA RESOLVER O PROBLEMA DO ZERO DNV, N FICA SO OLHANDO
  switch(estado){
    case 0:
    digitalWrite(pinled1, 0);
    digitalWrite(pinled2, 0);
    digitalWrite(pinled3, 0);
    digitalWrite(pinled4, 0);
    break;

    case 1:
    digitalWrite(pinled1, 1);
    if (tempoAtual - tempoAnt >= 1000){
      tempoAnt = millis();
      estado = 2;
    }
    break;

    case 2:
      digitalWrite(pinled2, 1);
      if (tempoAtual - tempoAnt >= 500){
        tempoAnt = millis();
        estado = 3;
      }
      break;

    case 3:
    digitalWrite(pinled3, 1);
      if (tempoAtual - tempoAnt >= 250){
        tempoAnt = millis();
        estado = 4;
      }
      break;
    
    case 4:
    digitalWrite(pinled4, 1);
      if (tempoAtual - tempoAnt >= 500){
        tempoAnt = millis();
        estado = 5;
      }
      break;

    case 5:
    digitalWrite(pinled1, 0);
    digitalWrite(pinled2, 0);
    digitalWrite(pinled3, 0);
    digitalWrite(pinled4, 0);
    if (tempoAtual - tempoAnt >= 1000){
      tempoAnt = millis();
      estado = 1;
    }
  }
  if (but1 == 1){
    estado = 0; }
}
