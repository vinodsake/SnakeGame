#include "sdl.h"

//NEED TO FIX THIS
#define STRINGIFY_(x) #x
#ifdef MYPROJECT 
	#define PROJECT_S STRINGIFY_(MYPROJECT)
#endif


SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;

bool SDLinit()
{
	std::cout << PROJECT_S << std::endl;
	//Initializing flag
	bool success = true;

	//Initialize SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "SDL could not initialied! SDL ERROR:" << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			std::cout << "Warning: Linear texture filtering not enabled!" << std::endl;
		}

		//Create Window
		gWindow = SDL_CreateWindow(project, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
						SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(gWindow == NULL)
		{
			std::cout << "SDL Window could not be created. SDL ERROR:" << SDL_GetError() << std::endl;
			success = false;
		}
		else
		{	
			//create vsynced renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(gRenderer == NULL)
			{
				std::cout << "SDL_Renderer was not created! SDL ERROR:" << SDL_GetError() << std::endl;
			}
			else
			{
				//Initialize render color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
			
				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if(!(IMG_Init(imgFlags) & imgFlags))
				{
					std::cout << "SDL_image could not be initialized! SDL_image Error:" << SDL_GetError() << std::endl;
				}
			
			}
			
		}
	}

	return success;
}
