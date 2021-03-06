/*
This is simply a header to include libraries, global const variables, and typedef names.  The global const variables not only declutter the classes by not requiring all of the variables to be passed around, but it allows another user to more easily change these vital settings as they so desire without having to search through all of the files to replace what they need to.
*/

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//screen size variables
const int S_WIDTH = 600;
const int S_HEIGHT = 400;
const int TILE_SIZE = 10;
const int B_THICKNESS = 1; //border thickness, i.e. how many rows of tiles border the window

//player variables
const int P_WIDTH = 20;
const int P_HEIGHT = 40;

//image variables
const string imPath="./images/"; //subdirectory for images
const string bgPath="bg/"; //subdirectory in images for background images
const string bgExt=".bmp"; //extension of images loaded for background (used with SDL_LoadBMP)
const string imExt=".png"; //extension of images loaded for objects (used with IMG_LoadTexture)

typedef vector< vector <char> > v2; //name for 2d array of chars

#endif
