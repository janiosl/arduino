int pinLed = 13;
int pinLed_green = 7;
int pinSensor = 0;
int leituraSensor;

void setup() {
  pinMode(pinLed, OUTPUT);
  pinMode(pinLed_green, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  //Função lê o sensor de humidade
  leituraSensor = analogRead(pinSensor);
  delay(1000);

  /*Se o valor for menor que 800, significa que está
  faltando água. O led de alerta é ligado e a mensagem
  exibida no monitor*/
  if (leituraSensor < 250) {
    digitalWrite(pinLed_green, LOW);
    digitalWrite(pinLed, HIGH);
    Serial.println("Me alimente!");
    Serial.println(leituraSensor);
    }
  /*Caso contrário o led é desligado e plana agradece*/
  else {
    digitalWrite(pinLed, LOW);
    digitalWrite(pinLed_green, HIGH);
    Serial.println("Obrigado!");
    Serial.println(leituraSensor);
    }
  delay(1000);
}
