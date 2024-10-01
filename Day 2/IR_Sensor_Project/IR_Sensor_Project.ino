#define SENSOR_PIN 18
void setup() {
Serial.begin(9600);                                       //This initializes the serial communication at a baud rate of 9600 bits per second.
pinMode(SENSOR_PIN, INPUT);               //sets SENSOR_PIN(pin 18) as input
}

void loop() {
int state = digitalRead(SENSOR_PIN);    //reads the value from SENSOR_PIN

  if (state == HIGH)
    Serial.println("The obstacle is NOT present");
  else
    Serial.println("The obstacle is present");

  delay(0);                                               //introduces a delay of 100 milliseconds between consecutive sensor readings 
}