#include <Arduino.h>

void PrintResult(int p, int m);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  Serial.println("Welcome to the Virtual Rock, Paper, Scissors Game!");
  Serial.println("Type a number 1-Rock, 2-Paper or 3-Scissor and press Enter:");
}

void loop() {
  if(Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    int player = input.toInt();

    if(player >= 1 && player <=3){
      Serial.print("You typed: ");
      if(player == 1) Serial.println("Rock");
      else if(player == 2) Serial.println("Paper");
      else Serial.println("Scissor");

      int result = random(1, 4); 
      Serial.print("My turn: ");
      if(result == 1) Serial.println("Rock");
      else if(result == 2) Serial.println("Paper");
      else Serial.println("Scissor");

      PrintResult(player,result);
      Serial.println("Please restart serial monitor for the next round!");
    }
  else{
    Serial.println("Invalid! Please restart serial monitor to play again!");}
  }
}

void PrintResult(int p, int m){
  if(p == m) Serial.println(">>It's a Draw!");
  else if((p == 1 && m == 3)||(p == 2 && m == 1)||(p == 3 && m == 2)) Serial.println(">>You beat me!");
  else Serial.println(">>I won!");
}
