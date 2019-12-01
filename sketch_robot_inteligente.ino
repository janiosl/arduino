//Configuração manual do sensor HC-SR04
//Pinos do sensor
int PinTrigger = 2; //Pino para cabeamento do Trigger
int PinEcho = 3; //Pino para cabeamento do Echo

//Variáveis para cálculo de distância
float TempoEcho = 0;
const float VelocidadeSom_mpors = 340;
const float VelocidadeSom_mporus = 0.000340;
float dist;
int parada = 0;

//Configuração dos pinos ligados às entradas da ponte H
//Motor A
int IN1 = 4;
int IN2 = 5;
//Motor B
int IN3 = 6;
int IN4 = 7;

void setup() {
  //Configuração do modo de operação dos pinos
  //Sensor de obstáculos
  pinMode(PinTrigger, OUTPUT);
  digitalWrite(PinTrigger, LOW);
  pinMode(PinEcho, INPUT);
  Serial.begin(9600);
  delay(100);

  //Motor A
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  //Motor B
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  //Gira o Motor A no sentido horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Gira o Motor B no sentido horario
  //Invertidos os comandos do motor B em todo o código.
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  Serial.println("Andando...");
  
  //Dispara o pulso, armazena o tempo de resposta
  //Utiliza função de cálculo para calcular a distância
  DisparaPulsoUltrassonico(); //Dispara o pulso
  TempoEcho = pulseIn(PinEcho, HIGH); //Guarda tempo de resposta do Echo
  dist = CalculaDistancia(TempoEcho) * 100;
  
  if (dist < 50)
  {
    parada = 1;
    Serial.println("Obstáculo encontrado");
    Serial.println(dist);
    //Para o motor A
    Serial.println("Parando motor A");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    //Para o motor B
    Serial.println("Parando motor B");
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(1000);
    
    //Gira o Motor A no sentido anti-horario
    Serial.println("Efetuando ré");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    //Gira o Motor B no sentido anti-horario
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    delay(1000);
    
    //Faz uma curva
    Serial.println("Fazendo curva");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    delay(250);
    
    //Para o motor A
    Serial.println("Parando curva");
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, HIGH);
    //Para o motor B
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, HIGH);
    delay(500);
    dist = 999;
  }
  delay(1000);
}

void DisparaPulsoUltrassonico() {
  //Função dispara o pulso através do Trigger
  digitalWrite(PinTrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(PinTrigger, LOW);
}
float CalculaDistancia(float tempo_us) {
  //Calcula a distância a partir do tempo de resposta do Echo
  return ( (tempo_us * VelocidadeSom_mporus) / 2 );
}
