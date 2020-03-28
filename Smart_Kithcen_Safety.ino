#include <Servo.h>
#include <LiquidCrystal.h>

const int relay=8;
LiquidCrystal lcd(2,3,4,5,6,7);
//initializing pins for output
int buzzer=11;
int pos=25;
int servopin=10;
Servo mymotor;
//initializing pins for input
int sensor=A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
  mymotor.attach(servopin);
  pinMode(buzzer,OUTPUT);
  mymotor.write(pos);
  pinMode(relay,OUTPUT);

  digitalWrite(relay,HIGH);
}

void loop() {
  delay(1000);
  //taking gas density as input
  int sensorvalue=analogRead(sensor);
  Serial.println(sensorvalue);
  
 //checking if gas leakage has occured or not
  if(sensorvalue>400)
  {
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("LPG gas Detected");
  lcd.setCursor(0,1);
  lcd.print(sensorvalue);
  digitalWrite(buzzer,HIGH); 
  digitalWrite(relay,LOW);
  mymotor.write(150);
  }
  
  else if(sensorvalue<400)
  {
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("No LPG gas detected");
  lcd.setCursor(0,1);
  lcd.print(sensorvalue);
  digitalWrite(buzzer,LOW); 
  digitalWrite(relay,HIGH);
  mymotor.write(pos);
  }

}
