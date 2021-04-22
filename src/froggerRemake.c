#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include "initGPIO.h"
#include "framebuffer.h"

#include "../resources/MainMenu.c"
#include "../resources/SelectionBar.c"
#include "../resources/PauseMenu.c"
#include "../resources/Background.c"
#include "../resources/CarImage.c"
#include "../resources/FrogImage.c"
#include "../resources/LogImage(48x32).c"
#include "../resources/TurtleImage(32x32).c"

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
void clear();
void *draw(void *params);

struct GameState game;
int currentStage;
bool gameStart, paused, quit, startHighlighted;

int main(int argc, char **argv)
{
	printf("\nMain");
	printf("\nGame menu");
    gameStart = false;
	paused = false;
	quit = false;

	pthread_t inputThread;	//Thread for input
	pthread_t drawThread;	//Thread for graphics
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	int tc = pthread_create(&inputThread, &attr, playerInput, "1");	//Creating thread for input
	if(tc)
	{
		printf("ERROR creating input thread, %d\n", tc);	//Error checking thread creation
		exit(-1);
	}
	int dc = pthread_create(&drawThread, &attr, draw, "1");		//Creating thread for drawing
	if(dc)
	{
		printf("ERROR creating draw thread, %d\n", tc);		//Error checking thread creation
		exit(-1);
	}
	gamePlay();
}

//Thread for player input
void *playerInput(void *params)	
{
	//GPIO initialization from project part 1
	unsigned int *gpioPtr = getGPIOPtr();
	initializeGPIO(gpioPtr);
	unsigned short button;
	startHighlighted = true;
	//Loop for program
	while(!quit)
	{
		//Loop for menu selection
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
						gameStart = true;	//Starts game
					}
					if(button == 8)	//A
					{
						if(startHighlighted)
						{
							gameStart = true;	//Starts game
						}
						else
						{
							quit = true;	//Exits program
						}
					}
				}
			}
			delayMicroseconds(1000000);
		}
		//Loop for gameplay and game not paused
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
							game.frog.y = game.frog.y + 1;	//Increments frog y value
							game.movesRemaining = game.movesRemaining - 1;	//Decrements remaining moves
							break;
						case 5:		//Down
							printf("\nFrog going down");
							game.frog.y = game.frog.y - 1;	//Decrements frog y value
							game.movesRemaining = game.movesRemaining - 1;	//Decrements remaining moves
							break;
						case 6:		//Left
							//Move frog left
							printf("\nFrog going left");
							game.frog.x = game.frog.x - 1;	//Increments frog x value
							game.movesRemaining = game.movesRemaining - 1;	//Decrements remaining moves
							break;
						case 7:		//Right
							//Move frog right
							printf("\nFrog going right");
							game.frog.x = game.frog.x + 1;	//Decrements frog x value
							game.movesRemaining = game.movesRemaining - 1;	//Decrements remaining moves
							break;
						default:
							break;
					}
				}
			}
			delayMicroseconds(100000);
		}
		while(paused)
		{	
			int menuSelect = 0;
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
							if(menuSelect == 1)
								menuSelect = menuSelect - 1;
							break;
						case 5:		//Down
							if(menuSelect == 0)
								menuSelect = menuSelect + 1;
							break;
						case 6:		//Left
							break;
						case 7:		//Right
							break;
						case 8:		//A
							if(menuSelect == 0)
								paused = false;
							else
								quit = true;
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
			delayMicroseconds(100000);
		}
	}
	pthread_exit(NULL);
}


//Initializes variables needed for game
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
	game.frog.y = 20;

	//Initializes game objects
	for(int i = 0; i < 4; i++)
	{
		int temp = -1;	//Temp is for reversing velocities of objects
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
			game.stages[i].objects[j].y = j + 1;
			game.stages[i].objects[j].velocity = temp;		//TODO: Might change object velocities later
		}
		temp = -temp;
		game.stages[i].isWater = i%2;
	}
}

//Function for game
void gamePlay()
{
	printf("\nGamePlay");
	initializeGame();
	bool exit = false;
	while(!exit && !quit)
	{
		if(gameStart)
		{
			update();
			//Clear screen
			//Draw
			exit = checkExit();
			delayMicroseconds(50000);
		}
	}
}

void update()
{
	//printf("\nUpdate");
	printf("\nFrog y: %i Frog x: %i", game.frog.y, game.frog.x);
	clock_t currentTime = clock();		//Gets current time in ticks
	int timePassed = (currentTime - game.startTime) / CLOCKS_PER_SEC;	//Converts ticks into seconds
	game.secondsRemaining = 999 - timePassed;		//Seconds remaining calculation

	int collide = collisionDetection();	
	//Adds platform velocity to frog
	if(collide != 0 && game.stages->isWater)	//If stage is water then objects are platforms
	{
		game.frog.x = game.frog.x + game.stages[currentStage].objects[collide].velocity;
	}

	//Adds velocity to objects, resets them when they hit the edge
	for(int i = 0; i < 10; i++)
	{
		game.stages[currentStage].objects[collide].x = game.stages[currentStage].objects[collide].x + game.stages[currentStage].objects[collide].velocity;
		if(game.stages[currentStage].objects[collide].x < 0)
		{
			game.stages[currentStage].objects[collide].x = 20;
		}
		if(game.stages[currentStage].objects[collide].x > 20)
		{
			game.stages[currentStage].objects[collide].x = 0;
		}
	}
	//Bounds detection for frog
	if(game.frog.x < 0 || game.frog.x > 20 || game.frog.y > 20)
	{
		game.extraLives = game.extraLives - 1;
		game.frog.x = 10;
		game.frog.y = 20;
	}
	//Checks if frog completed stage
	if(game.frog.y <= 0)
	{
		currentStage = currentStage + 1;
		game.frog.y = 20;
        printf("\nGoing up a stage");
	}
	
	//Score calculation
	game.score = game.secondsRemaining + game.movesRemaining + (game.extraLives * 100);

	printf("\n\nData\nTime remaining: %i\nLives: %i\nMoves: %i\n", game.secondsRemaining, game.extraLives, game.movesRemaining);
}

void clear()
{

}

typedef struct {
	int color;
	int x, y;
} Pixel;

typedef struct {
	Pixel pixels[640][640];
} Stage;

struct fbs framebufferstruct;
void drawPixel(Pixel *pixel);

void *draw(void *params)
{

	framebufferstruct = initFbInfo();
	
	int *mainMenuPtr=(int *) Menu.pixel_data;	
	int *pauseMenuPtr=(int *) Pause.pixel_data;	
	int *selectionBarPtr=(int *) SelectionBar.pixel_data;	
	int *backgroundPtr=(int *) Background.pixel_data;	
	int *carPtr=(int *) Car.pixel_data;
	int *logPtr=(int *) Log.pixel_data;
	int *turtlePtr=(int *) Turtle.pixel_data;
	int *frogPtr=(int *) Frog.pixel_data;


	Pixel *pixel;
	pixel = malloc(sizeof(Pixel));


	while(!quit)
	{
		while(!gameStart)
		{
			int i=0;
			for (int y = 0; y < 640; y++)
			{
				for (int x = 0; x < 640; x++) 
				{	
						pixel->color = mainMenuPtr[i]; 
						pixel->x = x;
						pixel->y = y;
							
						drawPixel(pixel);
						i++;		
				}
			}
			i = 0;
			if(startHighlighted)
			{
				for (int y = 0; y < 20; y++)
				{
					for (int x = 0; x < 320; x++) 
					{
						pixel->color = selectionBarPtr[i]; 
						pixel->x = x;
						pixel->y = y + 450;
							
						drawPixel(pixel);
						i++;		
					}
				}
			}
			else
			{
				for (int y = 0; y < 20; y++)
				{
					for (int x = 0; x < 320; x++) 
					{
						pixel->color = selectionBarPtr[i]; 
						pixel->x = x + 320;
						pixel->y = y + 450;
							
						drawPixel(pixel);
						i++;		
					}
				}
			}
		}
		while(gameStart && !paused)
		{
			//Pointers to images
			// Stage *stage;
			// stage = malloc(sizeof(Stage));
			int i=0;
			unsigned int quarter,byte,word;
			for (int y = 0; y < 640; y++)
			{
				for (int x = 0; x < 640; x++) 
				{	
						pixel->color = backgroundPtr[i]; 
						pixel->x = x;
						pixel->y = y;
							
						drawPixel(pixel);
						i++;		
				}
			}
			for(int j = 0; j < 10; j++)	//OBJECTS
			{
				i=0;
				for (int y = 0; y < 32; y++)
				{
					for (int x = 0; x < 32; x++) 
					{	
							pixel->color = carPtr[i]; 
							pixel->x = x + (game.stages[currentStage].objects[j].x * 32);	//Update locations for objects
							pixel->y = y + (game.stages[currentStage].objects[j].y * 32);
							
							drawPixel(pixel);
							i++;						
					}
				}
			}
			//Drawing frog
			i=0;
			for (int y = 0; y < 32; y++)
			{
				for (int x = 0; x < 32; x++) 
				{	
						pixel->color = frogPtr[i]; 
						pixel->x = x + (game.frog.x * 32);
						pixel->y = y + (game.frog.y * 32);
						
						drawPixel(pixel);
						i++;			
				}
			}
			
		}
		while(paused)
		{
			
		}
	}
	/* free pixel's allocated memory */
	free(pixel);
	pixel = NULL;
	munmap(framebufferstruct.fptr, framebufferstruct.screenSize);
}

// void drawPixel(Stage *stage)
// {
// 	memcpy(framebufferstruct.fptr, stage, 1280*720*2);
// }

/* Draw a pixel */
void drawPixel(Pixel *pixel){
	long int location = (pixel->x +framebufferstruct.xOff) * (framebufferstruct.bits/8) +
                       (pixel->y+framebufferstruct.yOff) * framebufferstruct.lineLength;
	*((unsigned short int*)(framebufferstruct.fptr + location)) = pixel->color;
}



//Checks frog position against object positions for current stage, returns object position in list
int collisionDetection()
{
	//Checks object x with frog x and object y with frog y
	for(int i = 0; i < 10; i++)
	{
		if(game.stages[currentStage].objects[i].x == game.frog.x && game.stages[currentStage].objects[i].y == game.frog.y)
			return i;
	}
	return 0;
}

//Checks to see if game is over via frog reaching castle or running out of live/moves/time
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