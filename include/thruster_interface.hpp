#ifndef THRUSTER_INTERFACE_HPP
#define THRUSTER_INTERFACE_HPP
#include <Arduino.h>
#include <Servo.h> 
inline void initializeThrusters();
inline void setThrusterThrottle(const int16_t pwm_values[]);
#endif // THRUSTER_INTERFACE_HPP