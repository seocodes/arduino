const int pinbotao = 2;
bool botao = false;
bool mensagem = false;

void setup() {
  pinMode(pinbotao, INPUT);
  Serial.begin(9600);
}

void loop() {
  botao = digitalRead(pinbotao);
  if (botao == true) {
    if (mensagem == false){
      Serial.println("Botão pressionado.");
      mensagem = true;
  }
}
  else{
    mensagem = false;
  }
}