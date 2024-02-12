#include <stdexcept>

/**
 * @brief Non-compliant design #1
 * The larger interface, the less maintainable and reusable.
 */
class HardwareAdapterLayer
{
public:
    virtual void readViaI2C(char* buffer, int size) = 0;
    virtual void writeViaI2C(char* buffer, int size) = 0;

    virtual void readViaUART(char* buffer, int size) = 0;
    virtual void writeViaUART(char* buffer, int size) = 0;

    virtual void readViaSPI(char* buffer, int size) = 0;
    virtual void writeViaSPI(char* buffer, int size) = 0;

    virtual void setGpioPin(int pin) = 0;
    virtual void clearGpioPin(int pin) = 0;

    //...
};

class I2CManager : public HardwareAdapterLayer
{
public:
    void readViaI2C(char* buffer, int size) override
    {
        // Implement I2C read functionality
    }

    void writeViaI2C(char* buffer, int size) override
    {
        // Implement I2C write functionality
    }

    void readViaUART(char* buffer, int size) override
    {
        throw std::logic_error("Unsupported function for I2CManager: readViaUART");
    }

    void writeViaUART(char* buffer, int size) override
    {
        throw std::logic_error("Unsupported function for I2CManager: writeViaUART");
    }

    void readViaSPI(char* buffer, int size) override
    {
        throw std::logic_error("Unsupported function for I2CManager: readViaSPI");
    }

    void writeViaSPI(char* buffer, int size) override
    {
        throw std::logic_error("Unsupported function for I2CManager: writeViaSPI");
    }

    void setGpioPin(int pin) override
    {
        throw std::logic_error("Unsupported function for I2CManager: setGpioPin");
    }

    void clearGpioPin(int pin) override
    {
        throw std::logic_error("Unsupported function for I2CManager: clearGpioPin");
    }
};
