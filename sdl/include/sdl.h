#ifndef SDL_H
#define SDL_H

#include<iostream>
#include<string>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_mixer.h>
#include<SDL_ttf.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// need to pass string as macro from command line to reuse this library
const char* project="SNAKEGAME";

bool SDLinit();

#endif // SDL_H
