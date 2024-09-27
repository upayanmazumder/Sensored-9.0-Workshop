# define LIGHT_SENSOR_PIN 34 //ESP32 pin GIOP36 (ADCO)

void setup() {
  // Initialise serial communication at 9600 bits per second
  Serial.begin(9600);
}

void loop() {
  // Reads the input on analog ping (value between 0 and 4095)
  int analogValue = analogRead(LIGHT_SENSOR_PIN);
  
  Serial.print("Analog Value = ");
  Serial.println(analogValue);
  // Qualitatively defined thresholds
  if (analogValue < 100) {
    Serial.println(" => dark ");
  } else if (analogValue < 200) {
    Serial.println(" => dim ");
  } else if (analogValue < 400) {
    Serial.println(" => light ");
  } else if (analogValue < 600) {
    Serial.println(" => bright ");
  }

  delay(500);
}