int greenLight = 0; //Defining pins
int yellowLight = 1;
int redLight   = 2;
int piezoBuzzer = 3;
int maximumMoistureLevel; //The max moisture level   and current moisture levels will be needed for percentage calculations
int currentMoistureLevel;//Like   so: current/max*100 = Moisture level as a percentage

void moistureDetection(){   //Create a function for all the long code, to keep the loop free
  if(currentMoistureLevel/maximumMoistureLevel   <= 0.1){ //If the moisture is below 10%
    digitalWrite(greenLight, LOW);
     digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, HIGH); //Switch   on red light, and sound the buzzer
    tone(piezoBuzzer, 5000, 500);

    delay(2000);

   }else if (currentMoistureLevel/maximumMoistureLevel <= 0.3 && currentMoistureLevel/maximumMoistureLevel   > 0.1)
  {//if the moisture level is in between 10 and 30%
    digitalWrite(greenLight,   LOW);
    digitalWrite(yellowLight, LOW);
    digitalWrite(redLight, HIGH);   //Switch red light on, but don't sound the buzzer
  }
  else if (currentMoistureLevel/maximumMoistureLevel   <= 0.6 && currentMoistureLevel/maximumMoistureLevel > 0.3)
  {//if the moisture   level is in between 30 and 60%
    digitalWrite(greenLight, LOW);
    digitalWrite(yellowLight,   HIGH);//Just switch yellow light on
    digitalWrite(redLight, LOW);
  } 
  else   //Otherwise the moisture level is above 60%, and therefore it's good enough
  {
    digitalWrite(greenLight, HIGH);//Switch green light on
    digitalWrite(yellowLight,   LOW);
    digitalWrite(redLight, LOW);
  }
}

void setup() {
   for (int i = 0; i < 4; i++)//Use a for loop, to not have to initiate all the pins   by hand
  {
    pinMode(i, OUTPUT);
  }
  pinMode (A0, INPUT); //A0   is the pin used for the Soil Moisture Sensor
  maximumMoistureLevel = analogRead(A0);
   tone(piezoBuzzer, 5000, 500);
  delay(200);
  tone(piezoBuzzer, 6000, 500);//Make   a sound to show that the program has been initiated.
  delay(600);
}

void   loop() {
  currentMoistureLevel = analogRead(A0); //Keep renewing the readings   for the current moisture level
  moistureDetection();
  delay(100); //Short   delay to not overload the program
  Serial.println(currentMoistureLevel);//Just   so you can see the moisture level as a reading between 0-1023
  
  
}