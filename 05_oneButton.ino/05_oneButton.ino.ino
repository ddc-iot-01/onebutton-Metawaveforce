/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: Jerry Smith
 * Date: 3/3/2020
 */

#include <OneButton.h>

// Setup OneButton on pin 23
OneButton button1(23, false);


int buttonState = LOW;
int flash = LOW;
int blue = 5;
int green = 6;

// Create variables buttonState and flash


void setup() {
  Serial.begin(9600);
  while(!Serial);
// Setup Serial Monitor
Serial.println("button setup.");
// Link oneButton library to functions click1, doubleclick1, longPressStart1
button1.attachClick(click1);
button1.attachDoubleClick(doubleclick1);
//button1.attachLongPressStart(longPressStart1);
//button1.attachLongPressStop(longPressStop1);
button1.setClickTicks(250);
button1.setClickTicks(2000);

pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
}


void loop() {
  // keep watching the push buttons:
  button1.tick();
  if (buttonState == LOW){
    digitalWrite (blue,LOW);
  }
  else 
  {
  digitalWrite (blue,HIGH);
  }
  
  if (flash == LOW){
  digitalWrite (green,LOW);
  }
  else
  {
  digitalWrite(green,HIGH);
  delay(40);
  digitalWrite (green,LOW);
  delay(40);
  }
  
} 
// loop


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time.
void click1() {
//change and print buttonState
Serial.println("button 1 click.");
buttonState = !buttonState;
Serial.print("buttonState = ");
Serial.println(buttonState);
  
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
  flash = !flash;
  Serial.print("flash = ");
  Serial.println(flash);
  
// change state of flash and print
} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("Button 1 longPress start");
// print longPress
} // longPressStart1

// This function will be called once, when the button1 is pressed for a long time.
void longPressStop1() {
  Serial.println("Button 1 longPress stop");
// print longPress
} // longPressStop1
