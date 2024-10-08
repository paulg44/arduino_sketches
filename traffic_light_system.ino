#include <LiquidCrystal.h>

int RED = 9;
int YELLOW = 8;
int GREEN = 7;
LiquidCrystal lcd(11, 10, 5, 4, 3, 2);

byte stop_icon[] = {
  B00000,
  B00000,
  B01110,
  B10011,
  B10101,
  B11001,
  B01110,
  B00000
};

byte arrow_bottom[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111
};

byte arrow_top[] = {
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte arrow_point_bottom[] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B10000,
  B11000,
  B11100,
  B11110
};

byte arrow_point_top[] = {
  B11110,
  B11100,
  B11000,
  B10000,
  B00000,
  B00000,
  B00000,
  B00000
};

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
     lcd.print("Traffic Light");
     lcd.createChar(1, arrow_bottom);
     lcd.createChar(2, arrow_top);
     lcd.createChar(3, arrow_point_bottom);
     lcd.createChar(4, arrow_point_top);
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
   lcd.setCursor(0, 1);
   lcd.write(byte(0));
  delay(RANDOM_GREEN_LENGTH[random_index]);
   lcd.clear();

  yellow_light();
  delay(DELAY_YELLOW);

  red_light();
   lcd.begin(16, 2);
   lcd.setCursor(0, 0);
   lcd.print("WALK");
   lcd.setCursor(8, 0);
   lcd.write(byte(1));
   lcd.setCursor(9, 0);
   lcd.write(byte(1));
   lcd.setCursor(10, 0);
   lcd.write(byte(1));
   lcd.setCursor(11, 0);
   lcd.write(byte(1));
   lcd.setCursor(8, 1);
   lcd.write(byte(2));
   lcd.setCursor(9, 1);
   lcd.write(byte(2));
   lcd.setCursor(10, 1);
   lcd.write(byte(2));
   lcd.setCursor(11, 1);
   lcd.write(byte(2));
   lcd.setCursor(12, 0);
   lcd.write(byte(3));
   lcd.setCursor(12, 1);
   lcd.write(byte(4));
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