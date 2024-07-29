#include "HX711.h"

HX711 scale;

#define DT  6
#define SCK 5

float weight_of_standard = 950;
float units = 0.035274;
float calibration_factor = 0;

void setup()
{
  Serial.begin(9600);
  scale.begin(DT, SCK);
  scale.set_scale();
  scale.tare();
  Serial.println("у вас есть 10 секунд чтобы положить то, чего вес вы знаете");
  delay(10000);
  Serial.print("calibration factor: ");
  calibration_factor = scale.get_units(10) / (weight_of_standard / units);
  Serial.println(calibration_factor);
}

void loop() 
{
}
