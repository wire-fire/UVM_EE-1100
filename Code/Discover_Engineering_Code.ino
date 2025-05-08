/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128  // OLED display width,  in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels
// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
#define P1 11
#define P2 12
#define P3 13
#define THRESHOLD 120

int pos = 0;  // variable to store the servo position

void setup() {
  Serial.begin(9600);
  if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {  // Initialize OLED Display to address 0x3C
    Serial.println(F("SSD1306 allocation failed"));
    while (true)
      ;
  }
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  oled.clearDisplay();
  oled.setCursor(1, 1);
  oled.setTextSize(2);
  oled.setTextColor(WHITE);
  oled.print("Welcome to the IEEE Club!");
  oled.display();
  delay(10);
  Serial.println("Should be printed");

  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(P3, OUTPUT);
  myservo.write(0);

}

void loop() {
  digitalWrite(P1, HIGH);
  digitalWrite(P2, HIGH);
  digitalWrite(P3, HIGH);
  oled.clearDisplay();

  /*
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
*/
  // Choices
  oled.setCursor(1, 1);
  oled.setTextSize(2);
  oled.print("A");
  oled.setCursor(11, 5);  // Centered!!
  oled.setTextSize(1);
  oled.print(" 3,635");
  oled.setCursor(16, 15);
  oled.print("  100");

  oled.setCursor(1, 40);
  oled.setTextSize(2);
  oled.print("B");
  oled.setCursor(11, 44);
  oled.setTextSize(1);
  oled.print(" 438");
  oled.setCursor(12, 54);
  oled.print("  92");

  oled.setCursor(70, 1);
  oled.setTextSize(2);
  oled.print("C");
  oled.setCursor(81, 5);
  oled.setTextSize(1);
  oled.print(" 777");
  oled.setCursor(81, 15);
  oled.print(" 131");

  oled.setCursor(70, 40);
  oled.setTextSize(2);
  oled.print("D");
  oled.setCursor(81, 44);
  oled.setTextSize(1);
  oled.print(" 2025");
  oled.setCursor(93, 54);
  oled.print(" 55");
  

  oled.display();

  while (digitalRead(2) == LOW) {
    oled.clearDisplay();
    oled.setCursor(5, 16);
    oled.setTextSize(2);
    oled.print("CORRECT!");
    oled.display();
    digitalWrite(P3, LOW);
    for (pos = 0; pos <= THRESHOLD; pos += 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);  // tell servo to go to position in variable 'pos'
      delay(5);           // waits 15 ms for the servo to reach the position
    }
    for (pos = THRESHOLD; pos > 0; pos -= 1) {  // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);  // tell servo to go to position in variable 'pos'
      delay(5);           // waits 15 ms for the servo to reach the position
    }
  }
  while (digitalRead(3) == LOW) {
    oled.clearDisplay();
    oled.setCursor(5, 16);
    oled.setTextSize(2);
    oled.print("WRONG (B)!");
    oled.display();
    digitalWrite(P1, LOW);
  }
  while (digitalRead(4) == LOW) {
    oled.clearDisplay();
    oled.setCursor(5, 16);
    oled.setTextSize(2);
    oled.print("WRONG (C)!");
    oled.display();
    digitalWrite(P1, LOW);
  }
  while (digitalRead(5) == LOW) {
    oled.clearDisplay();
    oled.setCursor(5, 16);
    oled.setTextSize(2);
    oled.print("WRONG (D)!");
    oled.display();
    digitalWrite(P1, LOW);
  }
  //delay(2000);
}
