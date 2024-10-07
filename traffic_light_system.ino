#include <LiquidCrystal.h>

int RED = 9;
int YELLOW = 8;
int GREEN = 7;
LiquidCrystal lcd(11,    10, 5, 4, 3, 2);

int DELAY_RED = 5000;
int DELAY_YELLOW = 2000;
int DELAY_GREEN = 5000;
int WARN_DELAY = 2000;
int RANDOM_GREEN_LENGTH[5] = {5000, 8000, 15000, 3500, 12000};
int last_index = -1;

void setup(){
  
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN,  OUTPUT);
  // Initialises the width, 16 columns. And rows , 2
     lcd.begin(16, 2);
  // Sets position of the cursor on screen
     lcd.setCursor(0, 1);
    //  Prints 
     lcd.print("Turning On");
    //  Resets cursor after printing
     lcd.setCursor(0, 1);
     lcd.print("Traffic Light");
     delay(2000);
    //  Clears any text
     lcd.clear();
  
}
void loop(){  
  int random_index;

  do 
  {
    random_index = random(0, 5);
  } while (random_index == last_index);

  last_index = random_index;

  green_light();
   walk();
  delay(RANDOM_GREEN_LENGTH[random_index]);
   lcd.clear();

  yellow_light();
  delay(DELAY_YELLOW);

  red_light();
   lcd.begin(16, 2);
   lcd.setCursor(0, 0);
   lcd.print("WALK");
  delay(DELAY_RED);
   lcd.clear();

  yellow_light_warn();
  delay(WARN_DELAY);
}

void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}
void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}
void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}
void yellow_light_warn() 
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, HIGH);
}

void walk()
{
lcd.begin(16, 2);
   lcd.setCursor(0, 0);
   lcd.print("DON'T WALK");
}