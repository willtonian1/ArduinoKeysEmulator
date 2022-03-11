// Tom Williams 2022

#include <Joystick.h>
#include "Keyboard.h" // library containing USB keyboard code

Joystick_ Joystick;

//buttons
const int buttonUPPin = 6; // turn right
const int buttonDOWNPin = 7; // turn left


//button press sortout
long lastClkUp = millis(); // for measuring times between clicks
 // - debouncing
 //millis measures the time between when your board last powered up, e.g on a click of a button
long lastClkDown = millis();

//states

int btnStateUP; // for checking the state of a pushButton
int btnStateDOWN;


//keys
char upKey = KEY_UP_ARROW;
char downKey = KEY_DOWN_ARROW;

//pot settings
int xVal = 0;
int potPin = A0;
double xAxis = 0;
float multiplier = 1.4;


void setup() {

   // make the pushButton pin an input:
 pinMode(buttonUPPin, INPUT);
 pinMode(buttonDOWNPin, INPUT);

 //joystick setup
  Joystick.setXAxisRange(-127, 127);
  Joystick.setYAxisRange(-127, 127);
  Joystick.begin();
   Keyboard.begin();
  Serial.begin(9600);
}

void loop() {

  // RIGHT BUTTON
  btnStateUP= digitalRead(buttonUPPin); // read state of button
  btnStateDOWN = digitalRead(buttonDOWNPin); // read state of button

 //UP BUTTON
 if (btnStateUP == HIGH) { // if button is pressed
 Keyboard.press(upKey); 
 delay(10);
 lastClkUp = millis();
 delay(100); // allow game to respond to the click
 // respond to right turn input
 Keyboard.releaseAll(); //needed for every click!!!
 }

 //down button 
  //UP BUTTON
 if (btnStateDOWN == HIGH) { // if button is pressed
 Keyboard.press(downKey); 
 delay(10);
 lastClkDown= millis();
 delay(100); // allow game to respond to the click
 // respond to right turn input
 Keyboard.releaseAll(); //needed for every click!!!
 }

  //POT readibgs
   xVal = analogRead(potPin);
   Serial.println(xVal);
   xAxis = (((0.24828934506 * xVal) - 127) * multiplier) * -1;
   
   
   Joystick.setXAxis(xAxis);
   Joystick.setYAxis(0);
   Joystick.sendState();
  Serial.println(xAxis);
}
