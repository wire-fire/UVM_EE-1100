//1-11-24 Jack McTasney
//4x1 7 segment test code with ATMEGA2560 
//Wired:
// 42: E    43: D1
// 44: D    45: A
// 46: DP   47: F
// 48: C    49: D2
// 50: G    51: D3
// 52: D4   53: B
//        
//        A
//       ---
//  F  |     |  B
//     |  G  |
//       ---
//  E  |     | C
//     |  D  |
//       ---
// Pull D# Low with A-->G (or DP) High to turn on segment!

//Define statements to make code more legible
#define A 2
#define B 3
#define C 4
#define D 5
#define E 6
#define F 7
#define G 8
#define DP 9
#define digit1 10
#define digit2 11
#define digit3 12
#define digit4 13

void digitOn(int num){
  //I am doing this the lazy way
  //The digit of interest is pulled LOW and all others are pulled HIGH (only turning on digit of interest)
  if (num==1){
    digitalWrite(digit1,LOW);
    digitalWrite(digit2,HIGH);
    digitalWrite(digit3,HIGH);
    digitalWrite(digit4,HIGH);
  }
  else if (num==2){
    digitalWrite(digit1,HIGH);
    digitalWrite(digit2,LOW);
    digitalWrite(digit3,HIGH);
    digitalWrite(digit4,HIGH);
  }
  else if (num==3){
    digitalWrite(digit1,HIGH);
    digitalWrite(digit2,HIGH);
    digitalWrite(digit3,LOW);
    digitalWrite(digit4,HIGH);
  }
  else if (num==4){
    digitalWrite(digit1,HIGH);
    digitalWrite(digit2,HIGH);
    digitalWrite(digit3,HIGH);
    digitalWrite(digit4,LOW);
  }
}

void refreshRateDemo(){
  for (int i=50;i>=5;i-=1)
  {
    // Digit 1 on
    digitOn(1);
    // "I"
    digitalWrite(F,HIGH);
    digitalWrite(E,HIGH);
    delay(i);
    // Digit 2 on
    digitOn(2);
    // With previous "I" print, makes an "E"
    digitalWrite(A,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(D,HIGH);
    delay(i);
    // Repeat on digit 3
    digitOn(3);
    delay(i);
    // Repeat on digit 4
    digitOn(4);
    delay(i);
    // Reset segments to off
    digitalWrite(F,LOW);
    digitalWrite(E,LOW);
    digitalWrite(A,LOW);
    digitalWrite(G,LOW);
    digitalWrite(D,LOW);
  }
  unsigned long hold=millis();
  while (millis()<hold+2000) //2 second hold at solid screen
  {
    digitalWrite(F,LOW);
    digitalWrite(E,LOW);
    digitalWrite(A,LOW);
    digitalWrite(G,LOW);
    digitalWrite(D,LOW);
    digitOn(1);
    digitalWrite(F,HIGH);
    digitalWrite(E,HIGH);
    digitOn(2);
    digitalWrite(A,HIGH);
    digitalWrite(G,HIGH);
    digitalWrite(D,HIGH);
    digitOn(3);
    digitOn(4);
  }
}

void setup() {
  // Don't freak out, this is just a bunch of initializations for the 12 outputs
  // needed to drive the 1x4 7 segment display!
  pinMode(E,OUTPUT);
  pinMode(digit1,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(A,OUTPUT);
  pinMode(DP,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(digit2,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(digit3,OUTPUT);
  pinMode(digit4,OUTPUT);
  pinMode(B,OUTPUT);
  // Reverse-bias all diodes in display (aka turn everything off)
  digitalWrite(A,LOW);
  digitalWrite(B,LOW);
  digitalWrite(C,LOW);
  digitalWrite(D,LOW);
  digitalWrite(E,LOW);
  digitalWrite(F,LOW);
  digitalWrite(G,LOW);
  digitalWrite(DP,LOW);
  digitalWrite(digit1,HIGH);
  digitalWrite(digit2,HIGH);
  digitalWrite(digit3,HIGH);
  digitalWrite(digit4,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  refreshRateDemo();
  delay(100); //Stability delay
}
