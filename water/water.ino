#define ledPin 6
#define sensorPin A0
void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);


}

void loop() {
  // put your main code here, to run repeatedly:
 
  int sensorValue = analogRead(sensorPin);
  if (sensorValue > 100)  {
    int outputValue = map(sensorValue, 100, 800, 0, 255);
    Serial.println(outputValue);
    analogWrite(ledPin, outputValue); // generate PWM signal
  
}

}
