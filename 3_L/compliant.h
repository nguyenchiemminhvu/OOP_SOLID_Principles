#include <memory>

/**
 * @brief Compliant design #1
 * By introducing separate interfaces for the gyroscope and accelerometer data retrieval, the code adheres to the principle more closely.
 * The Gyroscope and Accelerometer classes now implement their specific data retrieval methods through the GyroscopeInterface and AccelerometerInterface interfaces, respectively.
 * This ensures that the specific behavior of each sensor is encapsulated within its own interface, 
 * and the InertialMeasurementUnit class can now rely on these interfaces to retrieve sensor data without needing to know the specific details of each sensor
 */
class SensorData
{
public:
    double dat_x;
    double dat_y;
    double dat_z;
};

// Interface for all types of gyroscope data
class GyroscopeInterface
{
public:
    virtual void getGyroscopeData(double& gyroX, double& gyroY, double& gyroZ) = 0;
};

// Interface for all types of accelerometer data
class AccelerometerInterface
{
public:
    virtual void getAccelerometerData(double& accelX, double& accelY, double& accelZ) = 0;
};

class InertialMeasurementUnit
{
public:
    virtual SensorData getSensorData() = 0;
};

class Gyroscope : public InertialMeasurementUnit, public GyroscopeInterface
{
public:
    virtual SensorData getSensorData() override
    {
        SensorData data;
        getGyroscopeData(data.dat_x, data.dat_y, data.dat_z);
        return data;
    }

    void getGyroscopeData(double& gyroX, double& gyroY, double& gyroZ) override
    {
        // Retrieve gyroscope data
    }
};

class Accelerometer : public InertialMeasurementUnit, public AccelerometerInterface
{
public:
    virtual SensorData getSensorData() override
    {
        SensorData data;
        getAccelerometerData(data.dat_x, data.dat_y, data.dat_z);
        return data;
    }

    void getAccelerometerData(double& accelX, double& accelY, double& accelZ) override
    {
        // Retrieve accelerometer data
    }
};

class DrEngine
{
public:
    DrEngine()
    {
        mGyro = new Gyroscope();
        mAccel = new Accelerometer();
    }

    void updatePosition()
    {
        SensorData gyro_data = mGyro->getSensorData();
        SensorData accel_data = mAccel->getSensorData();

        // calculate position based on sensor data
    }

private:
    InertialMeasurementUnit* mGyro;
    InertialMeasurementUnit* mAccel;
};