// Exibe um número em decimal e binário no monitor serial e nos LEDs exibe o número na forma binária (até 4 bits) 

void setup() {
  // define o baudrate em 9600
  Serial.begin(9600);

  for (int i=2; i<6; i++){
    // seleciona os pinos 
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // lê Mensagens do monitor serial
  int numero = Serial.parseInt();

  // exibe o número em decimal no monitor serial
  Serial.println(numero);
  
  // exibe o número em binário no monitor serial
  Serial.println(numero,BIN);

  for (int i=0; i<4; i++){
    // o bitRead retorna o bit selecionado do numero da direita para a esquerda
    int acender = bitRead(numero, i);

    // os pinos selecionados enviam um sinal para acender o led
    digitalWrite(i+2, acender);
  }

  // espera 2 segundos
  delay(2000);
}
