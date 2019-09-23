/*
  Simple Switch Example

  Connect the switch between GND and D2.
  The internal pull-up resistor on Pin 2 pulls it high when the switch is open.
  When the switch closes, the pin will go low.
*/

const int switchPin = 2;
const int ledPin = LED_BUILTIN;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int switchState = digitalRead(switchPin);
  Serial.println(switchState);
  digitalWrite(ledPin, switchState);
  delay(1);
}