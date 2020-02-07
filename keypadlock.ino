<<<<<<< HEAD
/*
 * Based on code found here: 
 * http://arduino-tutorials.eu/arduino-keypad-lock-tutorial
 */

#include <Keypad.h> // Include Keypad library by Mark Stanley
#include <Servo.h> // Include the Servo library

Servo servoblue; // The servo is called "servoblue" from now on
char* password = "123"; // The password.
int position = 0;
const byte ROWS = 4; // The keypad has 4 rows
const byte COLS = 3; // The keypad has 3 columns

// The characters on the keypad is defined here
char keys[ROWS][COLS] = {
  {'#', '0', '*'},
  {'9', '8', '7'},
  {'6', '5', '4'},
  {'3', '2', '1'}
};

// The connection with the Arduino
byte rowPins[ROWS] = {5, 6, 7, 8};
byte colPins[COLS] = {2, 3, 4};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int redLED = 12; //The red LED is connected to pin 12
int greenLED = 13; //The green LED is connected to pin 13

void setup()
{
  pinMode(redLED, OUTPUT); //The LEDs are defined as Output
  pinMode(greenLED, OUTPUT);
  servoblue.attach(11); //The servo is connected to pin 11
  setLocked(true);
}

void loop()
{
  char key = keypad.getKey();

  // Lock the door by pushing * or # on the keypad
  if (key == '*' || key == '#') {
    position = 0;
    setLocked(true);
  }

  // Check if the current key matches the password, at that position
  // If not, start again at 0
  if (key == password[position]) {
    position++;
  } else {
    position = 0;
    setLocked(true);
  }

  // If you made it to the 3rd position, you must have got the code right. Open!
  if (position == 3) {
    setLocked(false);
  }

  delay(100);
}

void setLocked(int locked) {
  if (locked) {
    digitalWrite(redLED, HIGH); //..the red LED should light up..
    digitalWrite(greenLED, LOW); //..the green LED not..
    servoblue.write(90); //and the servo should turn to a 90 degree position.
  } else {
    digitalWrite(redLED, LOW); //..the red LED should be off..
    digitalWrite(greenLED, HIGH); //..and the green LED should light up..
    servoblue.write(0); //..and the servo should turn to a 0 degree position.
  }
}
=======
/*
 * Based on code found here: 
 * http://arduino-tutorials.eu/arduino-keypad-lock-tutorial
 */

#include <Keypad.h> // Include Keypad library by Mark Stanley
#include <Servo.h> // Include the Servo library

Servo servoblue; // The servo is called "servoblue" from now on
char* password = "123"; // The password.
int position = 0;
const byte ROWS = 4; // The keypad has 4 rows
const byte COLS = 3; // The keypad has 3 columns

// The characters on the keypad is defined here
char keys[ROWS][COLS] = {
  {'#', '0', '*'},
  {'9', '8', '7'},
  {'6', '5', '4'},
  {'3', '2', '1'}
};

// The connection with the Arduino
byte rowPins[ROWS] = {5, 6, 7, 8};
byte colPins[COLS] = {2, 3, 4};

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

int redLED = 12; //The red LED is connected to pin 12
int greenLED = 13; //The green LED is connected to pin 13

void setup()
{
  pinMode(redLED, OUTPUT); //The LEDs are defined as Output
  pinMode(greenLED, OUTPUT);
  servoblue.attach(11); //The servo is connected to pin 11
  setLocked(true);
}

void loop()
{
  char key = keypad.getKey();

  // Lock the door by pushing * or # on the keypad
  if (key == '*' || key == '#') {
    position = 0;
    setLocked(true);
  }

  // Check if the current key matches the password, at that position
  // If not, start again at 0
  if (key == password[position]) {
    position++;
  } else {
    position = 0;
    setLocked(true);
  }

  // If you made it to the 3rd position, you must have got the code right. Open!
  if (position == 3) {
    setLocked(false);
  }

  delay(100);
}

void setLocked(int locked) {
  if (locked) {
    digitalWrite(redLED, HIGH); //..the red LED should light up..
    digitalWrite(greenLED, LOW); //..the green LED not..
    servoblue.write(90); //and the servo should turn to a 90 degree position.
  } else {
    digitalWrite(redLED, LOW); //..the red LED should be off..
    digitalWrite(greenLED, HIGH); //..and the green LED should light up..
    servoblue.write(0); //..and the servo should turn to a 0 degree position.
  }
}
>>>>>>> bdb0c1012cfddd45f367b26ce7d8e6b1ffc63e88
