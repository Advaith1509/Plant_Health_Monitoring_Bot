// DHT11 sensor

#include <DHT.h>
#define DHTPIN 7 // what digital
  pin we're connected to
#define DHTTYPE DHT11  //DHT 11

// LCD display

#include
  <LiquidCrystal.h>;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

DHT dht (DHTPIN,
  DHTTYPE); //Initialize DHT sensor.


void setup() {
  // put your setup
  code here, to run once:


// Serial.begin(9600);
dht.begin();

}

void
  loop() {
 delay(10000); // Waiting time between measurements
 
float t
  = dht.readTemperature(); // Read temperature in *C (default)
float h = dht.readHumidity();
  // Read humidity %

float hic = dht.computeHeatIndex(t, h);


/*Serial.print("Temerature:
  ");
Serial.print(t);
Serial.print("*C\	");
Serial.print("Humidity:
  ");
Serial.print(h);
Serial.print("%\	");
Serial.print("Heat index:
  ");
Serial.println(hic);
*/



// LCD display

lcd.begin(16,
  2); // display diamensions
lcd.setCursor(0,0);
lcd.print("T=");
lcd.setCursor(2,0);
lcd.print(t);
lcd.setCursor(4,0);
lcd.print("*C
  ");
lcd.setCursor(0,1);
lcd.print("H=");
lcd.setCursor(2,1);
lcd.print(h);
lcd.setCursor(4,1);
lcd.print("%
  ");
lcd.setCursor(8,1);
lcd.print("HI=");
lcd.print(hic);

}