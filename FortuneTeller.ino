#include <LiquidCrystal.h>
// initializing library, letting it know which pins are used
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char * messagePadded = "              You should just die                 ";
// creating variables 
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  // starting LCD library, telling it how large the screen is
  lcd.begin(16, 2);
  // setting up the pinswitch as an input
  pinMode(switchPin, INPUT);
  // printing to the screen
  lcd.print("Ask the");
  // setCursor allows us to change the coordinates on the screen. (0, 0) is first column, first row
  lcd.setCursor(0, 1);
  lcd.print("Crystal Screen!");
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(5);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("The Screen says:");
      lcd.setCursor(0, 1);
      
      switch(reply) {
        case 0:
          lcd.print("Fuck no");
          break;
        case 1:
          lcd.print("Get outta here!");
          break;
        case 2:
          lcd.print("Sure, why not");
          break;
        case 3:
          lcd.print("nah");
          break;
        case 4:
         
          for (int letter = 0; letter <= strlen(messagePadded) - 16; letter++) //From 0 to upto n-16 characters supply to below function
          {
            showLetters(0, letter);
          }
          //lcd.print("sometimes you should just die");
          break;
      }
    }
  }
  prevSwitchState = switchState;
}

void showLetters(int printStart, int startLetter)
{
  lcd.setCursor(printStart, 1);
  for (int letter = startLetter; letter <= startLetter + 15; letter++) // Print only 16 chars in Line #2 starting 'startLetter'
  {
    lcd.print(messagePadded[letter]);
  }
  lcd.print(" ");
  delay(400);
}
