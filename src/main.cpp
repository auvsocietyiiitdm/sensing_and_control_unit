#include "main.hpp"

int16_t ax, ay, az, gx, gy, gz, mx, my, mz;
float roll, pitch, yaw, depth;
int16_t current_mode = 0;
void setup() {
  initializeCommunication();
  initializeIMU();
  initializeDepthSensor();
  initializeSensorMath();
  initializeThrusters();
}

void loop() {
  switch (current_mode)
  {
  case NORMAL_MODE:
    updateIMUReadings(ax, ay, az, gx, gy, gz, mx, my, mz);
    updateDepthSensorReadings(depth);
    applyIMUCalibration(ax, ay, az, gx, gy, gz, mx, my, mz);
    applyDepthSensorCalibration(depth);
    updateOrientation(ax, ay, az, gx, gy, gz, mx, my, mz, roll, pitch, yaw);
    sendOrientation(roll, pitch, yaw);
    sendDepth(depth);
    break;
  
  case CALIBRATION_MODE:
    updateIMUReadings(ax, ay, az, gx, gy, gz, mx, my, mz);
    updateDepthSensorReadings(depth);
    sendIMUReadings(ax, ay, az, gx, gy, gz, mx, my, mz);
    sendDepth(depth);
    break;
  
  case CALIBRATION_UPDATE_MODE:
    updateCalibrationCoefficients();
    current_mode = NORMAL_MODE;
    break;

  }
  checkForCommands();
}
