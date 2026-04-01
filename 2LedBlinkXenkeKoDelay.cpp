#include <Arduino.h>

int led1 = 6;
unsigned long LastTime1 = 0;

int led2 = 3;
unsigned long LastTime2 = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  bool state = digitalRead(led1);

  if(millis() - LastTime1 >= 1000){
    LastTime1 = millis();
    digitalWrite(led1, !digitalRead(led1));
  }

  if(millis() - LastTime2 >= 1000){
    LastTime2 = millis();
    digitalWrite(led2, state);
  }
}
