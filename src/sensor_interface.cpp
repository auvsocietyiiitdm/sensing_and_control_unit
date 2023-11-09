#include "sensor_interface.hpp"

    MS5837 Depth_Sensor;
    Adafruit_FXOS8700 accelmag = Adafruit_FXOS8700(0x8700A, 0x8700B);
    Adafruit_FXAS21002C gyro = Adafruit_FXAS21002C(0x0021002C);

inline void initializeIMU() {

    Serial.begin(9600);

    /* Wait for the Serial Monitor */
    while (!Serial) {
    delay(1);
    }

    Serial.println("Gyroscope Test");
    Serial.println("");

    /* Initialise the sensor */
    if (!gyro.begin()) {
    Serial.println("No FXAS21002C detected ... Check your wiring!");
    while (1)
      ;
    }
    Serial.println("FXOS8700 Test");
    Serial.println("");

    if (!accelmag.begin()) {
    Serial.println("No FXOS8700 detected ... Check your wiring!");
    while (1)
      ;
    }
}

inline void initializeDepthSensor() {
    
    Serial.begin(9600);

    Serial.println("Starting");

    Wire.begin();

    while (!Depth_Sensor.init()) {
    Serial.println("Init failed!");
    Serial.println("Are SDA/SCL connected correctly?");
    Serial.println("Blue Robotics Bar30: White=SDA, Green=SCL");
    Serial.println("\n\n\n");

    delay(5000);
    }

    Depth_Sensor.setFluidDensity(997); // kg/m^3 (freshwater, 1029 for seawater)
        
}

inline void updateIMUReadings(int16_t& ax, int16_t& ay, int16_t& az, int16_t& gx, int16_t& gy, int16_t& gz, int16_t& mx, int16_t& my, int16_t& mz) {
    sensors_event_t aevent, mevent, gevent;

    accelmag.getEvent(&aevent, &mevent);
    gyro.getEvent(&gevent);

    ax = aevent.acceleration.x;
    ay = aevent.acceleration.y;
    az = aevent.acceleration.y;

    mx = mevent.magnetic.x;
    my = mevent.magnetic.y;
    mz = mevent.magnetic.z;

    gx = gevent.gyro.x;
    gy = gevent.gyro.y;
    gz = gevent.gyro.z;

    delay(50);
}

inline void updateDepthSensorReadings(int16_t& depth) {
    Depth_Sensor.read();
    depth = Depth_Sensor.depth();
    delay(50);
}

