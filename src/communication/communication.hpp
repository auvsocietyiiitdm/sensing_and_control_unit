#ifndef SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#define SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP
#include "error.hpp"
#include "mat3x3.hpp"
#include "vec3.hpp"

namespace sensing_and_control_unit {
class Communication {
 private:
  /* data */
 public:
  Communication(/* args */);
  ~Communication();
  void initialize();

  float getDepthSensorOffset();
  Vec3f getAccelerometerOffsets();
  Vec3f getGyroscopeOffsets();
  Vec3f getMagnetometerSoftIronOffsets();
  Mat3x3f getMagnetometerHardIronOffsets();

  void sendOrientation(Vec3f orientation);
  void sendIMURawData(Vec3i accelerometer, Vec3i gyroscope, Vec3i magnetometer);
  void sendIMUData(Vec3f acceleration, Vec3f angular_velocity,
                   Vec3f magnetic_field);
  void sendDepthRawData(int depth);
  void sendDepth(float depth);

  void logMessage(const char *message, ErrorLevel error_level);
  void recieveCommands();
};
}  // namespace sensing_and_control_unit
#endif  // SENSING_AND_CONTROL_UNIT_SRC_COMMUNICATION_COMMUNICATION_HPP