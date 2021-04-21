#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
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

//Initialized GPIO lines
void initializeGPIO(unsigned int *gpio)
{
	INP_GPIO(gpio, CLK);
	OUT_GPIO(gpio, CLK);
	INP_GPIO(gpio, LAT);
	OUT_GPIO(gpio, LAT);
	INP_GPIO(gpio, DAT);
}

//Function for writing to latch
void writeLatch(int bit, unsigned int *gpio)
{
	if(bit == 0)
    	{
       		gpio[GPCLR0] = 1 << LAT;	//Sets latch bit to 0
    	}
    	else if(bit == 1)
    	{
        	gpio[GPSET0] = 1 << LAT;	//Sets latch bit to 1
    	}
}

//Function for writing to clock
void writeClock(int bit, unsigned int *gpio)
{
    	if(bit == 0)
    	{
        	gpio[GPCLR0] = 1 << CLK;	//Sets clock bit to 0
    	}
    	else if(bit == 1)
    	{
        	gpio[GPSET0] = 1 << CLK;	//Sets clock bit to 1
    	}
}

//Function for reading from data line
int readData(unsigned int *gpio)
{
    	return (gpio[GPLEV0] >> DAT) & 1;	//Reads bit from data line
}

//Function for printing which buttons are pressed
void printMessage(unsigned short code)
{
	//2D char array for names of each button pushed, max size 13 based on string size
	char buttonB[13] = "B";
	char buttonY[13] = "Y";
	char buttonSelect[13] = "Select";
	char buttonStart[13] = "Start";
	char buttonJpUp[13] = "Joy-pad UP";
	char buttonJpDown[13] = "Joy-pad DOWN";
	char buttonJpLeft[13] = "Joy-pad LEFT";
	char buttonJpRight[13] = "Joy-pad RIGHT";
	char buttonA[13] = "A";
	char buttonX[13] = "X";
	char buttonLeft[13] = "Left";
	char buttonRight[13] = "Right";

	char* buttonList[12] = {buttonB, buttonY, buttonSelect, buttonStart, buttonJpUp, buttonJpDown, buttonJpLeft, buttonJpRight, buttonA, buttonX, buttonLeft, buttonRight};
  	printf("You have pressed %s\n", buttonList[code]);
}

//Function to read SNES buttons pushed
unsigned short readSNES(unsigned int *gpio)
{
	unsigned short buttons = 0b1111111111111111;	//Initialized variable for buttons pushed
   	while(buttons == 0b1111111111111111)		//While loop while buttons aren't pushed
    	{
        	int counter = 0;	//Counter

		writeClock(1, gpio);		//Setup of SNES lines
		writeLatch(1, gpio);
		delayMicroseconds(12);
		writeLatch(0, gpio);

        	while(counter < 16)	//Loop to iterate through data line
        	{
                	delayMicroseconds(6);
                	writeClock(0, gpio);
                	delayMicroseconds(6);
                	int value = readData(gpio);	//Gets data line bit value
                	if(value == 0)
                	{
				//Adds bit to buttons pushed variable
                        	unsigned short temp = ~(1 << counter);
				buttons &= temp;
                	}
                	writeClock(1, gpio);	//Writes 1 to clock

          	      	counter++;	//Iterates counter
        	}
    	}
	return buttons;
}

//Get button function
int getButton(unsigned int *gpio)
{
	//printf("Created by Nathanael Huh\n");
    initializeGPIO(gpio);
	unsigned short button;
	while(1)	//Loops until start is pushed
	{
		printf("Please press a button\n");
		unsigned short code = readSNES(gpio);	//Gets series of bits for buttons pushed
		for(int i = 0; i < 12; i++)	//Iterates through bits sent from readSNES
		{
			int value = (code >> i) & 1;	//Gets bit of in i position
			if(value == 0)	//If button is pushed
			{
				button = i;	//Sets button pushed to index for printing
                printMessage(button);	//Prints button pushed
                return button;
			}
		}
	}
}


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
	int score;
	int extraLives;
	int secondsRemaining;
	int movesRemaining;
	clock_t startTime;
	bool gameOver;
	
	struct Object frog;
};
void gameMenu();
void gameState();
void initializeGame();
void update();
int collisionDetection();
bool checkExit();
void *playerInput(void *params);
void gamePlay();
void *counter(void *params);

struct GameState game;
int currentStage;
bool gameStart, paused;

int main(int argc, char **argv)
{
	printf("\nMain");
	printf("\nGame menu");
    gameStart = false;
	paused = false;

	pthread_t inputThread;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int tc = pthread_create(&inputThread, &attr, playerInput, "1");
	if(tc)
	{
		printf("ERROR creating thread, %d\n", tc);
		exit(-1);
	}
	gamePlay();
}

void *playerInput(void *params)
{
	unsigned int *gpioPtr = getGPIOPtr();
	initializeGPIO(gpioPtr);
	unsigned short button;
	bool quit = false;
	bool startHighlighted = true;
	//LOOP for menu selection
	while(!quit)
	{
		while(!gameStart)
		{
			printf("Please press a button\n");
			unsigned short code = readSNES(gpioPtr);	//Gets series of bits for buttons pushed
			for(int i = 0; i < 12; i++)	//Iterates through bits sent from readSNES
			{
				int value = (code >> i) & 1;	//Gets bit of in i position
				if(value == 0)	//If button is pushed
				{
					button = i;	//Sets button pushed to index for printing
					printMessage(button);	//Prints button pushed
					if(button == 6)	//Left
					{
						startHighlighted = true;
					}
					if(button == 7)	//Right
					{
						startHighlighted = false;
					}
					if(button == 3)	//Start
					{
						gameStart = true;
					}
					if(button == 8)	//A
					{
						if(startHighlighted)
						{
							gameStart = true;
						}
						else
						{
							quit = true;
						}
					}
				}
			}
			delayMicroseconds(1000000);
		}
		while(gameStart && !paused)
		{
			printf("Please press a button\n");
			unsigned short code = readSNES(gpioPtr);	//Gets series of bits for buttons pushed
			for(int i = 0; i < 12; i++)	//Iterates through bits sent from readSNES
			{
				int value = (code >> i) & 1;	//Gets bit of in i position
				if(value == 0)	//If button is pushed
				{
					button = i;	//Sets button pushed to index for printing
					printMessage(button);	//Prints button pushed
					switch(button)
					{
						case 3:		//Start
							//Pause game
							paused = true;
							break;
						case 4:		//Up
							//Move frog up
							printf("\nFrog going up");
							game.frog.y = game.frog.y + 1;
							game.movesRemaining = game.movesRemaining - 1;
							break;
						case 5:		//Down
							printf("\nFrog going down");
							game.frog.y = game.frog.y - 1;
							game.movesRemaining = game.movesRemaining - 1;
							break;
						case 6:		//Left
							//Move frog left
							printf("\nFrog going left");
							game.frog.x = game.frog.x - 1;
							game.movesRemaining = game.movesRemaining - 1;
							break;
						case 7:		//Right
							//Move frog right
							printf("\nFrog going right");
							game.frog.x = game.frog.x + 1;
							game.movesRemaining = game.movesRemaining - 1;
							break;
						default:
							break;
					}
				}
			}
			delayMicroseconds(1000000);
		}
		while(paused)
		{	
			//TODO: NEEDS SOME SORT OF PAUSE MENU SELECTION
			printf("Please press a button\n");
			unsigned short code = readSNES(gpioPtr);	//Gets series of bits for buttons pushed
			for(int i = 0; i < 12; i++)	//Iterates through bits sent from readSNES
			{
				int value = (code >> i) & 1;	//Gets bit of in i position
				if(value == 0)	//If button is pushed
				{
					button = i;	//Sets button pushed to index for printing
					printMessage(button);	//Prints button pushed
					switch(button)
					{
						case 0:		//B
							break;
						case 1:		//Y
							break;
						case 2:		//Select
							break;
						case 3:		//Start
							//Unpause game
							paused = false;
							break;
						case 4:		//Up
							break;
						case 5:		//Down
							break;
						case 6:		//Left
							break;
						case 7:		//Right
							break;
						case 8:		//A
							break;
						case 9:		//X
							break;
						case 10:	//Left bumper
							break;
						case 11:	//Right bumper
							break;
						default:
							break;
					}
				}
			}
			printf("\nPAUSED");
			delayMicroseconds(1000000);
		}
	}
	pthread_exit(NULL);
}

void initializeGame()
{
	printf("\nInit game");
	game.startTime = clock();
	game.score = 0;
	game.extraLives = 4;
	game.secondsRemaining = 999;
	game.movesRemaining = 200;
	game.gameOver = false;
	currentStage = 0;

	game.frog.x = 10;
	game.frog.y = 0;

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

void gamePlay()
{
	printf("\nGamePlay");
	initializeGame();
	bool exit = false;
	while(!exit)
	{
		if(gameStart)
		{
			update();
			//Clear screen
			//Draw
			exit = checkExit();
			delayMicroseconds(100000);
		}
	}
}

void update()
{
	//printf("\nUpdate");
	printf("\nFrog y: %i Frog x: %i", game.frog.y, game.frog.x);
	clock_t currentTime = clock();
	int timePassed = game.startTime - currentTime;
	game.secondsRemaining = 999 - timePassed;

	printf("\n\nData\nTime remaining: %i\nLives: %i\nMoves: %i\n", game.secondsRemaining, game.extraLives, game.movesRemaining);

	int collide = collisionDetection();
	if(collide != 0 && game.stages->isWater)
	{
		game.frog.x = game.frog.x + game.stages[currentStage].objects[collide].velocity;
	}

	for(int i = 0; i < 10; i++)
	{
		game.stages[currentStage].objects[collide].x = game.stages[currentStage].objects[collide].x + game.stages[currentStage].objects[collide].velocity;
	}
	if(game.frog.x < 0 || game.frog.x > 20 || game.frog.y < 0)
	{
		game.extraLives = game.extraLives - 1;
	}
	if(game.frog.y >= 20)
	{
		currentStage = currentStage + 1;
		game.frog.y = 0;
        printf("\nGoing up a stage");
	}
}

int collisionDetection()
{
	for(int i = 0; i < 10; i++)
	{
		if(game.stages[currentStage].objects[i].x == game.frog.x && game.stages[currentStage].objects[i].y == game.frog.y)
			return i;
	}
	return 0;
}
bool checkExit()
{
	if(currentStage == 3 && game.frog.y >= 20)
	{
		//WIN
        printf("\nCongrats you have won");
		game.gameOver = true;
		return true;
	}
	if(game.extraLives == 0 || game.movesRemaining == 0 || game.secondsRemaining == 0)
	{
		//LOSE
        printf("\nSorry you lose");
		game.gameOver = true;
		return true;
	}
	return false;
}