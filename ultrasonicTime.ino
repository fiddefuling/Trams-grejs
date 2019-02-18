/*  
  The Circuit:
  * VCC connection of the sensor attached to +5V
  * GND connection of the sensor attached to GND
  * TRIG connection of the sensor attached to digital pin 11
  * ECHO connection of the sensor attached to digital pin 12
*/
const int TRIG_PIN = 11;
const int ECHO_PIN = 12;
unsigned long time;
float timeseconds;
long duration, distanceCm;
int calibratedDist=200;

void applyShortLowPulse() {
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);
}


float timeToDistance(int duration) {
    return duration / 29.1 / 2;
}


void setup() {
    // Initialize serial communication
    Serial.begin(9600);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
}


void loop() {
    applyShortLowPulse();
    duration = pulseIn(ECHO_PIN, HIGH);
    distanceCm = timeToDistance(duration);

    if (distanceCm <= calibratedDist) {
        Serial.print("Time: "); 
        time = millis();
        timeseconds = time/1000.0;

        Serial.print(timeseconds); 
        Serial.println(" seconds");
    }
    delay(20);
}
