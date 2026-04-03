#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Định nghĩa số hàng và số cột
const byte i = 4;
const byte j = 4;

LiquidCrystal_I2C lcd(0x27,16,2);
// Định nghĩa bản đồ phím (như trên bàn phím)
char keys[i][j] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};

// Kết nối chân hàng và cột
byte rowPins[i] = {9, 8, 7, 6}; // R1, R2, R3, R4
byte colPins[j] = {5, 4, 3, 2}; // C1, C2, C3, C4

// Khởi tạo thư viện
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, i, j );

void setup(){
  Serial.begin(9600);
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(1,0);
  lcd.print("Mini Calculator");
  delay(2000);
  lcd.clear(); 
}

long num1 = 0; long num2 = 0;
char op;
boolean presentValue = false;
boolean finalResult = false;
String inputString = "";

void loop(){
  char key = keypad.getKey();
  if(key){
    if(key >= '0' && key <= '9'){
      if(finalResult == true){
        inputString = key;
        finalResult = false;
        lcd.clear();
      }
      else{inputString += key;}
      lcd.print(key);
    }
    else if(key == 'C'){
      num1 = 0; num2 = 0;
      inputString = "";
      presentValue = false;
      finalResult = false;
      lcd.clear();
    }
    else if(key == '='){
      if(inputString != ""){
      num2 = inputString.toInt();
      lcd.print(key);
      lcd.setCursor(0,1);
      if(op == '+'){lcd.print(num1 + num2);}
      else if(op == '-'){lcd.print(num1 - num2);}
      else if(op == '*'){lcd.print(num1 * num2);}
      else{
        if(num2 == 0){lcd.print("Math Error");}
        else{lcd.print((float)num1 / num2);}
      }}
      else if(num2 == 0){
        lcd.setCursor(0,1);
        lcd.print("Syntax Error");
      }
      inputString = "";
      finalResult = true;
    }
    else{
      if(inputString != ""){
      num1 = inputString.toInt();
      inputString = "";
      op = key;
      lcd.print(op);
      presentValue = true;
      boolean finalResult = false;}
    }
  }
}
