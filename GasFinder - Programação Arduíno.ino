const int pino_buzzer = D7; // pino onde o buzzer está conectado
const int pino_mq2 = A0; // pino onde o sensor está conectadO
float sensorValue; // armazenar valor do sensor
String msg; // armazena a mensagem a ser enviada para o Broker

#include <EspMQTTClient.h>

EspMQTTClient client(
  "Souza",              // SSID WiFi
  "12020623",           // Password WiFi
  "broker.hivemq.com",  // MQTT Broker
  "32093705_GasFinder_ESP", // Client
  1883                  // MQTT port
);


void setup() {
  Serial.begin(300);
  pinMode(pino_buzzer, OUTPUT);
}

void postMQTT(String msg) {
  client.publish("32093705_GasFinder", String(msg));
}

void confBuzzer() {  
  digitalWrite(pino_buzzer, HIGH);
  delay(100);
  digitalWrite(pino_buzzer, LOW);
  delay(300);
}

void onConnectionEstablished(){
  Serial.println("Conexão Estabelecida");
}

void loop() {
  client.loop();
  sensorValue = analogRead(pino_mq2);
  Serial.println(sensorValue);

  if (sensorValue < 100) { //desliga o buzzer caso não tenha gás no ambiente    
    digitalWrite(pino_buzzer, LOW);
    msg = "off";
  } else {
    if (sensorValue < 200)
      msg = "Detectado Níveis Baixos de Concentração de Gás\nValor: " + String(sensorValue/1024*100) + "%";
    else if (sensorValue < 400)
      msg = "Detectado Níveis Médios de Concentração de Gás\nValor: " + String(sensorValue/1024*100) + "%";
    else if (sensorValue < 800)
      msg = "Detectado Níveis Altos de Concentração de Gás\nValor: " + String(sensorValue/1024*100) + "%";
    else if (sensorValue >= 800)
      msg = "Detectado Níveis Emergenciais de Concentração de Gás\nValor: " + String(sensorValue/1024*100) + "%";
    postMQTT(msg);
    confBuzzer();
  }
}
