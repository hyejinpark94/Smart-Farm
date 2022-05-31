#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 2 /*-(Connect to Pin 2) -*/

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

int MoisensorPin = A0; //수분센서가 연결된 핀(AO)
//int motorPin = 3;
//int motorSpeed = 0;

//char buf[256];


void setup() {
  //pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
  
  //while(! Serial);
  //Serial.println("Speed 0 to 255");
  sensors.begin();
}

void loop() {

  int sensorValue_moi = analogRead(MoisensorPin);

  Serial.println();
  Serial.print("moisture = ");
  Serial.println(sensorValue_moi); //받은 데이터를 출력합니다
  delay(1000);
  
  Serial.print("temperature = ");
  sensors.requestTemperatures();
  //delay(1000);
  Serial.println(sensors.getTempCByIndex(0));
  delay(1000);

  //delay(1000);
  //sprintf(buf, "모터스피드 %d\n", motorSpeed);
  //Serial.print(buf);
  //analogWrite(motorPin,motorSpeed);
  
  /*if(Serial.available())
  {
    int speed = Serial.parseInt();
    if(speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin,speed);
    }
  }*/

}
