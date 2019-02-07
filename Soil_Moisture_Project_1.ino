/*  Natasha Stallsmith and Tirtha Subedi
    Prints soil moisture values to Serial Moniter.
    Lights up red LED if soil is too dry and green LED if soil is still moist.
    Opens valve for one second if soil is too dry.

    Credits:
      Soil Moisture Basic Example by SparkFun Electronics, Joel Bartlett, August 31, 2015
      SparkFun Soil Moisture Sensor and Serial LCD example 1 By Sarah Al-Mutlaq 2015
      Solenoid Valve Example Code Example, BCRobotics, https://www.bc-robotics.com/tutorials/controlling-a-solenoid-valve-with-arduino/ 
*/

int soilMoisture = 0; //value for storing moisture value 
int soilPin = A0; //soil moisture reading pin
int soilPower = 8; //Soil moisture Power
int threshold = 250; //Threshold for when the soil is moist versus dry
int greenLED = 9; //Pin for output to Green LED
int redLED = 10; //Pin for output to Red LED
int solenoidPin = 4;  //Output pin to solenoid

void setup() 
{
  Serial.begin(9600);   // open serial over USB

  pinMode(soilPower, OUTPUT); //Set power pin as an OUTPUT
  pinMode(solenoidPin, OUTPUT);  //Set "power" pin as OUTPUT
  pinMode(redLED, OUTPUT); //Set redLED pin as OUTPUT
  pinMode(greenLED, OUTPUT); //Set greenLED pin as OUTPUT
  digitalWrite(soilPower, LOW); //Set to LOW so no power is flowing through the sensor
}

void loop() 
{  
//get soil moisture value from the function below and print it
soilMoisture = readSoil();
Serial.print("Soil Moisture = "); 
Serial.print(soilMoisture); 
Serial.println();

if (soilMoisture <= threshold){ //if the soil moisture is low
  digitalWrite(redLED, HIGH); //turn on red LED
  digitalWrite(greenLED, LOW); //turn off green LED

  digitalWrite(solenoidPin, HIGH);    //Switch Solenoid ON
  delay(1000);                      //Wait 1 Second
  digitalWrite(solenoidPin, LOW);     //Switch Solenoid OFF
}
else if (soilMoisture >= threshold){ //if the soil moisture is high
  digitalWrite(greenLED, HIGH); //turn on green LED
  digitalWrite(redLED, LOW); //turn off red LED
}

//delay(1000); //Use this one second delay for testing, to see the system work in real-time
delay(1800000); //Use this half-hour delay for real life, in plant application
}

//This is the function used to get the soil moisture content
int readSoil(){

    digitalWrite(soilPower, HIGH); //turn on power to sensor
    delay(10); //wait 10 milliseconds 
    soilMoisture = analogRead(soilPin); //Read the SIG value form sensor 
    digitalWrite(soilPower, LOW); //turn off power to sensor
    return soilMoisture; //return current moisture value
}
