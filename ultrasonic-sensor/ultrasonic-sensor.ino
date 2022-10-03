/*
 * created by Rui Santos, https://randomnerdtutorials.com
 * 
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */

int trigPin = 11;  // Trigger
int echoPin = 12;  // Echo
long cm, inches;
float duration, time;
const int soundSpeed = 343;
float obstacleDistance;


void setup() {
  //Serial Port begin
  Serial.begin(9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  time = duration / 2000000;

  obstacleDistance = soundSpeed * time;
  Serial.print("obstacle distance in cm: ");
  Serial.print(obstacleDistance * 100);
  Serial.println();
  if (obstacleDistance < 20.00) {
    digitalWrite(8, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(3, LOW);
  } else if (obstacleDistance >= 20.00 && obstacleDistance <= 40.00) {
    digitalWrite(8, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(3, LOW);
  } else {
    digitalWrite(8, LOW);
    digitalWrite(6, LOW);
    digitalWrite(3, HIGH);
  }
  delay(1000);
}