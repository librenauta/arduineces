/* Tutos leidos:
 *  https://store.arduino.cc/usa/arduino-nano
 *  https://create.arduino.cc/projecthub/Arduino_Genuino/getting-started-with-the-arduino-desktop-ide-623be4
 *  https://www.arduino.cc/en/Reference/Tone
 *  https://www.sparkfun.com/products/13959
 *  http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
 */

#define trigPin 2
#define echoPin 3
#define led LED_BUILTIN
#define led2 10

// the setup function runs once when you press reset or power the board
double seed=0;
double speed = 0.01;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(1000); - Removed this line
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
  digitalWrite(led2,LOW);
}
  else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
    noTone(10);
  }
  if (distance >= 70 || distance <= 5){
    Serial.println("Out of range: "+ distance);
    noTone(10);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    double freq = (sin(tan(seed/10)/10)+1)*distance*20;
    tone(10,freq);
    seed += speed;
  }
  delay(5);
} 
