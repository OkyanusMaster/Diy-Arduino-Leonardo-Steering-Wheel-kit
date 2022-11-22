//Include Joystick library
#include <Joystick.h>

// Create Joystick
Joystick_ Joystick;

void setup() {
  //define buttons
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);

  //Set joystick axis range
  Joystick.begin();
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(0, 1023);
  Joystick.setZAxisRange(0, 1023);
  Joystick.setRxAxisRange(0, 1023);
  Joystick.setRzAxisRange(0, 1023);
  //Define potantiometer
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600);
}
const int pinToButtonMap = 2;

// Last state of the button
int lastButtonState[5] = { 0, 0, 0, 0, 0 };
void loop() {
  // Axes are assigned to the potentiometer
  int pot1 = analogRead(A0);
  Joystick.setXAxis(pot1);

  int pot2 = analogRead(A1);
  Joystick.setYAxis(pot2);

  int pot3 = analogRead(A2);
  Joystick.setRxAxis(pot3);

  int pot4 = analogRead(A3);
  Joystick.setZAxis(pot4);

  int pot5 = analogRead(A4);
  Joystick.setRzAxis(pot5);

  for (int index = 0; index < 7; index++) {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index]) {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
}
