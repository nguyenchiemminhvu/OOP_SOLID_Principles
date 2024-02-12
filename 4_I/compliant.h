/**
 * @brief Compliant design #1
 * Split the large interface into many smaller interfaces
 */
namespace HardwareAdapterLayer
{
    class II2C
    {
    public:
        virtual void readViaI2C(char* buffer, int size) = 0;
        virtual void writeViaI2C(char* buffer, int size) = 0;
    };

    class IUART
    {
    public:
        virtual void readViaUART(char* buffer, int size) = 0;
        virtual void writeViaUART(char* buffer, int size) = 0;
    };

    class ISPI
    {
    public:
        virtual void readViaSPI(char* buffer, int size) = 0;
        virtual void writeViaSPI(char* buffer, int size) = 0;
    };

    class IGpio
    {
    public:
        virtual void setGpioPin(int pin) = 0;
        virtual void clearGpioPin(int pin) = 0;
    };
}

namespace HardwareAdapterLayer
{
    class I2C : public II2C
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
    };

    class UART : public IUART
    {
    public:
        void readViaUART(char* buffer, int size) override
        {
            // Implement UART read functionality
        }

        void writeViaUART(char* buffer, int size) override
        {
            // Implement UART write functionality
        }
    };

    class SPI : public ISPI
    {
    public:
        void readViaSPI(char* buffer, int size) override
        {
            // Implement SPI read functionality
        }

        void writeViaSPI(char* buffer, int size) override
        {
            // Implement SPI write functionality
        }
    };

    class Gpio : public IGpio
    {
    public:
        void setGpioPin(int pin) override
        {
            // Implement GPIO pin setting functionality
        }

        void clearGpioPin(int pin) override
        {
            // Implement GPIO pin clearing functionality
        }
    };
}
