/*
Projeto Bot Green: Sensor de humidade para plantas
As fotos do projeto estão na página do Instagram @python.ds
*/

//Led vermelho conectado em GND e Pino digital 13
int pinLed = 13;
//Led verde conectado na protoboard
int pinLed_green = 7;
//Fio conectado à porta analógica 0 à protoboard para conexão com um dos pregos do sensor
//Entre este fio e o fio ligado ao prego há um resisotr de 10ohms
//No outro do resistor é colocado outro fio conectado ao GND do Arduino
int pinSensor = 0;

//Variável para registrar o valor lido pelo sensor
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

  /*Se o valor for menor que 250, significa que está
  faltando água. O led de alerta é ligado e a mensagem
  exibida no monitor
  O valor de 250 no exemplo é arbitrário, baseado nos testes que fiz
  numa plana esṕecífica. O ideal é rodar conectado ao monitor serial e
  verificar os valores adequados para avaliar a humidade de acordo com
  a terra usada e a demanda por água da planta
  */
  if (leituraSensor < 250) {
    //Como aprimoramente, esse limite poderia ser substituído por uma variável int no início
    //do código, para não ser necessário alterar diretamente na função.
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
