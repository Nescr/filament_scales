#include <EEPROM.h>
#include "GyverEncoder.h"
#include <Adafruit_GFX.h> 
#include <Adafruit_SSD1306.h> 
#include "HX711.h"

#include "GyverFilters.h"
GFilterRA analog0;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1); 

HX711 scale;

#define DT  6
#define SCK 5 

#define S1 4
#define S2 3
#define KEY 2

Encoder enc1(S1, S2, KEY);

float calibration_factor = -10.57;  // СЮДА ВПИСАТЬ ЗНАЧЕНИЕ ИЗ МОНИТОРА ПОРТА ПЕРВОГО КОДА!!!!!!!!!!!
float units;                      
float ounces;                      

int value;

bool state = 0;

unsigned long lastMillis = 0;
unsigned long currentMillis = 0;

void setup() 
{
  Serial.begin(9600);
  EEPROM.get(0, value);
  enc1.setType(TYPE2);
  display_init();
  delay(500);
  scale.begin(DT, SCK);
  scale.set_scale();
  scale.tare();
  scale.set_scale(calibration_factor);
  analog0.setCoef(0.30);
  analog0.setStep(50);
}

void loop() 
{
  while (!enc1.isClick())
  {
    currentMillis = millis();
    enc1.tick();
    disp_print_weight();
  }
  display.clearDisplay(); 
  display.setCursor(40, 20); 
  display.print(value);  
  display.display();
  while (!enc1.isClick())
  {
    enc1.tick();
    disp_print_bad_weight();
  }
  EEPROM.put(0, value);
}

void display_init()
{
  Serial.begin(9600); 
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) 
  {  
    Serial.println(F("SSD1306 allocation failed")); 
    for(;;); 
  } 
  display.display(); 
  delay(1000);
  display.clearDisplay(); 
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
}


void disp_print_bad_weight()
{
  enc1.tick();
  if (enc1.isRight()) 
  {
    value += 5;
    display.clearDisplay(); 
    display.setCursor(40, 20); 
    display.print(value);  
    display.display();
  }
  if (enc1.isLeft()) 
  {
    value -= 5;
    display.clearDisplay(); 
    display.setCursor(40, 20); 
    display.print(value);  
    display.display();
  }
}

void disp_print_weight()
{
  if (currentMillis - lastMillis >= 100) 
  {
    lastMillis = currentMillis;
    units = scale.get_units();
    units = units / 10;
    ounces = (units * 0.035274)*10;
    display.clearDisplay(); 
    display.setCursor(30, 25); 
    display.print(int(ounces) - value);  
    display.display();
  }
}
