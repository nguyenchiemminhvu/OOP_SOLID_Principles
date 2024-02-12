/**
 * @brief Non-compliant design #1
 * both Gyroscope and Accelerometer implement the getSensorData() method as required by the InertialMeasurementUnit interface, but they return completely different types of data. 
 * This violates the Liskov substitution principle because the client code cannot rely on consistent behavior 
 * when calling getSensorData() on different subclasses of InertialMeasurementUnit.
 */
struct SensorData
{
    // Accelerometer data
    float accelX;
    float accelY;
    float accelZ;

    // Gyroscope data
    float gyroX;
    float gyroY;
    float gyroZ;
};

class InertialMeasurementUnit
{
public:
    virtual SensorData getSensorData() = 0;
};

class Gyroscope : public InertialMeasurementUnit
{
public:
    virtual SensorData getSensorData()
    {
        SensorData data;
        // fill gyro x y z data

        return data;
    }
};

class Accelerometer : public InertialMeasurementUnit
{
public:
    virtual SensorData getSensorData()
    {
        SensorData data;
        // fill accel x y z data

        return data;
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
        SensorData gyro_data = mGyro->getSensorData(); // accel x y z is undefined
        SensorData accel_data = mAccel->getSensorData(); // gyro x y z is undefined

        // calculate position based on sensor data
    }

private:
    InertialMeasurementUnit* mGyro;
    InertialMeasurementUnit* mAccel;
};