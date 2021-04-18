#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include "initGPIO.h"

#define GPSEL0 0
#define GPSET0 7
#define GPCLR0 10
#define GPLEV0 13

#define CLK 11
#define LAT 9
#define DAT 10

#define INP_GPIO(g,p) *(g+((p)/10)) &= ~(7<<(((p)%10)*3))
#define OUT_GPIO(g,p) *(g+((p)/10)) |= (1<<(((p)%10)*3))

void initGPIO(unsigned int *gpio)
{
    INP_GPIO(gpio, CLK);
    OUT_GPIO(gpio, CLK);
    INP_GPIO(gpio, LAT);
    OUT_GPIO(gpio, LAT);
}

void writeLatch(int bit, unsigned int *gpio) 
{
    if(bit == 0)
    {
        gpio[GPCLR0] = 1 << LAT;
    }
    else if(bit == 1)
    {
        gpio[GPSET0] = 1 << LAT;
    }
}
void writeClock(int bit, unsigned int *gpio)
{
    if(bit == 0)
    {
        gpio[GPCLR0] = 1 << CLK;
    }
    else if(bit == 1)
    {
        gpio[GPSET0] = 1 << CLK;
    }
}
int readData(unsigned int *gpio)
{
    return (gpio[GPLEV0] >> 10) & 1;
}

int readSNES(unsigned int *gpio)
{
    while(true)
    {
        int counter = 0;
        while(counter < 16)
        {
                delayMicroseconds(6);
                writeClock(0, gpio);
                delayMicroseconds(6);
                int value = readData(gpio);
                if(value == 0)
                {
                        return counter;
                }
                gpio[GPSET0] = 1 << 11;

                counter++;
        }
    }
}

int getButton()
{
        unsigned int *gpioPtr = getGPIOPtr();
        initGPIO(gpioPtr);
        writeLatch(1, gpioPtr);
        delayMicroseconds(12);
        writeLatch(0, gpioPtr);
        int button;
        while(true)
        {
            printf("Please press a button\n");
            button = readSNES(gpioPtr);
            return button;
        }
}




