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
  //Set joystick axis range
  Joystick.begin();
  Joystick.setXAxisRange(0, 1023);
  Joystick.setYAxisRange(360, 907);
  Joystick.setZAxisRange(307, 807);
  Joystick.setRxAxisRange(338, 825);
  //Define potantiometer
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600);

}
const int pinToButtonMap = 2;

// Last state of the button
int lastButtonState[5] = {0, 0, 0, 0, 0};
void loop() {
  // Axes are assigned to the potentiometer
  int pot1 = analogRead(A0);
  Joystick.setXAxis(pot1);

  int pot2 = analogRead(A1);
  Joystick.setYAxis(pot2);

  int pot3 = analogRead(A2);
  Joystick.setRxAxis(pot3);

  int pot4 = analogRead(A4);
  Joystick.setZAxis(pot4);
  Serial.println(pot4);

  for (int index = 0; index < 5; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
}
