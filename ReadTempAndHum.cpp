#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int DHTPIN = 2;       
const int DHTTYPE = DHT11;

DHT dht(DHTPIN,DHTTYPE);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight();
  dht.begin();         
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print("Nhiet do: "); lcd.print(t);

  lcd.setCursor(0,1);
  lcd.print("Do am: "); lcd.print(h);

  Serial.print("Nhiet do: ");
  Serial.println(t);               
  Serial.print("Do am: ");
  Serial.println(h);               
  
  Serial.println();                
  delay(1000);                     
}
