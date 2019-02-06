/*
  The Circuit:
    * VCC connection of the sensor attached to +5V
    * GND connection of the sensor attached to GND
    * TRIG connection of the sensor attached to digital pin 12
    * ECHO connection of the sensor attached to digital pin 13
*/

const int TRIG_PIN = 12;
const int ECHO_PIN = 13;

void setup() {
    // Initialize serial communication
    Serial.begin(9600);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}


void loop() {
    long duration, distanceCm;

    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);

    // Convert the time into a distance
    distanceCm = duration /29.1 / 2;

    if (distanceCm <= 200) {
        Serial.println("Detected!");
    }
    delay(500);
}
