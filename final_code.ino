//installing the required libraries
#include <AFMotor.h>
#include <DHT.h>
#include <SoftwareSerial.h>

#define DHTPIN A3
#define DHTTYPE DHT11

#define left A5
#define right A0

dht11 DHT11;

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

// Define the serial monitor for communication with the GSM module
#define GSM_RX 8
#define GSM_TX 7
SoftwareSerial gsmSerial(GSM_RX, GSM_TX);

String message = ""; // Message to be sent

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //declaring pin types
  pinMode(left, INPUT);
  pinMode(right, INPUT);

  Serial.begin(9600);
  gsmSerial.begin(9600); // Start communication with GSM module

  for (int i = 0; i < 4; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A1, INPUT);
  maximumMoistureLevel = analogRead(A2);
  delay(200);

  // Initialize DHT sensor
  dht.begin();
}

void loop() {

  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  Serial.println(digitalRead(right));

  //line detected by both
  if (digitalRead(left) == 1 && digitalRead(right) == 1) {
    //Forward movement
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
  }

  //line detected by left sensor
  else if (digitalRead(left) == 1 && !digitalRead(right) == 1) {
    //turn left
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
  }

  //line detected by right sensor
  else if (!digitalRead(left) == 1 && digitalRead(right) == 1) {
    //turn right
    motor1.run(FORWARD);
    motor1.setSpeed(200);
    motor2.run(FORWARD);
    motor2.setSpeed(200);
    motor3.run(FORWARD);
    motor3.setSpeed(200);
    motor4.run(FORWARD);
    motor4.setSpeed(200);
  }

  //line detected by none
  else if (!digitalRead(left) == 1 && !digitalRead(right) == 1) {
    //stop 
    stopAndSendMessage();
  }
}

void stopAndSendMessage() {

	// Check for incoming SMS
  if (gsmSerial.available() > 0) {
    String incomingMessage = gsmSerial.readString();
    incomingMessage.trim(); // Remove leading/trailing whitespaces

    // Check if the incoming message is "report 1"
    if (incomingMessage == "REPORT 1") {
      sendReport();
    }
    // Check if the incoming message is "report 2"
    else if (incomingMessage == "REPORT 2") {
      sendReport();
    }
  }
  

void sendReport() {
  // Read temperature and humidity from DHT sensor
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Prepare message
  message = "Hello there!!\n";
  message += "This message is from the plant health monitoring system.\n";
  message += "Here is the latest report on the conditions of your plants.\n\n";
  message += "Soil Moisture: Currently, the soil moisture levels are at " + String(map(currentMoistureLevel, 0, 1023, 0, 100)) + "%, indicating ";

  // Check soil moisture level
  if (currentMoistureLevel > 800) {
    message += "dry conditions for optimal growth.\n\n";
  } else if (currentMoistureLevel > 400) {
    message += "well-watered conditions for optimal growth.\n\n";
  } else {
    message += "appropriate conditions for optimal growth.\n\n";
  }

  // Check humidity level
  message += "Humidity: The humidity in the environment surrounding your plants is at " + String(humidity) + "%, creating ";

  if (humidity > 60) {
    message += "an ideal atmosphere for their well-being.\n\n";
  } else if (humidity > 40) {
    message += "a moderate atmosphere for their well-being.\n\n";
  } else {
    message += "a challenging atmosphere for their well-being.\n\n";
  }

  // Check temperature
  message += "Temperature: The temperature in your plant environment is currently at " + String(temperature) + "°C, which is within the ";

  if (temperature > 18 && temperature < 30) {
    message += "optimal range for healthy plant growth.\n\n";
  } else {
    message += "ideal range for healthy plant growth.\n\n";
  }

  message += "Overall, your plants are thriving in their current environment.";

  // Send data via SMS
  sendSMS(message);
}

void sendSMS(String text) {
  // AT command to set SIM900 to SMS mode
  gsmSerial.println("AT+CMGF=1");
  delay(1000);

  // The SMS text
  gsmSerial.print(text);
  delay(100);

  // End AT command with a Ctrl+Z
  gsmSerial.println((char)26); 
  delay(1000);

  gsmSerial.println();
  delay(10000); // Give module time to send SMS
}
