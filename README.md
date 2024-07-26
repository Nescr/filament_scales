# filament_scales

To assemble the device you will need:
1) Strain gauge 5 kilograms 
2) HX711
3) Arduino nano (or any other)
4) I2C oled display 128x64 0.96
5) encoder

assemble all the electronics according to the diagram provided in the "Электроника" folder


# If this is your first time picking up Arduino

1) download and install arduino ide from the official website: https://www.arduino.cc/en/software
2) download and install the ch340 driver: https://wch-ic.com/downloads/CH341SER_EXE.html
3) go to arduino ide and install the libraries

![Image alt](https://github.com/Nescr/image_for_readme/blob/main/photo_for_filament/Adafruit_SSD1306.png)
![Image alt](https://github.com/Nescr/image_for_readme/blob/main/photo_for_filament/GyverEncoder.png)
![Image alt](https://github.com/Nescr/image_for_readme/blob/main/photo_for_filament/HX711.png)


# Flashing arduino

1) Open the file "find_calibration_factor", find and enter in "float weight_of_standard = 950;" weight value (instead of 950), which you know exactly in grams
2) Upload the sketch with the corrected values, restart the device and wait 2 seconds, put on the strain gauge the weight you indicated in the previous paragraph. The calibration factor value will soon appear in the port monitor
3) Open the "working_prototype" file and paste the value obtained from the port monitor into line 23 of the code, then upload the new sketch to the arduino

Congratulations, if you did everything right, you should have succeeded!


# Инструкция на русском

Для сборки устройства вам понадобится:
1) Тензодатчик 5 кг 
2) HХ711
3) Ардуино нано (или любой другой)
4) I2C OLED-дисплей 128х64 0.96
5) энкодер

Соберите всю электронику по схеме, представленной в папке «Электроника"


# Если вы никогда не работали с ардуино

1) Cкачайте и установите arduino ide с официального сайта: https://www.arduino.cc/en/software
2) Cкачайте и утановите драйвер ch340: https://wch-ic.com/downloads/CH341SER_EXE.html
3) зайдите в arduino ide и установите библиотеки

![Image alt](https://github.com/Nescr/image_for_readme/blob/main/photo_for_filament/Adafruit_SSD1306.png)
![Image alt](https://github.com/Nescr/image_for_readme/blob/main/photo_for_filament/GyverEncoder.png)
![Image alt](https://github.com/Nescr/image_for_readme/blob/main/photo_for_filament/HX711.png)


# Перепрошивка Arduino

1) Откройте файл "find_calibration_factor", найдите и введите "float Weight_of_standard = 950;" значение веса (вместо 950), которое вы точно знаете в граммах
2) Загрузите скетч с исправленными значениями, перезагрузите прибор и подождите 2 секунды, поставьте на тензодатчик тот груз, который вы указали в предыдущем пункте. Значение калибровочного коэффициента вскоре появится в мониторе порта.
3) Откройте файл «working_prototype» и вставьте значение, полученное из монитора порта, в строку 23 кода, затем загрузите новый скетч в arduino.

Поздравляю, если вы всё сделано правильно, у вас должно было получиться!
