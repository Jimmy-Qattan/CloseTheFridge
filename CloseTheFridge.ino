#include <SR04.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
SR04 sr04 = SR04(3, 2);
#define buzzer 4

long dist;
int phase = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

  
}

void loop() {
  dist = sr04.Distance();
  lcd.setCursor(0, 1);
  Serial.print(dist);
  
  isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey1();
}

void isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey1() {
  for (int g = 0; g < 10000; g++) {
    if ((dist < 70)) {
      isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey2();
      delay(1000);
    }
  }
}

void isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey2() {
  for (int i = 0; i < 1000; i++) {
    lcd.clear();
    phase = 1;
    dist = sr04.Distance();
    if (phase == 1) {
      lcd.print("Eating Time! :)");
    }
    delay(2000);
    if (dist > 200) {
      isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey3();
    }
    delay(500);
  }
}

void isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey3() {
  for (int j = 0; j < 1000; j++) {
    lcd.clear();
    phase = 2;
    if (phase == 2) {
      lcd.clear();
      lcd.print("5");
      delay(1000);
      lcd.clear();
      lcd.print("4");
      delay(1000);
      lcd.clear();
      lcd.print("3");
      delay(1000);
      lcd.clear();
      lcd.print("2");
      delay(1000);
      lcd.clear();
      lcd.print("1");
      delay(1000);
      lcd.clear();
      lcd.print("CLOSE FRIDGE!!!!!!");
    }
    digitalWrite(buzzer, HIGH);
    isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey4(); 
    delay(500);
  }
}

void isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey4() {
  for (int k = 0; k < 1000; k++) {
    dist = sr04.Distance();
    if (dist < 50) {
      digitalWrite(buzzer, LOW);
      lcd.clear();
      delay(1000);
      isTheFatRetardStillLookingForHisPieInTheFridgeyWidgey1();
    }
    delay(500);
  }
}
