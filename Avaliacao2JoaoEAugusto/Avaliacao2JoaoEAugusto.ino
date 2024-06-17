//Augusto Z. Vitali e João Victor Benedet Machado - 1190

// Buttons
const int Lh_button = 5; // declarei os pinos do arduino correspondente aos led e botoes
const int Ll_button = 4;
const int Th_button = 3;
const int Tc_button = 2;
// Led
const int V_entrada = 11;
const int V_saida = 10;
const int Aquecedor = 9;
const int Alarme = 8;

void setup() { //declaramos o que é entrada e saida dos pinos
  pinMode(Lh_button, INPUT);
  pinMode(Ll_button, INPUT);
  pinMode(Th_button, INPUT);
  pinMode(Tc_button, INPUT);
  pinMode(V_entrada, OUTPUT);
  pinMode(V_saida, OUTPUT);
  pinMode(Aquecedor, OUTPUT);
  pinMode(Alarme, OUTPUT);
}

void loop() {
  bool Lh_sensor = digitalRead(Lh_button);  // A 
  bool Ll_sensor = digitalRead(Ll_button);  // B
  bool Th_sensor = digitalRead(Th_button);  // C
  bool Tc_sensor = digitalRead(Tc_button);  // D
  // isso a cima tem a funcao de ler as atividades dos botoes

  // atraves da simplificação com o mapa de karnough, que é feito a partir da tabela verdade
  if (!Lh_sensor * !Tc_sensor + !Lh_sensor * !Th_sensor) { // A`.D` + A`.D` 
    digitalWrite(V_entrada, HIGH);
  } else {
    digitalWrite(V_entrada, LOW);
  }
  if (Ll_sensor * !Th_sensor * !Tc_sensor) { // B.C`.D`
    digitalWrite(V_saida, HIGH);
  } else {
    digitalWrite(V_saida, LOW);
  }
  if (!Th_sensor * Tc_sensor) { // C`.D
    digitalWrite(Aquecedor, HIGH);
  } else {
    digitalWrite(Aquecedor, LOW);
  }
  if (!Lh_sensor*Th_sensor + Lh_sensor*Th_sensor + Lh_sensor*!Ll_sensor) { // A`.C + A.C + A.B`
    digitalWrite(Alarme, HIGH);
  } else { // caso operacao falsa, ele faz desliga o led, funciona em todos os outros else's
    digitalWrite(Alarme, LOW);
  }
}
