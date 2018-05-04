/*
  Botao
 
 Liga e desliga um LED conectado ao pino digital 13 quando pressionado um botao conectado ao pino 2.
 
 O Circuito:
 * LED conectado ao pino 13 e ao terra
 * botao conectado ao pino 2 desde 5V
 * resistor de 10K conectado ao pino 2 desde o terra
*/

// constantes nao sao alteradas. 
// Sao usadas aqui para definir os numeros dos pinos:
const int buttonPin = 2;     // o numero do pino do botão
const int ledPin =  13;      // o numero do pino do LED

// variaveis que devem mudar:
int buttonState = 0;         // variavel para ler o estado do botao

void setup() {
  // inicializa o pino do LED como saida:
  pinMode(ledPin, OUTPUT);      
  // inicializa o pino do botao como entrada:
  pinMode(buttonPin, INPUT);    
}

void loop(){
  // faz a leitura do valor do botao:
  buttonState = digitalRead(buttonPin);

  // verifica se o botao esta pressionado.
  // em caso positivo, buttonState e HIGH:
  if (buttonState == HIGH) {    
    // liga o LED:    
    digitalWrite(ledPin, HIGH);  
  }
  else {
    // desliga o LED:
    digitalWrite(ledPin, LOW);
  }
}
