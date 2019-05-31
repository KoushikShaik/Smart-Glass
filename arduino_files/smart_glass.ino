#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

String data;            //Variable for storing received data
void setup()
{
    Serial.begin(9600);   //Sets the baud for serial data transmission                                   
    display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.print("SMART GLASS          Initialized");
    
    display.display();
     delay(5000);
      display.clearDisplay();
      display.display();
    
}

void loop() {
  // put your main code here, to run repeatedly:
    
  if(Serial.available() > 0)      // Send data only when you receive data:
  {
      data = Serial.readString();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");         

      Serial.print("Sending to screen\n");
      delay(50);
      display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
      display.clearDisplay();
      display.setTextSize(3);
      display.setTextColor(WHITE);
      display.setCursor(25,10);
      
      display.print(data);
      display.display();
      Serial.print("Sent to screen\n");
      delay(15000);
      display.clearDisplay();
      display.display();
     
      
   }   
 
         
}
