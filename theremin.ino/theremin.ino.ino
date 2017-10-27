/* Tutos leidos:
 *  https://store.arduino.cc/usa/arduino-nano
 *  https://create.arduino.cc/projecthub/Arduino_Genuino/getting-started-with-the-arduino-desktop-ide-623be4
 *  https://www.arduino.cc/en/Reference/Tone
 *  https://www.sparkfun.com/products/13959
 *  http://www.instructables.com/id/Simple-Arduino-and-HC-SR04-Example/
 *  https://openwebinars.net/blog/tutorial-de-arduino-sonidos-con-arduino/
 */
#define trigPin 2
#define echoPin 3
#define led LED_BUILTIN 
#define led2 10

/* declaración de variables */

int spk=13;                                           // altavoz a GND y pin 13
int c[5]={131,262,523,1046,2093};       // frecuencias 4 octavas de Do
int cs[5]={139,277,554,1108,2217};      // Do#
int d[5]={147,294,587,1175,2349};       // Re
int ds[5]={156,311,622,1244,2489};    // Re#
int e[5]={165,330,659,1319,2637};      // Mi
int f[5]={175,349,698,1397,2794};       // Fa
int fs[5]={185,370,740,1480,2960};     // Fa#
int g[5]={196,392,784,1568,3136};     // Sol
int gs[5]={208,415,831,1661,3322};   // Sol#
int a[5]={220,440,880,1760,3520};      // La
int as[5]={233,466,932,1866,3729};    // La#
int b[5]={247,494,988,1976,3951};      // Si
// todas las notas con sus direferentes octavas 
double seed= 0;
double speed = 0.01;

void nota(int a, int b);            // declaración de la función auxiliar. Recibe dos números enteros

void setup() {  

  
pinMode(LED_BUILTIN, OUTPUT); // le da output al ledpin
Serial.begin(9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led2, OUTPUT);

}
void nota(int frec, int t)
{
    tone(spk,frec);      // suena la nota frec recibida
    delay(t);                // para despues de un tiempo t
}

void loop() {

  long duration, distance;
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance); 
  delay(1);

 if ((distance >= 5)&&(distance <= 10)) {  // This is where the LED On/Off happens

      nota(c[1],80);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 10)&&(distance <= 15)) {  // This is where the LED On/Off happens

      nota(cs[1],80);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 15)&&(distance <= 20)) {  // This is where the LED On/Off happens

      nota(d[1],80);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 20)&&(distance <= 25)) {  // This is where the LED On/Off happens

      nota(ds[1],80);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 25)&&(distance <= 30)) {  // This is where the LED On/Off happens

      nota(e[1],80);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 30)&&(distance <= 35)) {  // This is where the LED On/Off happens

      nota(f[1],80);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 35)&&(distance <= 40)) {  // This is where the LED On/Off happens

      nota(fs[1],50);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 40)&&(distance <= 45)) {  // This is where the LED On/Off happens

      nota(g[1],50);noTone(spk);delay(0);    //un tono
      }   
 if ((distance >= 45)&&(distance <= 50)) {  // This is where the LED On/Off happens

      nota(gs[1],50);noTone(spk);delay(0);    //un tono
      }  
 if ((distance >= 45)&&(distance <= 50)) {  // This is where the LED On/Off happens

      nota(a[1],50);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 50)&&(distance <= 55)) {  // This is where the LED On/Off happens

      nota(as[1],50);noTone(spk);delay(0);    //un tono
      }
 if ((distance >= 55)&&(distance <= 60)) {  // This is where the LED On/Off happens

      nota(b[1],50);noTone(spk);delay(0);    //un tono
      }

}




