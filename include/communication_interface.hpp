#ifndef COMMUNICATION_INTERFACE_HPP
#define COMMUNICATION_INTERFACE_HPP
#include <Arduino.h>
inline void initializeCommunication();
inline void sendOrientation(float roll, float pitch, float yaw);
inline void sendDepth(float depth);
inline void sendIMUReadings(int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz, int16_t mx, int16_t my, int16_t mz);
inline void updateCalibrationCoefficients();
inline void checkForCommands();
#endif // COMMUNICATION_INTERFACE_HPP