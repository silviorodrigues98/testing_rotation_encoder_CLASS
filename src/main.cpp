#include <Arduino.h>

#define ENCODER_PIN 4
volatile unsigned long int rotationCounter = 0;
volatile bool counterActivated = false;

void IRAM_ATTR isr()
{
    rotationCounter++;
    counterActivated = true;
}

void setup()
{
    Serial.begin(115200);
    Serial.println("Setup started...");
    pinMode(ENCODER_PIN, INPUT_PULLUP);
    attachInterrupt(
        digitalPinToInterrupt(ENCODER_PIN), isr,
        FALLING);
}

void loop()
{
    if(counterActivated)
    {
        Serial.println(rotationCounter);
        counterActivated = false;
    }
}