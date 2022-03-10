// Tom Williams 2022

#include "Keyboard.h" // library containing USB keyboard code

const int buttonRtPin = 6; // turn right
const int buttonLftPin = 7; // turn left



long lastClkUp = millis(); // for measuring times between clicks
 // - debouncing
 //millis measures the time between when your board last powered up, e.g on a click of a button
long lastClkLeft = millis();
long lastClkRight = millis();

int btnStateUp; // for checking the state of a pushButton
int btnStateLeft;
int btnStateRight;

char upKey = KEY_UP_ARROW;
char downKey = KEY_DOWN_ARROW;
char leftKey = KEY_LEFT_ARROW;
char rightKey = KEY_RIGHT_ARROW;

void setup() {
 // make the pushButton pin an input:
 pinMode(buttonRtPin, INPUT);
 pinMode(buttonLftPin, INPUT);
 // initialize control over the keyboard:
 Keyboard.begin();
 pinMode(13, OUTPUT);
 digitalWrite(13, LOW); // just turn off
 // onboard LED - not needed
}
void loop() {


 
 // RIGHT BUTTON
 btnStateRight = digitalRead(buttonRtPin); // read state of button
 
 if (btnStateRight == HIGH) { // if button is pressed
 Keyboard.press(rightKey); 
 delay(10);
 lastClkRight = millis();
 delay(100); // allow game to respond to the click
 // respond to right turn input
 Keyboard.releaseAll(); //needed for every click!!!
 }


 
 // LEFT BUTTON
 btnStateLeft = digitalRead(buttonLftPin);
 if (btnStateLeft == HIGH) { // turn left
 Keyboard.press(leftKey);
 delay(10);
 lastClkLeft = millis();
 delay(100);
 Keyboard.releaseAll();
 }
 delay(10); // slow down sketch for easier viewing on screen
}
