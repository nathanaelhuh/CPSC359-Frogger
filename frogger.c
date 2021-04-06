#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
	int menu = printGameMenu();
	
	if(menu == 1)
	{
		//start game
		initalizeGame();
		
	}
	else	//Exits the game
	{
		return 0;
	}

}


int printGameMenu();
{
	
	//This is the main game menu that has start and quit
	//Will have some sort of background and maybe animation?
	//Loop while waiting on input
	bool start = false;
	bool quit = false;


}
