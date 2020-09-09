#ifndef POKLON_H
#define POKLON_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdlib.h>
#include <time.h>

#include "drawable.h"
#include "movable.h"

#include "spritesheet.h"
#include "sprite.h"

using namespace std;

class Poklon:public Sprite{
public:
    Poklon(SpriteSheet *sheet, int width = 64, int height = 64);
    void draw(SDL_Renderer * renderer);
    void move();
    void move (int dx, int dy);


    int randomBroj();
    int ogranicenje(); /// dodati parametar u zavisnosti od nivoa
    int nivo=1;

};
#endif // POKLON_H_INCLUDED
