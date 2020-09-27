#include "game_controller.h"

int main(int argc, char* args[])
{
	//start up SDL and create window
	if( !SDLinit() )
	{
		std::cout << "Failed to initialize SDL" << std::endl;
	}
	else
	{	
		std::cout << "EVERY THING IS FINE" << std::endl;
	}
}
