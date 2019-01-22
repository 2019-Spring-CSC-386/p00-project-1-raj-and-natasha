/*  Natasha Stallsmith and Tirtha Subedi
    Prints soil moisture values to Serial Moniter
    Lights up red LED if soil is too dry and green LED if soil is still moist.

    Credits:
      Soil Moisture Basic Example by SparkFun Electronics, Joel Bartlett, August 31, 2015
      SparkFun Soil Moisture Sensor and Serial LCD example 1 By Sarah Al-Mutlaq 2015
    
*/

int soilMoisture = 0; //value for storing moisture value 
int soilPin = A0; //Declare a variable for the soil moisture sensor 
int soilPower = 7; //Variable for Soil moisture Power
int thresholdUp = 250; //Threshold for when the soil is moist versus dry, may need to be calibrated
int greenLED = 9; //Pin for output to Green LED
int redLED = 10; //Pin for output to Red LED

//Rather than powering the sensor through the 3.3V or 5V pins, 
//we'll use a digital pin to power the sensor. This will 
//prevent corrosion of the sensor as it sits in the soil. 

void setup() 
{
  Serial.begin(9600);   // open serial over USB

  pinMode(soilPower, OUTPUT); //Set power pin as an OUTPUT
  pinMode(redLED, OUTPUT); //Set redLED pin as OUTPUT
  pinMode(greenLED, OUTPUT); //Set greenLED pin as OUTPUT
  digitalWrite(soilPower, LOW); //Set to LOW so no power is flowing through the sensor
}

void loop() 
{
Serial.print("Soil Moisture = ");    
//get soil moisture value from the function below and print it
soilMoisture = readSoil();
Serial.print(soilMoisture);
if (soilMoisture <= threshold){ //if the soil moisture is low, turn off green LED and turn on red LED
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
}
else if (soilMoisture >= threshold){ //if the soil moisture is high, turn off red LED and turn on green LED
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED, LOW);
}

//This 1 second timeframe is used so you can test the sensor and see it change in real-time.
//For in-plant applications, you will want to take readings much less frequently.
delay(1000);//take a reading every second
}

//This is a function used to get the soil moisture content
int readSoil(){

    digitalWrite(soilPower, HIGH); //turn D7 "On"
    delay(10); //wait 10 milliseconds 
    soilMoisture = analogRead(soilPin); //Read the SIG value form sensor 
    digitalWrite(soilPower, LOW); //turn D7 "Off"
    return soilMoisture; //send current moisture value
}
