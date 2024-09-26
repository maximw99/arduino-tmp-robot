#include <Arduino.h>

// variables
const int sensorPin = A0;


// put function declarations here:

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int pinNumber = 2; pinNumber < 7; pinNumber++){
    pinMode(pinNumber, OUTPUT);
    digitalWrite(pinNumber, LOW);
  }

  // pinMode(4, OUTPUT);
  // pinMode(3, OUTPUT);
  // pinMode(2, OUTPUT);
  // digitalWrite(4, HIGH);
  // digitalWrite(3, HIGH);
  // digitalWrite(2, HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor: ");
  Serial.print(sensorVal);
  Serial.print(" ");

  float voltage = (sensorVal/1024.0) * 5;
  Serial.print("Volt: ");
  Serial.print(voltage);
  Serial.print(" ");

  float tempature = (voltage - 0.5) * 100;
  Serial.print("Temp: ");
  Serial.print(tempature);
  Serial.print(" ");
  delay(1500);

  if (tempature > 20){
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
  }

  if (tempature > 24){
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, LOW);
  }

  if (tempature > 27){
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(4, HIGH);
  }

}

// put function definitions here: