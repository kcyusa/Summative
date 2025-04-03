#include <IRremote.h>  // IR remote library

// Define pins
const int IR_RECEIVER_PIN = 11;  // IR sensor OUT to Arduino Pin 11
const int RELAY_PIN = 3;         // Relay control pin (for bulb)

IRrecv irrecv(IR_RECEIVER_PIN);  // Create IR receiver object
decode_results results;          // Stores decoded IR signals

void setup() {
  Serial.begin(9600);            // Start serial communication
  irrecv.enableIRIn();           // Start IR receiver
  pinMode(RELAY_PIN, OUTPUT);    // Set relay as output
  digitalWrite(RELAY_PIN, LOW); // Initially OFF
  Serial.println("IR Remote Decoder Ready!");
}

void loop() {
   
  if (irrecv.decode(&results)) {  // If a signal is received
    Serial.print("Button HEX Code: 0x");
    Serial.println(results.value, HEX);  // Print HEX code

    // Example: Toggle relay when button "1" is pressed
    if (results.value != NULL) {// Replace with your button's HEX code
      digitalWrite(RELAY_PIN, !digitalRead(RELAY_PIN));  // Toggle relay
      Serial.println("Bulb Toggled!");
    }
    irrecv.resume();  // Prepare for next signal
  }
  delay(100);  // Small delay to stabilize
}