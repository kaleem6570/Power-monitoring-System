const int sensorPin0 = 4; //battery // Analog pin the sensor is connected to
const int sensorPin1 = 13;//solar
const int sensorPin2= 2; //load
float voltage;//for battery
float voltage1;//for solar
float voltage2;// for load
float current;
float current1;
void setup() {
  Serial.begin(9600);
}

void loop() {
  
  int sensorValue1 = analogRead(sensorPin0);//battery
  int sensorValue = analogRead(sensorPin1);//solar
  int sensorValue2 =analogRead(sensorPin2);//load
  if(sensorValue1>=2500){
   voltage = sensorValue * (4.4 / 1023.0);//for battery
  }
  else{
     voltage = sensorValue * (5.0 / 1023.0);
  }
  voltage1 = sensorValue1 * (7.1 / 1023.0);// Convert ADC reading to voltage (assuming 7.1V reference)// for solar
  voltage2 = sensorValue2 * (7.1 / 1023.0);//for load
  current1 = abs((voltage2)-2.5/0.185); // for load
  float  battery_percentage = map(voltage1, 0, 12.8 , 0, 100);
  Serial.print("Battery Percentage = ");
  Serial.print( battery_percentage);
   Serial.println(" %");
   delay(5000);
   Serial.print("solar voltage: ");
   Serial.print(voltage);
   Serial.print("V");
   Serial.println(" ");
   delay(5000);
   Serial.print("Load Current: ");
  Serial.print(current1);
  Serial.print("A");
  Serial.println(" ");
  delay(5000);
}
