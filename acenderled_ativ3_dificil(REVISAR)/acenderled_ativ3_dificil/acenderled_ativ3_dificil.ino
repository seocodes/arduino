const int pinup = 3; 
const int pindown = 2;
const int pinled1 = 4;
const int pinled2 = 5;
bool but0 = false;
bool but1 = false;
bool estado = 0;
unsigned long tempoAnt = 0;

void setup() {
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinup, INPUT);
  pinMode(pindown, INPUT);
}

void loop() {
  but0 = digitalRead(pinup);
  but1 = digitalRead(pindown);
  if (but0 == 1){
    digitalWrite(pinled1, 1);       
    if (estado == 0){
      tempoAnt = millis(); }   // começa a contar o tempo anterior quando o botão é pressionado, e logo depois já deixa de contar pois o estado vira 1
                                //por isso a conta (tempAtual - tmepAnt) dá certo. Se não tivesse esse if, o tempoAnt iria contar enquanto o botão tivesse pressionado (but0 = 1)
    estado = 1;                       //estado vira 1 para indicar que o botão FOI PRESSIONADO.
                       //a variável ESTADO é necessário pois o codigo n consegue entender que o botao foi apertado antes sem uma variavel auxiliar, lembre-se que o tempoAnt só conta IF butt0 = 1
  }
  if (estado == 1){                     //o segundo LED irá acender após entender que o botão ja foi pressionado (não precisando deixar o but0 pressionado)
    unsigned long tempoAtual = millis();      //não da pra ser if (but0 == 1) pois não iria nem ligar (teria que deixar apertado)
    if (tempoAtual - tempoAnt >= 1000){
      digitalWrite(pinled2, 1);
    }
  }
  if (but1 == 1){
    digitalWrite(pinled1, 0);
    digitalWrite(pinled2, 0);
    estado = 0;                      //estado vira 0 para indicar
  }

}
