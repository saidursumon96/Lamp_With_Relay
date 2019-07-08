#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); //Pin10 RX , Pin 11 TX connected to--> Bluetooth TX,RX
#define Lamp1 2
#define Lamp2 3

//If Out to active Low change ON 0 and OFF 1
//If Out to active High change ON 1 and OFF 0
#define ON 1
#define OFF 0

char val;
String statusLamp1,statusLamp2;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(Lamp1,OUTPUT);digitalWrite (Lamp1,OFF);
  pinMode(Lamp2,OUTPUT);digitalWrite (Lamp2,OFF);

  mySerial.begin(9600);
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  //cek data serial from bluetooth android App
  
  if( mySerial.available() >0 ) {
        val = mySerial.read();
    Serial.println(val);
  }
  //Lamp is on
  if( val == '1' ) {
      digitalWrite(Lamp1,ON); statusLamp1="1"; 
      }
  else if( val == '2' ) {
      digitalWrite(Lamp2,ON); statusLamp2="2"; 
      }

  //Lamp is off
  else if( val == 'A' ) {
    digitalWrite(Lamp1,OFF); statusLamp1="A";
    }
  else if( val == 'B' ) {
    digitalWrite(Lamp2,OFF); statusLamp2="B"; 
}

  //synchronize Arduino to APK
  else if( val == 'S' ) {
  //send data to android apk
      delay(500);
      mySerial.println(statusLamp1+statusLamp2+"J"); //delay(500);
      val=' ';
  }
}
