#include <SFE_BMP180.h>
#include "DHT.h"
#include <Wire.h>
#include <ESP8266WiFi.h>
//#include <Adafruit_BMP085.h>
//#define seaLevelPressure_hPa 1013.25
int sensorPin = A0;    // input for LDR and rain sensor
int enable2 = 13;      // enable reading Rain sensor
int sensorValue2 = 0;  // variable to store the value coming from sensor Rain sensor
double T, P;
WiFiClient client;
char status;
SFE_BMP180 bmp;
//Adafruit_BMP085 bmp;
DHT dht(2, DHT11);

String apiKey = "O2O4YCNCAVQB7YW2";
const char* server = "api.thingspeak.com";
const char *ssid =  "OPPO F19 Pro";
const char *pass =  "f4yz6qg4";

void setup() {
  Serial.begin(9600);
  pinMode(enable2, OUTPUT);
  dht.begin();
  bmp.begin();
  Wire.begin();
  WiFi.begin(ssid,pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop(){
status =  bmp.startTemperature();
  if (status != 0) {
    delay(status);
    status = bmp.getTemperature(T);

    status = bmp.startPressure(3);// 0 to 3
    if (status != 0) {
      delay(status);
      status = bmp.getPressure(P, T);
      if (status != 0) {

      }
    }
  }

float h = dht.readHumidity();
float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Temperature: ");
  Serial.println(t);
  Serial.print("Humidity: ");
  Serial.println(h);

  delay(500);
sensorValue2 = analogRead(sensorPin);
sensorValue2 = constrain(sensorValue2, 150, 440); 
sensorValue2 = map(sensorValue2, 150, 440, 1023, 0); 
if (sensorValue2>= 20)
{
  Serial.print("rain is detected");
  
digitalWrite(enable2, HIGH);
  }
  else
  
{
  Serial.print("rain not detected \n");
  digitalWrite(enable2, LOW); 
  }
  Serial.print("Rain value:       ");
  Serial.println(sensorValue2);
  Serial.println();

   Serial.print("absolute pressure: ");
    Serial.print(P, 2);
    Serial.println("mb");

     /*Serial.print("Pressure = ");
    Serial.print(bmp.readPressure());
    Serial.println(" Pa");

    Serial.print("Pressure at sealevel (calculated) = ");
    Serial.print(bmp.readSealevelPressure());
    Serial.println(" Pa");

    Serial.print("Altitude = ");
    Serial.print(bmp.readAltitude());
    Serial.println(" meters");*/

    if (client.connect(server, 80)) {
    String postStr = apiKey;
    postStr += "&field1=";
    postStr += String(t);
    postStr += "&field2=";
    postStr += String(h);
    postStr += "&field3=";
    postStr += String(P, 2);
    postStr += "&field4=";
    postStr += String(sensorValue2);
    postStr += "\r\n\r\n\r\n\r\n";

    client.print("POST /update HTTP/1.1\n");
    client.print("Host: api.thingspeak.com\n");
    client.print("Connection: close\n");
    client.print("X-THINGSPEAKAPIKEY: " + apiKey + "\n");
    client.print("Content-Type: application/x-www-form-urlencoded\n");
    client.print("Content-Length: ");
    client.print(postStr.length());
    client.print("\n\n\n\n");
    client.print(postStr);
    }
    client.stop();
  delay(100);
}
