#include "thruster_interface.hpp"
#include "config.hpp"

Servo g_thrusters[NUMBER_OF_THRUSTERS];
const uint8_t g_kPinMap[NUMBER_OF_THRUSTERS] = {PA0, PA1, PA2, PA3, PA6, PB0, PA7};

/**
 * @brief Initialize thrusters, set initial PWM for idle state.
 *
 * Attaches each thruster to its pin, sets PWM to INIT_THRUSTER_PWM (idle state),
 * readies thrusters for control without active propulsion.
 * 
 * @note Ensure that g_thrusters[] and g_kPinMap[] are configured.
 * 
 * @param None
 * @return None
 */

inline void initializeThrusters(){
  // Initializing the thrusters
  for (int thruster_index = 0; thruster_index < NUMBER_OF_THRUSTERS; thruster_index++){
    g_thrusters[thruster_index].attach(g_kPinMap[thruster_index]);
    g_thrusters[thruster_index].writeMicroseconds(INIT_THRUSTER_PWM);
  }
}

/**
 * @brief Set throttle for each thruster based on individual PWM values.
 *
 * Sets throttle for each thruster using provided PWM values.
 * PWM values determine thruster speed.
 *
 * @param pwm_values An array of int16_t values representing the PWM values for each thruster.
 *                   Array size should be equal to NUMBER_OF_THRUSTERS.
 *                   Each element corresponds to the PWM value for the respective thruster.
 * @return None
 */

inline void setThrusterThrottle(const int16_t pwm_values[]){
  int pwm_value;
  for (int thruster_index = 0; thruster_index < NUMBER_OF_THRUSTERS; thruster_index++){
    pwm_value = pwm_values[thruster_index];
    g_thrusters[thruster_index].writeMicroseconds(pwm_value);
  }
}

