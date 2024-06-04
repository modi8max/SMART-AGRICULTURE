#include<DHT.h>
#define POWER_PIN  7
#define SIGNAL_PIN A5
int value = 0; 
DHT dht11(9,DHT11);
int moisture = 0;
int sensor_pin = A4;
void setup() {
  pinMode(9,INPUT);
  Serial.begin(9600);
  pinMode(POWER_PIN, OUTPUT);   // configure D7 pin as an OUTPUT
  digitalWrite(POWER_PIN, LOW);
  pinMode(A0, INPUT);
   pinMode(6, OUTPUT);
   pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  // put your setup code here, to 
  pinMode(sensor_pin, INPUT);
}

void loop() {

  Serial.print("Temprature Sensor : ");
  Serial.println(dht11.readTemperature());
  Serial.print("Humidity Sensor : ");
  Serial.println(dht11.readHumidity());
  delay(1000);
  digitalWrite(POWER_PIN, HIGH);  // turn the sensor ON
  delay(10);                      // wait 10 milliseconds
  value = analogRead(SIGNAL_PIN); // read the analog value from sensor
  digitalWrite(POWER_PIN, LOW);   // turn the sensor OFF

  Serial.print("Sensor value: ");
  Serial.println(value);

  delay(1000);
  moisture = analogRead(A0);
    digitalWrite(6, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  if (moisture < 200) {
    digitalWrite(13, HIGH);
  } else {
    if (moisture < 400) {
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
    } else {
      if (moisture < 600) {
        digitalWrite(13, HIGH);
        digitalWrite(12, HIGH);
        digitalWrite(11, HIGH);
      } else {
        if (moisture < 800) {
          digitalWrite(13, HIGH);
          digitalWrite(12, HIGH);
          digitalWrite(11, HIGH);
          digitalWrite(10, HIGH);
        } 
        else {
          digitalWrite(13, HIGH);
          digitalWrite(12, HIGH);
          digitalWrite(11, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(9, HIGH);
          digitalWrite(6, HIGH);
        }
      }
    }
  }
  delay(100); // Wait for 100 millisecond(s)
  // put your main code here, to run repeatedly:
 int sensor_data = analogRead(sensor_pin);
  Serial.print("NEED WATER Sensor_data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");
    if((sensor_data>=1700)&&(sensor_data<=1800)){

   
     digitalWrite(13,HIGH);
   delay(100);
   digitalWrite(13,LOW);
   delay(100);
   digitalWrite(9,HIGH);
   delay(100);
   digitalWrite(9,LOW);
   delay(100);
   digitalWrite(10,HIGH);
   delay(100);
   digitalWrite(10,LOW);
   delay(100);
    Serial.print("NEED WATER");
    }
  
  if(sensor_data > 950)
  {
    Serial.println("No moisture, Soil is dry");
  }
  else if(sensor_data >= 400 && sensor_data <= 950)
  {
    Serial.println("There is some moisture, Soil is medium");
  }
  else if(sensor_data < 400)
  {
    Serial.println("Soil is wet");
    
  }

  delay(1000);
}
