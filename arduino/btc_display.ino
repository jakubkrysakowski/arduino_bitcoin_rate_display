#include <SPI.h>
#include <Wire.h>

#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_DC 11  //OLED -- D/C
#define OLED_CS 12  //Not connect
#define OLED_CLK 10 //OLED -- SCL
#define OLED_MOSI 9 //OLED -- SDA
#define OLED_RESET 13//OLED -- RST
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);



void setup()   
{                
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect.
  }
  
  display.begin(SSD1306_SWITCHCAPVCC);  // Switch OLED
  display.clearDisplay();  // Clear OLED
  display.display(); // display OLED
  
  // text display tests
  display.setTextSize(1.2);
  display.setTextColor(WHITE);
  
  display.display(); // display OLED
}

void loop () 
{


  display.setCursor(0,30);
  if (Serial.available()) {
    display.clearDisplay();
    display.println("BTC/PLN: " + Serial.readString());
    display.display();
  }
  delay(1000);
}
