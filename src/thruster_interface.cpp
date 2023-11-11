#include "thruster_interface.hpp"
#include "config.hpp"

Servo g_thrusters[NUMBER_OF_THRUSTERS];
  //pinmap for the thrusters
const uint8_t pinMap[NUMBER_OF_THRUSTERS] = {PA0, PA1, PA2, PA3, PA6, PB0, PA7};

inline void initializeThrusters(){
  // Initializing the thrusters
  for (int thruster_index = 0; thruster_index < NUMBER_OF_THRUSTERS; thruster_index++){
    g_thrusters[thruster_index].attach(pinMap[thruster_index]);
    g_thrusters[thruster_index].writeMicroseconds(INIT_THRUSTER_PWM);
  }
}

inline void setThrusterPWMValues(const int16_t pwm_values[]){
  int pwm_value;
  for (int thruster_index = 0; thruster_index < NUMBER_OF_THRUSTERS; thruster_index++){
    pwm_value = pwm_values[thruster_index];
    g_thrusters[thruster_index].writeMicroseconds(pwm_value);
  }
}

