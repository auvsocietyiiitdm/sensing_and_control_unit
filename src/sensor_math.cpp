#include "sensor_math.hpp"
#include "Fusion/Fusion.h"
#include <math.h>
#include <time.h>
#include "MS5837.h"
MS5837 Depth_Sensor;

#define SAMPLE_RATE 10

FusionOffset offset;
FusionAhrs ahrs;

const FusionMatrix gyroscopeMisalignment = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
const FusionVector gyroscopeSensitivity = {1.0f, 1.0f, 1.0f};
const FusionVector gyroscopeOffset = {0.0f, 0.0f, 0.0f};
const FusionMatrix accelerometerMisalignment = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
const FusionVector accelerometerSensitivity = {1.0f, 1.0f, 1.0f};
const FusionVector accelerometerOffset = {0.0f, 0.0f, 0.0f};
const FusionMatrix softIronMatrix = {1.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 1.0f};
const FusionVector hardIronOffset = {0.0f, 0.0f, 0.0f};

inline void initializeSensorMath() 
{
    FusionOffsetInitialise(&offset, SAMPLE_RATE);
    FusionAhrsInitialise(&ahrs);

    const FusionAhrsSettings settings = {
            .convention = FusionConventionNwu,
            .gain = 0.5f,
            .gyroscopeRange = 2000.0f, 
            .accelerationRejection = 10.0f,
            .magneticRejection = 10.0f,
            .recoveryTriggerPeriod = 5 * SAMPLE_RATE, 
    }; 
    FusionAhrsSetSettings(&ahrs, &settings);
}


inline void applyIMUCalibration(float &ax, float &ay, float &az, float &gx, float &gy, float &gz, float &mx, float &my, float &mz) 
{
    const clock_t timestamp = clock();
    FusionVector gyroscope = {gx, gy, gz}; 
    FusionVector accelerometer = {ax, ay, az}; 
    FusionVector magnetometer = {mx, my, mz};
    
    gyroscope = FusionCalibrationInertial(gyroscope, gyroscopeMisalignment, gyroscopeSensitivity, gyroscopeOffset);
    accelerometer = FusionCalibrationInertial(accelerometer, accelerometerMisalignment, accelerometerSensitivity, accelerometerOffset);
    magnetometer = FusionCalibrationMagnetic(magnetometer, softIronMatrix, hardIronOffset);

    gyroscope = FusionOffsetUpdate(&offset, gyroscope);

    static clock_t previousTimestamp;
    const float deltaTime = (float) (timestamp - previousTimestamp) / (float) CLOCKS_PER_SEC;
    previousTimestamp = timestamp;

    FusionAhrsUpdate(&ahrs, gyroscope, accelerometer, magnetometer, deltaTime);
}

inline void applyDepthSensorCalibration(float& depth)
{
    depth=Depth_Sensor.depth();
}

inline void updateOrientation(float ax, float ay, float az, float gx, float gy, float gz, float mx, float my, float mz, float &roll, float &pitch, float &yaw)

{
    const FusionEuler rotation = FusionQuaternionToEuler(FusionAhrsGetQuaternion(&ahrs));
    const FusionVector translation = FusionAhrsGetEarthAcceleration(&ahrs);

    roll =rotation.angle.roll;
    pitch = rotation.angle.pitch;
    yaw = rotation.angle.yaw;

    ax=translation.axis.x;
    ay=translation.axis.y;
    az=translation.axis.z;
}
