#include <LiquidCrystal.h>

int RED = 9;
int YELLOW = 8;
int GREEN = 7;


LiquidCrystal lcd(11, 10, 5, 4, 3, 2);

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
int WARN_DELAY = 2000;
int RANDOM_GREEN_LENGTH[5] = {5000, 8000, 15000, 3500, 12000};
int last_index = -1;

// Make a traffic light class that can be reused 
class TrafficLight {
  public: 
     int redPin;
     int yellowPin;
     int greenPin;

     TrafficLight(int red, int yellow, int green) {
      redPin = red;
      yellowPin = yellow;
      greenPin = green;
      pinMode(redPin, OUTPUT);
      pinMode(yellowPin, OUTPUT);
      pinMode(greenPin, OUTPUT);
     }

     void greenLight() {
      digitalWrite(greenPin, HIGH);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, LOW);
     }

     void yellowLight() {
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, LOW);
     }

     void redLight() {
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, LOW);
      digitalWrite(redPin, HIGH);
     }

     void warnLight() {
      digitalWrite(greenPin, LOW);
      digitalWrite(yellowPin, HIGH);
      digitalWrite(redPin, HIGH);
     }
}

// Set traffic light class to pins on arduino
TrafficLight(RED, YELLOW, GREEN);

void setup(){
  // Initialises the width, 16 columns. And rows , 2
     lcd.begin(16, 2);
     lcd.print("Traffic Light");
   //  lcd.createChar(1, arrow_bottom);
    //  lcd.createChar(2, arrow_top);
    //  lcd.createChar(3, arrow_point_bottom);
    //  lcd.createChar(4, arrow_point_top);
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

  // trafficLight object handles light states instead of my original functions
  TrafficLight.greenLight();
  printMessage("DON'T WALK");
  delay(RANDOM_GREEN_LENGTH[random_index]);
   lcd.clear();

  TrafficLight.yellowLight();
  delay(DELAY_YELLOW);

  TrafficLight.redLight();
  //  arrow();
  delay(DELAY_RED);
   lcd.clear();

  TrafficLight.warnLight();
  delay(WARN_DELAY);
}

void printMessage(String message) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(message);
}