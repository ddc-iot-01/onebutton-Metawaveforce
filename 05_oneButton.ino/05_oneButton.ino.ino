/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: Jerry Smith
 * Date: 3/3/2020
 */

#include "OneButton.h"

// Setup OneButton on pin 23
OneButton button1(23, false);

int buttonState = LOW;
int flash = LOW;

// Create variables buttonState and flash


void setup() {
  Serial.begin(9600);
  while(!Serial);
// Setup Serial Monitor
// Link oneButton library to functions click1, doubleclick1, longPressStart1
button1.attachClick(click1);
button1.attachDoubleClick(doubleclick1);
button1.attachLongPressStart(longPressStart1);
button1.attachLongPressStop(longPressStop1);
//button1.attachDuringLongPress(longPress1);
button1.setClickTicks(250);
button1.setClickTicks(2000);
}


void loop() {
  // keep watching the push buttons:
  button1.tick();
  
} // loop


// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time.
void click1() {
//change and print buttonState
Serial.println("button 1 click.");
buttonState = !buttonState;
Serial.print("buttonState");
  
} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("Button 1 doubleclick.");
  flash = !flash;
  Serial.println("flash = ");
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
