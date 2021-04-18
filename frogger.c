#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include "ReadSNES.h"

int gameMenu();
void initializeGame();

typedef struct Tile {
	int x;
	int y;
	bool platform;
	bool obstacle;
	bool leftDirection;
}

//Global variables
int score;
int extraLives;
int secondsRemaining;
int movesRemaining;
clock_t startTime;

int main(int argc, char **argv)
{
	//TODO: Check proper inputs??
	pthread_t mainThread
	pthread_attr_t attr;
	thread_attr_init(&attr);
    pthread_create(&mainThread, &attr, gameMenu, "1");
}

int gameMenu();
{
	
	//This is the main game menu that has start and quit
	//Will have some sort of background and maybe animation?
	//Loop while waiting on input
	bool start = false;
	bool quit = false;
	bool startHighlighted = true;
	while(start == false && quit == false)
	{
		int button = getButton()
		if(getButton == 6)	//Left
		{
			startHighlighted = true;
		}
		if(getButton == 7)	//Right
		{
			startHighlighted = false;
		}
		if(getButton == 3)	//Start
		{
			start = true;
		}
		if(getButton == 8)	//A
		{
			if(startHighlighted)
			{
				start = true;
			}
			else
			{
				quit = true;
			}
		}
	}

	if(start)
	{
		pthread_t gameThread
		pthread_attr_t attr;
		thread_attr_init(&attr);
		pthread_create(&gameThread, &attr, gamePlay, "1");
	}
	else
	{
		return 0
	}

	//IF left input then start is highlighted
	//IF right input then quit is highlighted

	//break when A is pressed or start is pressed
	//if start is highlighted or start is pressed return 1
	//else if quit is highlighted return 0
	//else throw error
}


void initializeGame()
{
	startTime = clock();
	score = 0;
	extraLives = 4;
	secondsRemaining = 999;
	movesRemaining = 200;
}

void drawPixel(GameState *theGame)
{
	memcpy(theGame->framebuffer->fptr, theGame->stage, 1280*720*2);
}

void gamePlay()
{
	initializeGame();
}



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




