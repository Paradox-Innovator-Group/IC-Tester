#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define buzz 45
#define pin1 2
#define pin2 3
#define pin3 4
#define pin4 5
#define pin5 6
#define pin6 7
#define pin7 8
#define pin8 9
#define pin9 10
#define pin10 11
#define pin11 12
#define pin12 13
#define pin13 21
#define pin14 22
#define pin15 23
#define pin16 24
#define pin17 25
#define pin18 26
#define pin19 27
#define pin20 28
#define pin21 29
#define pin22 30
#define pin23 31
#define pin24 32
#define pin25 33
#define pin26 34
#define pin27 35
#define pin28 36
#define green 38
#define red 39

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {A4, A5, A6, A7};
byte colPins[COLS] = {A0, A1, A2, A3};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
void setup() {
  pinMode(buzz, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("Univrsl ICTester");
  lcd.setCursor(0, 1);
  lcd.print("ParadoxInnovator");
  tone(buzz, 880, 382); delay(382); tone(buzz, 784, 382); delay(382);
  tone(buzz, 987, 382); delay(764);
  tone(buzz, 1046, 382); delay(764);

}
int enteredIC = 0;
int input = 0;
int readIC() {
  String enteredIC = "";

  char key = keypad.getKey();
  while (key != '*') {
    key = keypad.getKey();
    if (key != NO_KEY) {
      if (key == '#' && enteredIC.length() > 0) { // Check if E is pressed and there are characters to delete
        enteredIC.remove(enteredIC.length() - 1); // Remove the last character
        digitalWrite(buzz, HIGH);
        delay(10);
        digitalWrite(buzz, LOW);
      } else if (key != '#') { // Ignore E in password input
        Serial.print(key);
        digitalWrite(buzz, HIGH);
        delay(10);
        digitalWrite(buzz, LOW);
        enteredIC += key;
        delay(100); // delay to prevent multiple characters being entered at once
      } // delay to prevent multiple characters being entered at once
    }
    Serial.println(enteredIC);
    lcd.setCursor(3, 1);
    lcd.print("           ");
    lcd.setCursor(3, 1);
    lcd.print(enteredIC);
  }
  Serial.println(); // newline after password input
  int num = 0;
  int sign = 1;
  int i = 0;

  // if (enteredIC.charAt(0) == '-') {
  //   sign = -1;
  //   i = 1;
  // }
  if (enteredIC.length() > 0) {
    if (enteredIC.charAt(0) == '-') {
      sign = -1;
      enteredIC.remove(0, 1); // Remove the negative sign
    }

  for (int i = 0; i < enteredIC.length(); i++) {
      if (enteredIC.charAt(i) >= '0' && enteredIC.charAt(i) <= '9') {
        num = num * 10 + (enteredIC.charAt(i) - '0');
      }
  }
  }
  return num * sign;
}
void loop() {
  Serial.print("Enter IC Number :");
  lcd.clear();
  lcd.print("Enter IC Number:");
  lcd.setCursor(0, 1);
  lcd.print("IC");
  input = readIC();
  delay(20);
  lcd.clear();
  lcd.print("Checking IC");
  lcd.print(input);
  while (1)
  {
    char key = keypad.getKey();
    if (key != NO_KEY) {
      if (key == 'A')
      {
        Serial.println("Checking IC");
        database();
      }
    }
  }
 

}
void database()
{
  if(input == 7400)
      IC7400();
  else if(input == 7402)
      IC7402();
  else if(input == 7404)
      IC7404();
  else if(input == 7408)
      IC7408();
  else if(input == 7410)
      IC7410();
  else if(input == 7420)
      IC7420();
  else if(input == 7432)
      IC7432();
  else if(input == 74266)
      IC74266();
  else if(input == 7476)
      IC7476();
  else if(input == 7486)
      IC7486();
  else{
    Serial.print("No Data Found");
    lcd.setCursor(0,1);
    lcd.print("No Data Found    ");
    delay(1000);
    lcd.clear();
    lcd.print("Contact..");
    lcd.setCursor(0,1);
    lcd.print("ParadoxInnovator");
  }
}

void IC7400()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, INPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, INPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);

  //testing IC
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  int test1 = digitalRead(pin3);

  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  int test2 = digitalRead(pin6);

  digitalWrite(pin9, HIGH);
  digitalWrite(pin10, LOW);
  int test3 = digitalRead(pin8);

  digitalWrite(pin12, HIGH);
  digitalWrite(pin13, HIGH);
  int test4 = digitalRead(pin11);

  if (test1 == test2 == test3 == HIGH &&  test4 == LOW)
  {
    Serial.println("IC7400 Is OK!");
    delay(20);
    lcd.setCursor(0, 1);
    lcd.print("IC7400 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC7400 is Damaged!!");

    lcd.setCursor(0, 1);
    lcd.print("IC7400 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7402()
{
  pinMode(pin1, INPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, INPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, INPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);
  //testing IC
  digitalWrite(pin3, LOW);
  digitalWrite(pin2, LOW);
  int test1 = digitalRead(pin1);

  digitalWrite(pin6, HIGH);
  digitalWrite(pin5, LOW);
  int test2 = digitalRead(pin4);

  digitalWrite(pin9, LOW);
  digitalWrite(pin8, HIGH);
  int test3 = digitalRead(pin10);

  digitalWrite(pin12, HIGH);
  digitalWrite(pin11, HIGH);
  int test4 = digitalRead(pin13);

  if ( test2 == test3 == test4 == LOW && test1 ==HIGH)
  {
    Serial.println("IC7402 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7402 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC7402 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7402 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}
void IC7404()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, INPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, INPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, INPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);
  //testing IC
  digitalWrite(pin1, LOW);
  int test1 = digitalRead(pin2);

  digitalWrite(pin3, LOW);
  int test2 = digitalRead(pin4);

  digitalWrite(pin5, LOW);
  int test3 = digitalRead(pin6);

  digitalWrite(pin9, LOW);
  int test4 = digitalRead(pin8);

  digitalWrite(pin11, HIGH);
  int test5 = digitalRead(pin10);

  digitalWrite(pin13, HIGH);
  int test6 = digitalRead(pin12);

  if (test1 == test2 == test3 == test4 == HIGH &&  test5 == test6 == LOW)
  {
    Serial.println("IC7404 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7404 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green,LOW);
  }
  else
  {
    Serial.println("IC7404 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7404 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7408()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, INPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, INPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);
  //testing IC
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  int test1 = digitalRead(pin3);

  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  int test2 = digitalRead(pin6);

  digitalWrite(pin9, LOW);
  digitalWrite(pin10, LOW);
  int test3 = digitalRead(pin8);

  digitalWrite(pin12, HIGH);
  digitalWrite(pin13, HIGH);
  int test4 = digitalRead(pin11);

  if (test1 == test2 == test3 == LOW && test4 == HIGH)
  {
    Serial.println("IC7408 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7408 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC7408 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7408 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7410()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, INPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, OUTPUT);
  pinMode(pin12, INPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin13,LOW);
  int test1 = digitalRead(pin12);

  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin3, HIGH);
  int test2 = digitalRead(pin6);

  digitalWrite(pin9, HIGH);
  digitalWrite(pin10, HIGH);
  digitalWrite(pin11, HIGH);
  int test3 = digitalRead(pin8);



  if (test1 == test2 ==  HIGH && test3 ==LOW)
  {
    Serial.println("IC7410 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7410 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC7410 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7410 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7420()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, INPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, INPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  int test1 = digitalRead(pin6);

  digitalWrite(pin12, HIGH);
  digitalWrite(pin13, HIGH);
  digitalWrite(pin10, HIGH);
  digitalWrite(pin9, HIGH);
  int test2 = digitalRead(pin8);

  if (test1 == HIGH && test2 == LOW)
  {
    Serial.println("IC7420 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7420 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green,LOW);
    
  }
  else
  {
    Serial.println("IC7420 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7420 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7432()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, INPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, INPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  int test1 = digitalRead(pin3);

  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  int test2 = digitalRead(pin6);

  digitalWrite(pin9, HIGH);
  digitalWrite(pin10, LOW);
  int test3 = digitalRead(pin8);

  digitalWrite(pin12, LOW);
  digitalWrite(pin13, LOW);
  int test4 = digitalRead(pin11);

  if (test1 == test2 == test3 ==  HIGH && test4 ==LOW)
  {
    Serial.println("IC7432 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7432 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC7432 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7432 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC74266()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, INPUT);
  pinMode(pin11, INPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  int test1 = digitalRead(pin3);

  digitalWrite(pin6, LOW);
  digitalWrite(pin5, LOW);
  int test2 = digitalRead(pin4);

  digitalWrite(pin9, LOW);
  digitalWrite(pin8, HIGH);
  int test3 = digitalRead(pin10);

  digitalWrite(pin12, LOW);
  digitalWrite(pin13, HIGH);
  int test4 = digitalRead(pin11);

  if (test1 == test2 == HIGH && test3 == test4 == LOW)
  {
    Serial.println("IC74266 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC74266 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC74266 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC74266Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}
void IC7476()
{
  //JK FLIPFLOP
  pinMode(pin1, OUTPUT);//clk
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);//clk
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, INPUT);
  pinMode(pin11, INPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, INPUT);
  pinMode(pin15, INPUT);
  pinMode(pin16, OUTPUT);


  digitalWrite(pin13, LOW);
  digitalWrite(pin5, HIGH);
  //testing IC
  digitalWrite(pin4, HIGH);
  digitalWrite(pin16, LOW);
  digitalWrite(pin15, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  //generating clock
  for (int i = 0; i < 100; i++)
  {
    digitalWrite(pin1, HIGH);
    delay(1000);
    digitalWrite(pin1, LOW);
    delay(1000);
  }
  int test1 = digitalRead(pin15); //high

  digitalWrite(pin9, HIGH);
  digitalWrite(pin12, LOW);
  digitalWrite(pin11, LOW);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, HIGH);
  //generating clock
  for (int i = 0; i < 100; i++)
  {
    digitalWrite(pin6, HIGH);
    delay(1000);
    digitalWrite(pin6, LOW);
    delay(1000);
  }
  int test2 = digitalRead(pin11); //high

  if (test1 == test2 == HIGH)
  {
    Serial.println("IC7476 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7476 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
  }
  else
  {
    Serial.println("IC7476 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7476 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(800);
  }
}

void IC7486()
{
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin8, INPUT);
  pinMode(pin9, OUTPUT);
  pinMode(pin10, OUTPUT);
  pinMode(pin11, INPUT);
  pinMode(pin12, OUTPUT);
  pinMode(pin13, OUTPUT);
  pinMode(pin14, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin14, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  int test1 = digitalRead(pin3);

  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  int test2 = digitalRead(pin6);

  digitalWrite(pin9, HIGH);
  digitalWrite(pin10, LOW);
  int test3 = digitalRead(pin8);

  digitalWrite(pin12, LOW);
  digitalWrite(pin13, HIGH);
  int test4 = digitalRead(pin11);

  if (test1 == test2 == LOW && test3 == test4 == HIGH)
  {
    Serial.println("IC7486 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7486 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC7486 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7486 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}
