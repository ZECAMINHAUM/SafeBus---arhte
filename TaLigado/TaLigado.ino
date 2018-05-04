#include <SoftwareSerial.h>

const int buttonPin = 2;
int buttonState = 0;

SoftwareSerial SIM900(7, 8); // Configura a porta serial do SIM900
 
char incoming_char=0; //Variavel que guarda os caracteres que envia ao SIM900

void setup(){
  pinMode(buttonPin, INPUT);
  SIM900.begin(19200); // SIM900
  delay(25000); //Retardo para que encuentra a una RED
  Serial.begin(19200); //Configura a velocidade serial para o Arduino
  Serial.println("OK"); //Mensaje OK en el arduino, para saber que todo va bien.
}

void loop(){
  // faz a leitura do valor do botao:
  buttonState = digitalRead(buttonPin);

  // verifica se o botao esta pressionado.
  // em caso positivo, buttonState e HIGH:
  if (buttonState == HIGH) {    
    mensagem_sms();
    delay(15000);  
    mensagem_sms();
    delay(15000);  
    mensagem_sms();
  }
}

void mensagem_sms(){
 
  SIM900.print("AT+CMGF=1\r"); // AT command to send SMS message
  delay(100);
  SIM900.println("AT+CMGS=\"+5517992462107\""); // recipient's mobile number, in international format
  delay(100);
  SIM900.println("Aviso de roubo do carro numero ***-****, coordenadas: **.******* e **.*******"); // message to send
  delay(100);
  SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26 //Comando de finalizacion
  delay(100);
  SIM900.println();
  delay(5000); // Tiempo para que se envie el mensaje
  Serial.println("SMS sent successfully");
}
