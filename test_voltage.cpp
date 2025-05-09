#define TRIG_PIN 2      // GPIO 2 connected to TRIG
#define ECHO_PIN 3      // GPIO 3 connected to ECHO
#define LED_PIN 13      // Built-in LED on the ESP32 or use another pin

long duration;
int distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // Send a pulse to trigger the HC-SR04
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the pulse duration from ECHO pin
  duration = pulseIn(ECHO_PIN, HIGH); // Time in microseconds
  
  // Calculate the distance (in cm) based on the pulse duration
  distance = duration * 0.0344 / 2;  // Speed of sound in air is 0.0344 cm/us
  
  // Approximate voltage based on pulse width
  float voltage = map(duration, 0, 100000, 0, 5);  // Mapping microseconds to voltage
  
  // Print the measured distance and calculated voltage
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Voltage: ");
  Serial.println(voltage);
  
  delay(1000);  // Wait for 1 second
}
