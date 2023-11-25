#ifndef SENSOR_MATH_HPP
#define SENSOR_MATH_HPP
#include <Arduino.h>


inline void initializeSensorMath();
inline void applyIMUCalibration(float &ax, float &ay, float &az, float &gx, float &gy, float &gz, float &mx, float &my, float &mz);
inline void applyDepthSensorCalibration(float &depth);
inline void updateOrientation(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz, float &roll, float &pitch, float &yaw);

#endif // SENSOR_MATH_HPP


