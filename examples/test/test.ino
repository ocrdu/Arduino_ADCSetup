#include <ADCSetup.h>

unsigned int clockdivider = 128;
unsigned int cyclesPerSampleSetting = 0;
unsigned int vin = 0;
unsigned long int sampleStart = 0;
unsigned long int sampleEnd = 0;

void setup() {
  ADCsetup(clockdivider, cyclesPerSampleSetting);
  Serial.begin(115200);
  while (!Serial);
}

void loop() {
  sampleStart = micros();
  vin = analogRead(A2);
  sampleEnd = micros();
  Serial.print(vin); Serial.print(" => "); Serial.print(3.263 * vin / 4095, 3); Serial.print("V in ");
  Serial.print((sampleEnd - sampleStart)); Serial.println("μs");
  delay(1000);
}