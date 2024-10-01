#include <ESP32Servo.h>

// Define the pin for the servo
const int servoPin = 25;  // Note: Use a valid GPIO pin for ESP32

Servo myServo;

// Define the initial angle and step
int currentAngle = 0;
int step = 1;  // Small step for smooth movement
bool increasing = true;  // True for moving forward, false for moving back

void setup() {
  // Start serial communication with the specified baud rate
  Serial.begin(115200);
  
  // Attach the servo on the specified pin
  myServo.attach(servoPin);

  // Print a message to the serial monitor
  Serial.println("Servo initialized");
}

void loop() {
  // Write the current angle to the servo
  myServo.write(currentAngle);
  Serial.print("Servo position: ");
  Serial.print(currentAngle);
  Serial.println(" degrees");
  
  // Delay for smooth movement
  delay(20);  // 20ms delay between each step (adjustable for speed)

  // Update the angle based on the current direction
  if (increasing) {
    currentAngle += step;
    if (currentAngle >= 180) {  // When it reaches 180 degrees, reverse direction
      increasing = false;
      currentAngle = 180;  // Cap at 180 degrees
    }
  } else {
    currentAngle -= step;
    if (currentAngle <= 0) {  // When it reaches 0 degrees, start moving forward
      increasing = true;
      currentAngle = 0;  // Cap at 0 degrees
    }
  }
}
