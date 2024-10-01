#define SOIL_MOISTURE_PIN 4  // Pin for soil moisture sensor

void setup() { 
    Serial.begin(9600);  // Start serial communication at 9600 baud
}

void loop() { 
    int moistureValue = analogRead(SOIL_MOISTURE_PIN);  // Read the moisture value
    Serial.print("Soil Moisture Value: ");  // Print label
    Serial.println(moistureValue);  // Print the moisture value

    // Determine moisture condition
    if (moistureValue == 4095) {
        Serial.println("Condition: Perfect Insulator");
    } else if (moistureValue == 0) {
        Serial.println("Condition: Perfect Conductor");
    } else {
        Serial.println("Condition: Intermediate");
    }

    delay(500);  // Wait for half a second before the next reading
}
