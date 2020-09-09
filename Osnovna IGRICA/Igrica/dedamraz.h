#ifndef DEDAMRAZ_H
#define DEDAMRAZ_H


#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>


#include "drawable.h"
#include "movable.h"

#include "spritesheet.h"
#include "sprite.h"

using namespace std;

class Dedamraz:public Sprite{
public:
    Dedamraz(SpriteSheet *sheet, int width = 64, int height = 64);
    void draw(SDL_Renderer * renderer);
    void move();
    void move (int dx, int dy);
    int nivo=1;

};
#endif // DEDAMRAZ_H
