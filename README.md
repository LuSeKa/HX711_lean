# HX711_light
A light Arduino library for interfacing with the HX711 load cell amplifier.

This library is meant for Arduino boards or projects with SRAM restrictions. 
It was tested with the Arduino Uno R3 and the Arduino Mega2560 R3. 
It might not work on boards with significantly faster CPUs, as these might violate the HX711's timing requirements.

The inner workings of this library are explained in this [blogpost](https://medium.com/@lukas.s.kaul/talking-to-a-chip-one-bit-at-a-time-a8726ccff8dc).
