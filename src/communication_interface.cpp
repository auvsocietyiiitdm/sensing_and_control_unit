 #include "communication_interface.hpp"
 #include <ros.h>
 #include <std_msgs/Int32MultiArray.h>
 #include <std_msgs/Float32MultiArray.h>
 #include <std_msgs/Float64.h>
 #include <std_msgs/Int16MultiArray.h>
//Publish data variables declaration
std_msgs::Float32MultiArray orientation_data;
std_msgs::Float64 depth_data;
std_msgs::Int16MultiArray imu_data;

void pwm_values_cb(const std_msgs::Int32MultiArray& pwm_values);
ros::NodeHandle nh;
ros::Subscriber <std_msgs::Int32MultiArray> sub("pwm_values", &pwm_values_cb);
ros::Publisher orientation_pub("orientation_data", &orientation_data);
ros::Publisher depth_pub("depth_data",&depth_data);
ros::Publisher imu_pub("imu_data",&imu_data);

inline void initializeCommunication() {
    // Initializing ROS
    nh.initNode();
    nh.subscribe(sub);
    nh.advertise(orientation_pub);
    nh.advertise(depth_pub);
    nh.advertise(imu_pub);

}

inline void sendOrientation(float roll, float pitch, float yaw) {
    float values[3] = {yaw, pitch, roll};
    orientation_data.data = values;
    orientation_data.data_length = 3;
    orientation_pub.publish(&orientation_data);

}

inline void sendDepth(float depth) {
    depth_data.data = depth;
    depth_pub.publish(&depth_data);
}

inline void sendIMUReadings(int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz, int16_t mx, int16_t my, int16_t mz) {
    short imu_values[9] = {ax, ay, az, gx, gy, gz, mx, my, mz};
    imu_data.data = imu_values;
    imu_data.data_length = 9;
    imu_pub.publish(&imu_data);
}

inline void updateCalibrationCoefficients() {
}
