/*
 * El ejemplo de esta semana es una conexión sencilla hacia alguna red WiFi 
 * 
 * Para esta semana, necesitamos lo siguiente:
 * ESP32
 * Una red WiFi existente en nuestro hogar, lugar de trabajo, etc.
 * 
 * No habrá una conexión física con ningún componente extra.
 * Realizado por: Sebastian Carranza C. -  TodoMaker
 */

/*Incluimos primero la librería*/
#include <Husarnet.h>
#include <WiFi.h>

const char* hostName = "esp32";
const char* husarnetJoinCode = "fc94:b01d:1803:8dd8:f33d:0a11:c475:c4fe/fc94:b01d:1803:8dd8:b293:5c7d:7639:932a/MzTzmw4UWKYnznfUfmRxaF";
const char* dashboardURL = "default";

const char* ssid = "Rebo";
const char* pass = "jose2260";

void setup() {
  
  Husarnet.selfHostedSetup(dashboardURL);
    Husarnet.join(husarnetJoinCode, hostName);
    Husarnet.start();
  Serial.begin(115200);
  /*Iniciamos la conexión a la red WiFi definida*/
  WiFi.begin(ssid, pass);
  delay(2000);
  /*En el terminal Serial, indicamos que se está realizando la conexión*/
  Serial.print("Se está conectando a la red WiFi denominada ");
  Serial.println(ssid);
  /*Mientras se realiza la conexión a la red, aparecerán puntos, hasta que se realice la conexión*/
  while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
  /*Con la conexión ya realizada, se pasa a imprimir algunos datos importantes, como la dirección IP asignada a nuestro dispositivo*/
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  /*No se contempla el uso de un loop en el ejemplo de esta semana*/
}
