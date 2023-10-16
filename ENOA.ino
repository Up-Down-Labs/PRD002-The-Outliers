#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(0, 1); 

int ledPin1 = 11;// RED LED
int ledPin2 = 12;// YELLOW LED
int ledPin3 = 13;// GREEN LED

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);

  digitalWrite(ledPin1, HIGH); 

  bluetoothSerial.begin(9600);  
  Serial.begin(9600);  
}
void loop() {

  if (bluetoothSerial.available() > 0) {

    char command = bluetoothSerial.read();

    if (command == '1') { 

      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, HIGH);
      delay(1000);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, HIGH);

    } 
     else if (command == '0') { 
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin2, HIGH);
      delay(1000);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin1, HIGH);
     
    }

  }

}









