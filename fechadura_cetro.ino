#include <Keypad.h> //INCLUSÃO DE BIBLIOTECA
#include <Ultrasonic.h>

#define TRIGGER_PIN  12
#define ECHO_PIN     11

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

#include <Servo.h>

Servo servo_Motor;
String password = "1234";
int position = 0;

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS] [COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };

byte colPins[COLS] = { 5, 4, 3, 2 };

Keypad keypad = Keypad (makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int ledvermelho = 12;
const int ledverde = 13;

bool abrir= false;

void setup() {
  Serial.begin(9600);
  pinMode(ledvermelho, OUTPUT);
  pinMode(ledverde, OUTPUT);

  servo_Motor.attach(10);
  setLocked(false);

  Serial.println("digite a senha");
}

void loop() {
  float cmMsec;
  long microsec = ultrasonic.timing();

  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  Serial.print("dist:");
  Serial.println(cmMsec);
  if (cmMsec < 10) {
   abrir = ! abrir;      
     setLocked(abrir);
   delay(1000);
  }



  char key = keypad.getKey();
  Serial.println(key);
  if (key == '*' || key == '#') {
    Serial.println(key);
    position = 0;
    setLocked(false);
  }
  if (key == password[position]) {
    position++;
  }
  //Serial.println(position);
  if (position == 4) {
    setLocked(true);

  }
  delay(100);

}

void setLocked(int locked) {
  abrir = locked;
  if (locked) {
    digitalWrite(ledvermelho, HIGH);
    digitalWrite(ledverde, LOW);
    servo_Motor.write(0);
    Serial.println("Abriu");
  }  else {
    digitalWrite(ledverde, HIGH);
    digitalWrite(ledvermelho, LOW);
    servo_Motor.write(400);
    Serial.println("fechou");
    
  }

}
