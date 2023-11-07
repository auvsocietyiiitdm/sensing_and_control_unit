#ifndef SENSOR_INTERFACE_HPP
#define SENSOR_INTERFACE_HPP
#include <Arduino.h>
inline void initializeIMU();
inline void initializeDepthSensor();
inline void updateIMUReadings(int16_t& ax, int16_t& ay, int16_t& az, int16_t& gx, int16_t& gy, int16_t& gz, int16_t& mx, int16_t& my, int16_t& mz);
inline void updateDepthSensorReadings(float& depth);
#endif // SENSOR_INTERFACE_HPP