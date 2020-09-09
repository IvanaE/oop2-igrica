#include "dedamraz.h"



Dedamraz ::Dedamraz(SpriteSheet *sheet, int width, int height):Sprite(sheet,width,height)
{
}

void Dedamraz :: draw(SDL_Renderer * renderer)
{
    if(state&LEFT)
    {
        sheet->drawFrame("walk_left", currentFrame, spriteRect, renderer);
    } else if(state&RIGHT)
    {
        sheet->drawFrame("walk_right", currentFrame, spriteRect, renderer);
    } else if(state&UP)
    {
        sheet->drawFrame("walk_up", currentFrame, spriteRect, renderer);
    } else if(state&DOWN)
    {
        sheet->drawFrame("walk_down", currentFrame, spriteRect, renderer);
    } else if(state == STOP)
    {
        sheet->drawFrame("walk_down", 0, spriteRect, renderer);
    }

    frameCounter++;
    if(frameCounter%frameSkip == 0)
    {
        currentFrame++;
        if(currentFrame >= 9)
        {
            currentFrame = 0;
        }
        frameCounter = 0;
    }
}


void Dedamraz::move(int dx, int dy)
{
    ///ubrzanje
    spriteRect->x += 3*dx;
    spriteRect->y += 3*dy;
        ///ograniceno kretanje
    if( nivo==1)
    {

        if (spriteRect->x < 0)
        {
            spriteRect->x = 0;
        }
        else if (spriteRect->x > 640 - spriteRect->w)
        {
            spriteRect->x = 640-spriteRect->w;                  //640 sirina prozora
        }
        if ( spriteRect->y < 120)
        {
            spriteRect->y = 120;
        }
        else if (spriteRect->y > 220 - spriteRect->h)
        {                                                       //220 visina prozora
            spriteRect->y = 220 - spriteRect->h;
        }
    }
    else if( nivo==2)
    {

        if (spriteRect->x < 0)
        {
            spriteRect->x = 0;
        }
        else if (spriteRect->x > 640 - spriteRect->w)
        {
            spriteRect->x = 640-spriteRect->w;                  //640 sirina prozora
        }
        if ( spriteRect->y < 120)
        {
            spriteRect->y = 120;
        }
        else if (spriteRect->y > 350 - spriteRect->h)
        {                                                       //220 visina prozora
            spriteRect->y = 350 - spriteRect->h;
        }
    }
    else if( nivo==3)
    {

        if (spriteRect->x < 0)
        {
            spriteRect->x = 0;
        }
        else if (spriteRect->x > 640 - spriteRect->w)
        {
            spriteRect->x = 640-spriteRect->w;                  //640 sirina prozora
        }
        if ( spriteRect->y < 120)
        {
            spriteRect->y = 120;
        }
        else if (spriteRect->y > 450 - spriteRect->h)
        {                                                       //220 visina prozora
            spriteRect->y = 450 - spriteRect->h;
        }
    }
    else
    {

        if (spriteRect->x < 0)
        {
            spriteRect->x = 0;
        }
        else if (spriteRect->x > 640 - spriteRect->w)
        {
            spriteRect->x = 640-spriteRect->w;                  //640 sirina prozora
        }
        if ( spriteRect->y < 20)
        {
            spriteRect->y = 20;
        }
        else if (spriteRect->y > 450 - spriteRect->h)
        {                                                       //dno prozora
            spriteRect->y = 450 - spriteRect->h;
        }
    }



}

void Dedamraz::move()
{
     if(state != 0)
    {
        if(state & 1)
        {
            move(-1, 0);
        }
        if(state & 2)
        {
            move(1, 0);
        }
        if(state & 4)
        {
            move(0, -1);
        }
        if(state & 8)
        {
            move(0, 1);
        }
    }
}



