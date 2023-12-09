#include "main.hpp"
#include <Wire.h>

float ax, ay, az, gx, gy, gz, mx, my, mz, depth;

void setup() 
{
  Wire.setSDA(PB7);
  Wire.setSCL(PB6);
  Wire.begin();
  initializeCommunication();
  initializeIMU();
  initializeDepthSensor();
  initializeThrusters();
}

void loop() {
  updateIMUReadings(ax, ay, az, gx, gy, gz, mx, my, mz);
  updateDepthSensorReadings(depth);
  sendIMUReadings(ax, ay, az, gx, gy, gz, mx, my, mz);
  sendDepth(depth);
  checkForCommands();
}
