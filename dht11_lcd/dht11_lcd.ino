//DHT11 Sensor:
#include "DHT.h"
#define DHTPIN 4     // pin to data connection
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);

//Libraries:
#include <Wire.h> // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>

// Set the LCD I2C address
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Temp and Humidity Sensor Test"); // printing in the port monitor
  dht.begin(); // excitation of DHT11 sensor working
}

void loop() {
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  // set the cursor to (0,0):
  lcd.setCursor(0, 0); // position setting for the temperature on the LCD display
  // print from 0 to 9:

   lcd.print("Temp: ");
   lcd.print(t);
   lcd.print("C");
  
  // set the cursor to (16,1): // position setting for the humidity on the LCD display
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  
  // printing values on the LCD display  
  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print("C, Humidity: ");
  Serial.print(h);
  Serial.println("%");

}

