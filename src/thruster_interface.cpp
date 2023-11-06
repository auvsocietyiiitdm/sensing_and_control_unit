
#include "thruster_interface.hpp"
#include Servo.h
#define NO_OF_THRUSTERS=7;

  //declaring an array of servo objects for the thrusters
Servo thrusters[NO_OF_THRUSTERS];
  //pinmap for the thrusters
const uint8_t pinMap[NO_OF_THRUSTERS] = {PA0, PA1, PA2, PA3, PA6, PB0, PA7};

inline void initializeThrusters(){
  // Initializing the thrusters
  for (int i = 0; i < NO_OF_THRUSTERS; i++){
    thrusters[i].attach(pinMap[i]);
    thrusters[i].writeMicroseconds(1472);
  }
}
 //set speed for each thruster based on the vector input
inline void setThrusterSpeeds(std::vector<int16_t> speeds){
  for (int i = 0; i < NO_OF_THRUSTERS; i++){
    int pwm_value = speeds[i];
    thrusters[i].writeMicroseconds(pwm_value);
  }
}

