// Define the pins for IR sensors and LEDs
int irSensor1 = 2; // IR sensor 1 connected to pin 2
int irSensor2 = 3; // IR sensor 2 connected to pin 3
int led1 = 6;      // LED 1 connected to pin 6
int led2 = 7;      // LED 2 connected to pin 7
const int irSensor3 = 8;
const int irSensor4 = 9;
const int irSensor5 = 10;

int prevSensorVal3 = HIGH;
int prevSensorVal4 = HIGH;
int prevSensorVal5 = HIGH;

void setup() {
  // Set the IR sensor pins as inputs
   pinMode(irSensor3, INPUT);
  pinMode(irSensor4, INPUT);
  pinMode(irSensor5, INPUT);
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);

  // Set the LED pins as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  // Start the serial monitor
  Serial.begin(9600);
  Serial.println("Docking & Parking System Initialized...");
}

void loop() {

  // Read the state of both IR sensors
  int sensor1State = digitalRead(irSensor1);
  int sensor2State = digitalRead(irSensor2);
  int sensorVal3 = digitalRead(irSensor3);
  int sensorVal4 = digitalRead(irSensor4);
  int sensorVal5 = digitalRead(irSensor5);

  if (sensorVal3 != prevSensorVal3 ||  sensorVal4 != prevSensorVal4 || sensorVal5 != prevSensorVal5) {
      
    // Print slot status only if there's a change in any sensor
    Serial.println("Change detected in parking slots:");

    if (sensorVal3 == LOW) {
      Serial.println("Slot 1 occupied");
    } else {
      Serial.println("Slot 1 vacant");
    }

    if (sensorVal4 == LOW) {
      Serial.println("Slot 2 occupied");
    } else {
      Serial.println("Slot 2 vacant");
    }

    if (sensorVal5 == LOW) {
      Serial.println("Slot 3 occupied");
    } else {
      Serial.println("Slot 3 vacant");
    }

    prevSensorVal3 = sensorVal3;
    prevSensorVal4 = sensorVal4;
    prevSensorVal5 = sensorVal5;
  }

  // If IR sensor 1 detects an object, turn on LED 2
  if (sensor1State == LOW) { // LOW means object detected (depends on sensor type)
    digitalWrite(led2, HIGH); // Turn on LED 2
  } else {
    digitalWrite(led2, LOW); // Turn off LED 2
  }

  // If IR sensor 2 detects an object, turn on LED 1
  if (sensor2State == LOW) { // LOW means object detected (depends on sensor type)
    digitalWrite(led1, HIGH); // Turn on LED 1
  } else {
    digitalWrite(led1, LOW); // Turn off LED 1
  }

   delay(500);
}
