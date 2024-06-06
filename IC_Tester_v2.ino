#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//28 27 26 25 24 23 22 21||||| 20 19 18 17 16 15
//1  2  3  4  5  6  7  8 ||||| 9  10 11 12 13 14
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define buzz 46
#define pin1 2//pwm
#define pin2 3
#define pin3 4
#define pin4 5
#define pin5 6
#define pin6 7//pwm
#define pin7 8
#define pin8 9
#define pin9 10
#define pin10 11
#define pin11 12
#define pin12 13
#define pin13 14
#define pin14 15
#define pin15 16
#define pin16 17
#define pin17 18
#define pin18 19
#define pin19 30
#define pin20 31
#define pin21 22
#define pin22 23
#define pin23 24
#define pin24 25
#define pin25 26
#define pin26 27
#define pin27 28
#define pin28 29
#define green 48
#define red 47

const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte colPins[COLS] = {A3, A2, A1, A0};
byte rowPins[ROWS] = {A7, A6, A5, A4};
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
  lcd.print("Digital ICTester");
  lcd.setCursor(0, 1);
  lcd.print("ParadoxInnovator");
  tone(buzz, 880, 382); delay(382); tone(buzz, 784, 382); delay(382);
  tone(buzz, 987, 382); delay(764);
  //  tone(buzz, 1046, 382); delay(764);
  
}
int test1=0;
int test2=0;
int test3=0;
int test4=0;
int test5=0;
int test6=0;
//int enteredIC = 0;
String input = "";
String enteredIC = "";
String readIC() {
  enteredIC = "";

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
        if (key != '*')
          enteredIC += key;
        delay(100); // delay to prevent multiple characters being entered at once
      } // delay to prevent multiple characters being entered at once
    }
    Serial.println(enteredIC);
    lcd.setCursor(3, 1);
    lcd.print("           ");
    lcd.setCursor(3, 1);
    lcd.print(enteredIC);
    delay(20);
  }
  Serial.println(); // newline after password input
  //  int num = 0;
  //  int sign = 1;
  //  int i = 0;
  //
  //  // if (enteredIC.charAt(0) == '-') {
  //  //   sign = -1;
  //  //   i = 1;
  //  // }
  //  if (enteredIC.length() > 0) {
  //    if (enteredIC.charAt(0) == '-') {
  //      sign = -1;
  //      enteredIC.remove(0, 1); // Remove the negative sign
  //    }
  //
  //  for (int i = 0; i < enteredIC.length(); i++) {
  //      if (enteredIC.charAt(i) >= '0' && enteredIC.charAt(i) <= '9') {
  //        num = num * 10 + (enteredIC.charAt(i) - '0');
  //      }
  //  }
  //  }
  //  return num * sign;
  return enteredIC;
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
      if (key == 'C')
      {
        Serial.println("Checking IC");
        database();
      }
      if (key == 'B')
      {
        enteredIC = "";
        loop();
      }
      if (key == 'A')
      {
        //auto mode
      }
    }
  }


}
void database()
{
  if (input == "7400")
    IC7400();
  else if (input == "7402")
    IC7402();
  else if (input == "7404")
    IC7404();
  else if (input == "7408")
    IC7408();
  else if (input == "7410")
    IC7410();
  else if (input == "7420")
    IC7420();
  else if (input == "7432")
    IC7432();
  else if (input == "74266")
    IC74266();
  else if (input == "7476")
    IC7476();
  else if (input == "7486")
    IC7486();
  else {
    Serial.print("No Data Found");
    lcd.setCursor(0, 1);
    lcd.print("No Data Found    ");
    delay(1000);
    lcd.clear();
    lcd.print("Contact..");
    lcd.setCursor(0, 1);
    lcd.print("ParadoxInnovator");
    delay(5000);
    enteredIC = "";
    loop();
  }
}

void IC7400()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, INPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, OUTPUT);
  pinMode(pin25, INPUT);
  pinMode(pin26, OUTPUT);
  pinMode(pin27, OUTPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);

  //testing IC
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  test1 = digitalRead(pin3);

  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  test2 = digitalRead(pin6);

  digitalWrite(pin23, HIGH);
  digitalWrite(pin24, LOW);
  test3 = digitalRead(pin22);

  digitalWrite(pin26, HIGH);
  digitalWrite(pin27, HIGH);
  test4 = digitalRead(pin25);
  Serial.println(test1);
  Serial.println(test2);
  Serial.println(test3);
  Serial.println(test4);
  if (test1 == HIGH && test2 == HIGH && test3 == HIGH &&  test4 == LOW)
  {
    Serial.println("IC7400 Is OK!");
    delay(20);
    lcd.setCursor(0, 1);
    lcd.print("IC7400 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
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
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7402()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, INPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, OUTPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, INPUT);
  pinMode(pin25, OUTPUT);
  pinMode(pin26, OUTPUT);
  pinMode(pin27, INPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);
  //testing IC
  digitalWrite(pin3, LOW);
  digitalWrite(pin2, LOW);
  test1 = digitalRead(pin1);

  digitalWrite(pin6, HIGH);
  digitalWrite(pin5, LOW);
  test2 = digitalRead(pin4);

  digitalWrite(pin22, LOW);
  digitalWrite(pin23, HIGH);
  test3 = digitalRead(pin24);

  digitalWrite(pin25, HIGH);
  digitalWrite(pin26, HIGH);
  test4 = digitalRead(pin27);
  Serial.println(test1);
  Serial.println(test2);
  Serial.println(test3);
  Serial.println(test4);
  if ( test2 == LOW && test3 == LOW && test4 == LOW && test1 == HIGH)
  {
    Serial.println("IC7402 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7402 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
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
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}
void IC7404()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, INPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, INPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, INPUT);
  pinMode(pin25, OUTPUT);
  pinMode(pin26, INPUT);
  pinMode(pin27, OUTPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);
  //testing IC
  digitalWrite(pin1, LOW);
  test1 = digitalRead(pin2);

  digitalWrite(pin3, LOW);
  test2 = digitalRead(pin4);

  digitalWrite(pin5, LOW);
  test3 = digitalRead(pin6);

  digitalWrite(pin23, LOW);
  test4 = digitalRead(pin22);

  digitalWrite(pin25, HIGH);
  test5 = digitalRead(pin24);

  digitalWrite(pin27, HIGH);
  test6 = digitalRead(pin26);
  Serial.println(test1);
  Serial.println(test2);
  Serial.println(test3);
  Serial.println(test4);
  Serial.println(test5);
  Serial.println(test6);

  if (test1 == HIGH && test2 == HIGH && test3 == HIGH && test4 == HIGH &&  test5 == LOW && test6 == LOW)
  {
    Serial.println("IC7404 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7404 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC7404 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7404 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7408()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, INPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, OUTPUT);
  pinMode(pin25, INPUT);
  pinMode(pin26, OUTPUT);
  pinMode(pin27, OUTPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);
  //testing IC
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
  test1 = digitalRead(pin3);

  digitalWrite(pin4, HIGH);
  digitalWrite(pin5, LOW);
  test2 = digitalRead(pin6);

  digitalWrite(pin23, LOW);
  digitalWrite(pin24, LOW);
  test3 = digitalRead(pin22);

  digitalWrite(pin26, HIGH);
  digitalWrite(pin27, HIGH);
  test4 = digitalRead(pin25);
  Serial.println(test1);
  Serial.println(test2);
  Serial.println(test3);
  Serial.println(test4);
  if (test1 == LOW && test2 == LOW && test3 == LOW && test4 == HIGH)
  {
    Serial.println("IC7408 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7408 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
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
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7410()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, INPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, OUTPUT);
  pinMode(pin25, OUTPUT);
  pinMode(pin26, INPUT);
  pinMode(pin27, OUTPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
  digitalWrite(pin27, LOW);
  test1 = digitalRead(pin26);

  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  digitalWrite(pin3, HIGH);
  test2 = digitalRead(pin6);

  digitalWrite(pin25, HIGH);
  digitalWrite(pin24, HIGH);
  digitalWrite(pin23, HIGH);
  test3 = digitalRead(pin22);
  Serial.println(test1);
  Serial.println(test2);
  Serial.println(test3);


  if (test1 == HIGH && test2 ==  HIGH && test3 == LOW)
  {
    Serial.println("IC7410 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7410 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
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
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7420()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, INPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, OUTPUT);
  pinMode(pin25, INPUT);
  pinMode(pin26, OUTPUT);
  pinMode(pin27, OUTPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  test1 = digitalRead(pin6);

  digitalWrite(pin26, HIGH);
  digitalWrite(pin27, HIGH);
  digitalWrite(pin24, HIGH);
  digitalWrite(pin23, HIGH);
  test2 = digitalRead(pin22);
  Serial.println(test1);
  Serial.println(test2);
  if (test1 == HIGH && test2 == LOW)
  {
    Serial.println("IC7420 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7420 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(green, LOW);

  }
  else
  {
    Serial.println("IC7420 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7420 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7432()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, INPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, OUTPUT);
  pinMode(pin25, INPUT);
  pinMode(pin26, OUTPUT);
  pinMode(pin27, OUTPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  test1 = digitalRead(pin3);

  digitalWrite(pin4, LOW);
  digitalWrite(pin5, HIGH);
  test2 = digitalRead(pin6);

  digitalWrite(pin23, HIGH);
  digitalWrite(pin24, LOW);
  test3 = digitalRead(pin22);

  digitalWrite(pin26, LOW);
  digitalWrite(pin27, LOW);
  test4 = digitalRead(pin25);
  Serial.println(test1);
  Serial.println(test2);
  Serial.println(test3);
  Serial.println(test4);
  if (test1 == HIGH && test2 == HIGH && test3 ==  HIGH && test4 == LOW)
  {
    Serial.println("IC7432 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7432 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
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
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC74266()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, INPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, OUTPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, INPUT);
  pinMode(pin25, INPUT);
  pinMode(pin26, OUTPUT);
  pinMode(pin27, OUTPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  test1 = digitalRead(pin3);

  digitalWrite(pin6, LOW);
  digitalWrite(pin5, LOW);
  test2 = digitalRead(pin4);

  digitalWrite(pin23, LOW);
  digitalWrite(pin22, HIGH);
  test3 = digitalRead(pin24);

  digitalWrite(pin26, LOW);
  digitalWrite(pin27, HIGH);
  test4 = digitalRead(pin25);
  Serial.println(test1);
  Serial.println(test2);
  Serial.println(test3);
  Serial.println(test4);
  if (test1 == HIGH && test2 == HIGH && test3 == LOW && test4 == LOW)
  {
    Serial.println("IC74266 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC74266 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
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
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}
void IC7476()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  //JK FLIPFLOP
  pinMode(pin1, OUTPUT);//clk
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);//clk
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  pinMode(pin21, OUTPUT);
  pinMode(pin22, INPUT);
  pinMode(pin23, INPUT);
  pinMode(pin24, OUTPUT);
  pinMode(pin25, OUTPUT);
  pinMode(pin26, INPUT);
  pinMode(pin27, INPUT);
  pinMode(pin28, OUTPUT);


  digitalWrite(pin25, LOW);
  digitalWrite(pin5, HIGH);
  pwm();
  //testing IC
  digitalWrite(pin4, HIGH);
  digitalWrite(pin28, LOW);
  //  digitalWrite(pin27, LOW);
  digitalWrite(pin2, HIGH);
  digitalWrite(pin3, HIGH);
  //generating clock
  
  //  for (int i = 0; i < 100; i++)
  //  {
  //    digitalWrite(pin1, HIGH);
  //    delay(1000);
  //    digitalWrite(pin1, LOW);
  //    delay(1000);
  //  }

  test1 = digitalRead(pin27); //high

  digitalWrite(pin24, HIGH);
  digitalWrite(pin21, LOW);
  //  digitalWrite(pin23, LOW);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, HIGH);
  //generating clock
  //  for (int i = 0; i < 100; i++)
  //  {
  //    digitalWrite(pin6, HIGH);
  //    delay(1000);
  //    digitalWrite(pin6, LOW);
  //    delay(1000);
  //  }

  test2 = digitalRead(pin23); //high
  Serial.println(test1);
  Serial.println(test2);
  if (test1 ==  HIGH && test2 == LOW)
  {
    Serial.println("IC7476 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7476 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(green, LOW);
  }
  else
  {
    Serial.println("IC7476 is Damaged!!");
    lcd.setCursor(0, 1);
    lcd.print("IC7476 Is Damage!");
    digitalWrite(red, HIGH);
    digitalWrite(buzz, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void IC7486()
{
  test1=0;
  test2=0;
  test3=0;
  test4=0;
  test5=0;
  test6=0;
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, INPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, INPUT);
  pinMode(pin7, OUTPUT);
  pinMode(pin22, INPUT);
  pinMode(pin23, OUTPUT);
  pinMode(pin24, OUTPUT);
  pinMode(pin25, INPUT);
  pinMode(pin26, OUTPUT);
  pinMode(pin27, OUTPUT);
  pinMode(pin28, OUTPUT);
  digitalWrite(pin7, LOW);
  digitalWrite(pin28, HIGH);
  //testing IC
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, HIGH);
  test1 = digitalRead(pin3);

  digitalWrite(pin4, LOW);
  digitalWrite(pin5, LOW);
  test2 = digitalRead(pin6);

  digitalWrite(pin23, HIGH);
  digitalWrite(pin24, LOW);
  test3 = digitalRead(pin22);

  digitalWrite(pin26, LOW);
  digitalWrite(pin27, HIGH);
  test4 = digitalRead(pin25);
  Serial.println(test1);
  Serial.println(test2);
  Serial.println(test3);
  Serial.println(test4);
  if (test1 == LOW && test2 == LOW && test3 == HIGH && test4 == HIGH)
  {
    Serial.println("IC7486 Is OK!");
    lcd.setCursor(0, 1);
    lcd.print("IC7486 Is OK!");
    digitalWrite(green, HIGH);
    delay(1000);
    lcd.setCursor(0, 1);
    lcd.print("                  ");
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
    lcd.setCursor(0, 1);
    lcd.print("                  ");
    digitalWrite(red, LOW);
    digitalWrite(buzz, LOW);
  }
}

void pwm() {
  // Set pin 2 and pin 6 as output
  pinMode(pin1, OUTPUT);
  pinMode(pin6, OUTPUT);

  // Configure Timer1 for 1 Hz interrupt
  noInterrupts();           // Disable all interrupts
  TCCR1A = 0;               // Clear Timer/Counter Control Registers
  TCCR1B = 0;
  TCNT1 = 0;                // Initialize counter value to 0
  OCR1A = 7812;             // Set compare match register for 1 Hz (16 MHz / 1024 / 2)
  TCCR1B |= (1 << WGM12);   // CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10);  // 1024 prescaler
  TIMSK1 |= (1 << OCIE1A);  // Enable timer compare interrupt

  // Configure Timer3 for 1 Hz interrupt
  TCCR3A = 0;               // Clear Timer/Counter Control Registers
  TCCR3B = 0;
  TCNT3 = 0;                // Initialize counter value to 0
  OCR3A = 7812;             // Set compare match register for 1 Hz (16 MHz / 1024 / 2)
  TCCR3B |= (1 << WGM32);   // CTC mode
  TCCR3B |= (1 << CS32) | (1 << CS30);  // 1024 prescaler
  TIMSK3 |= (1 << OCIE3A);  // Enable timer compare interrupt

  interrupts();             // Enable all interrupts
}


// Timer1 interrupt service routine
ISR(TIMER1_COMPA_vect) {
  static bool state = false;
  state = !state;
  digitalWrite(pin2, state);  // Toggle pin 2
}

// Timer3 interrupt service routine
ISR(TIMER3_COMPA_vect) {
  static bool state = false;
  state = !state;
  digitalWrite(pin6, state);  // Toggle pin 6
}
