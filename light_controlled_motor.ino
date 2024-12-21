#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 7, 6, 5, 4, 3);

// Pins Definition
#define LDR A0
#define MotorPin 10

// Functions Definition
void PINS_INIT();
// Variables Definition
int LDR_SENSE();
void LCD_DISPLAY();
int MOTOR_SPEED(int);
float MotorSpeed_LDR = 0;

void setup() {
    // Turn on an LCD
    lcd.begin(16, 2);
    // SET PIN MODES --> INPUT \ OUTPUT 
    PINS_INIT();
}

void loop() {
    MOTOR_SPEED();
    LCD_DISPLAY();
}
int LDR_SENSE() {
    MotorSpeed_LDR = analogRead(LDR);
}

void MOTOR_SPEED() {
    LDR_SENSE();
    MotorSpeed_LDR = map(MotorSpeed_LDR, 1023, 0, 0, 255);
    analogWrite(MotorPin ,MotorSpeed_LDR);
}

void LCD_DISPLAY() {
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print(" SPEED: ");
    lcd.setCursor(4, 1);
    lcd.print("=");
    lcd.print((MotorSpeed_LDR / 255) * 100);
    lcd.print("%");
    delay(100);
}

void PINS_INIT() {
    pinMode(MotorPin, OUTPUT);
}