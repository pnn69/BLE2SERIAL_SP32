/*
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */

#include <Arduino.h>
#include "BluetoothSerial.h"

// Set LED_BUILTIN if it is not defined by Arduino framework
#ifndef LED_BUILTIN
#define LED_BUILTIN 2
#endif

BluetoothSerial SerialBT;
String buffer;

void setup()
{
    Serial.begin(115200);
    Serial.println("\r\nHelo world!\r\n");
    // initialize LED digital pin as an output.
    pinMode(LED_BUILTIN, OUTPUT);
    SerialBT.begin("ESP32test"); // Bluetooth device name
    Serial.println("\nThe device started, now you can pair it with bluetooth!");
}

void loop()
{
    // turn the LED on (HIGH is the voltage level)
    digitalWrite(LED_BUILTIN, HIGH);
    // wait for a second
    delay(1);
    // turn the LED off by making the voltage LOW
    digitalWrite(LED_BUILTIN, LOW);
    // wait for a second
    delay(1);
    if (Serial.available())
    {
        SerialBT.write(Serial.read());
    }
    if (SerialBT.available())
    {
        Serial.write(SerialBT.read());
    }
}