#ifndef SENSOR_INTERFACE_HPP
#define SENSOR_INTERFACE_HPP
#include <Arduino.h>
inline void initializeIMU();
inline void initializeDepthSensor();
inline void updateIMUReadings(float &ax, float &ay, float &az, float &gx, float &gy, float &gz, float &mx, float &my, float &mz);
inline void updateDepthSensorReadings(float &depth);
#endif // SENSOR_INTERFACE_HPP