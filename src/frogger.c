#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>

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


void initializeGame();
int *gameMenu(void *param);
void *playerInput(void *param);
void *gameState(void *param);
void update();
int collisionDetection();
bool checkExit();
void gamePlay();

struct Tile {
	int x;
	int y;
};

struct Object {
	int x;
	int y;
	bool isPlatform;
	int velocity;
};

struct Stage {
	bool isWater;
	struct Tile board[20][20];
	struct Object objects[10];

};
struct GameState {
	struct Stage stages[4];
};

struct GameState game;
struct Object frog;
//Global variables
int score;
int extraLives;
int secondsRemaining;
int movesRemaining;
clock_t startTime;

int currentStage;

int main(int argc, char **argv)
{
	//TODO: Check proper inputs??
	pthread_t mainThread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
    pthread_create(&mainThread, &attr, gameMenu, "1");
}

int *gameMenu(void *param)
{
	
	//This is the main game menu that has start and quit
	//Will have some sort of background and maybe animation?
	//Loop while waiting on input
	bool start = false;
	bool quit = false;
	bool startHighlighted = true;
	while(start == false && quit == false)
	{
		int button = getButton();
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
		pthread_t gameThread;
		pthread_attr_t attr;
		pthread_attr_init(&attr);
		pthread_create(&gameThread, &attr, gamePlay, "1");
	}
	else
	{
		return 0;
	}
}


void initializeGame()
{
	startTime = clock();
	score = 0;
	extraLives = 4;
	secondsRemaining = 999;
	movesRemaining = 200;

	currentStage = 0;

	frog.x = 10;
	frog.y = 0;

	for(int i = 0; i < 4; i++)
	{
		int temp = -1;
		for(int j = 0; j < 10; j++)
		{
			for(int a = 0; a < 20; a++)
			{
				for(int b = 0; b < 20; b++)
				{
					game.stages[i].board[a][b].x = b;
					game.stages[i].board[a][b].y = a;
				}
			}
			game.stages[i].objects[j].x = 0;
			game.stages[i].objects[j].y = j;
			game.stages[i].objects[j].velocity = temp;		//TODO: Might change object velocities later
		}
		temp = -temp;
		game.stages[i].isWater = i%2;
	}
}

// void drawPixel(GameState *theGame)
// {
// 	memcpy(theGame->framebuffer->fptr, theGame->stage, 1280*720*2);
// }

void gamePlay()
{
	initializeGame();

	//Create threads for player input and game state
	pthread_attr_t attr;

	pthread_t inputThread;
	pthread_attr_init(&attr);
    pthread_create(&inputThread, &attr, playerInput, "1");

	pthread_t gameStateThread;
	pthread_attr_init(&attr);
    pthread_create(&gameStateThread, &attr, gameState, "1");
}

void *playerInput(void *param)
{
	while(true)
	{
		int button = getButton();
		switch(button)
		{
			case 0:		//B
			case 1:		//Y
			case 2:		//Select
			case 3:		//Start
				//Pause game
			case 4:		//Up
				//Move frog up
				frog.y = frog.y + 1;
			case 5:		//Down
				frog.y = frog.y - 1;
			case 6:		//Left
				//Move frog left
				frog.x = frog.x - 1;
			case 7:		//Right
				//Move frog right
				frog.x = frog.x + 1;
			case 8:		//A
			case 9:		//X
			case 10:	//Left bumper
			case 11:	//Right bumper
		}
	
	}
}

void update()
{
	int collide = collisionDetection();
	if(collide != 0 && game.stages->isWater)
	{
		frog.x = frog.x + game.stages[currentStage].objects[collide].velocity;
	}

	for(int i = 0; i < 10; i++)
	{
		game.stages[currentStage].objects[collide].x = game.stages[currentStage].objects[collide].x + game.stages[currentStage].objects[collide].velocity;
	}
	if(frog.y >= 20)
	{
		currentStage = currentStage + 1;
	}

}

int collisionDetection()
{
	for(int i = 0; i < 10; i++)
	{
		if(game.stages[currentStage].objects[i].x == frog.x && game.stages[currentStage].objects[i].y == frog.y)
			return i;
	}
	return 0;
}

void *gameState(void *param)
{
	bool exit = false;
	while(exit == false)
	{
		update();
		//Clear screen
		//Draw
		exit = checkExit();
	}
}

bool checkExit()
{
	if(currentStage == 3 && frog.y >= 20)
	{
		//WIN
		return true;	
	}
	if(extraLives == 0 || movesRemaining == 0 || secondsRemaining == 0)
	{
		//LOSE
		return true;
	}
}