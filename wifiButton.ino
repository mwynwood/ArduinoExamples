/* Wifi Button for IFTTT
 * Using Wemos D1 Mini
 *
 * This code sets up a button that can trigger an event on IFTTT
 * You can set it up here: https://ifttt.com/
 *
 * Thanks to https://www.makeuseof.com/tag/wifi-connected-button-esp8266-tutorial/
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Settings
#define ssid ""
#define password ""
#define ifttt_key ""
#define ifttt_trigger ""

const int wakePin = D0; // Button goes from D0 to GND
const int ledPin = BUILTIN_LED;

void setup() {
  pinMode(ledPin, OUTPUT); // Set up LED for use
  digitalWrite(ledPin, HIGH); // Turns LED off

  Serial.begin(115200);
  while (!Serial) {
  }

  Serial.println("Button Pressed!");
  digitalWrite(ledPin, LOW); // Turns LED on
  connectToWifi(); // Connects to the WiFi
  call_ifttt(); // Sends trigger to IFTTT
  ESP.deepSleep(wakePin); // Puts device into a deep sleep, until the button is pressed again
}

void connectToWifi() {
  Serial.print("Connecting to: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  Serial.println("Attempting to connect: ");

  // Try to connect for 10 seconds
  int i = 10;
  while (WiFi.status() != WL_CONNECTED && i >= 0) {
    delay(1000);
    Serial.print(i + ", ");
    i--;
  }
  Serial.println(" ");

  // Print connection result
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected.");
    Serial.print("IP address: " + WiFi.localIP());
  }
  else {
    Serial.println("Connection failed - check your credentials or connection");
  }
}

void call_ifttt() {
  char url[255];
  strcpy(url, "http://maker.ifttt.com/trigger/");
  strcat(url, ifttt_trigger);
  strcat(url, "/with/key/");
  strcat(url, ifttt_key);
  HTTPClient http;
  http.begin(url);
  int httpCode = http.GET(); // Send the request
  String payload = http.getString(); // Get the response payload
  Serial.println(httpCode); // Print HTTP return code
  Serial.println(payload);    // Print request response payload
  http.end();  // Close connection
}

void loop() {
  // If deep sleep is working, this code will never run.
  Serial.println("This shouldn't get printed");
}