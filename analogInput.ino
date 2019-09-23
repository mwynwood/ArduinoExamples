/*
 Analog Input

 This example reads data from an analog input and
 expresses the value as a number between 0 and 100.

 You could connect a potentiometer (Center leg to A0, one side to 5v, other side to GND)
 You could connect a moisture sensor
 You could connect a photoresistor (5v to Leg 1 of photoresistor, Leg 2 of photoresistor to A0, Leg 2 of photoresistor to Leg 1 of 10k resistor, Leg 2 of 10k resistor to GND)
 You could connect... pretty much any analog input device.
*/

int ledPin = LED_BUILTIN;

void setup() {
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
}

void loop() {
  int outputValue = map(analogRead(A0), 0, 1023, 0, 100);
  Serial.println(outputValue);

  if (outputValue > 50) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(500);
}