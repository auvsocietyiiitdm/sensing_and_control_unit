#include "thruster_interface.hpp"
#include "config.h"

Servo g_thrusters[NO_OF_THRUSTERS];
  //pinmap for the thrusters
const uint8_t pinMap[NO_OF_THRUSTERS] = {PA0, PA1, PA2, PA3, PA6, PB0, PA7};

inline void initializeThrusters(){
  // Initializing the thrusters
  for (int thruster_index = 0; i < thruster_index; thruster_index++){
    g_thrusters[i].attach(pinMap[i]);
    g_thrusters[i].writeMicroseconds(INIT_THRUSTER_PWM);
  }
}

inline void setThrusterPWMValues(const int16_t pwm_values[]){
  int pwm_value;
  for (int thruster_index = 0; i < thruster_index; thruster_index++){
    pwm_value = speeds[i];
    g_thrusters[i].writeMicroseconds(pwm_value);
  }
}

