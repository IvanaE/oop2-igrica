#include "poklon.h"

Poklon ::Poklon(SpriteSheet *sheet, int width, int height):Sprite(sheet,width,height)
{
     spriteRect->x =0;
     spriteRect->y =120;
}

void Poklon :: draw(SDL_Renderer * renderer)
{
    if(state == STOP)
    {
        sheet -> drawFrame("walk_down", 0, spriteRect, renderer);
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

void Poklon::move(int dx, int dy)
{

    ///ograniceno kretanje
    if (spriteRect->x < 0)
    {
        spriteRect->x = 0;
    }
    else if (spriteRect->x > 640 - spriteRect->w)
    {
        spriteRect->x = 640-spriteRect->w;                  //640 sirina prozora

    }
    if ( spriteRect->y < 0)
    {
        spriteRect->y =0;

    }
    else if (spriteRect->y > 230 - spriteRect->h)
    {                                               //480 visina prozora
        spriteRect->y = 230 - spriteRect->h;
    }


}

void Poklon::move()
{

}

int Poklon::randomBroj()
{
    int
    srand(time(NULL));
    int br = rand() % 4;
    switch(br)
    {

        case 0:
            return 3;
            break;
        case 1:
            return 51;
            break;
        case 2:
            return 20;
            break;
        case 3:
            return 36.5;
            break;
        default:
            return 0;
            cout<<"Nemoguce!";
    }

}
int Poklon:: ogranicenje()
{
    if (nivo==1)
    {
     return 120;
    }
    else if (nivo==2)
    {
        srand(time(NULL));
        int br=rand()%2;
           switch(br)
        {

            case 0:
                return 120;
                break;
            case 1:
                return 250;
                break;
            default:
                return 0;
        }

    }
    else if (nivo==3)
    {
        srand(time(NULL));
        int br=rand()%3;
           switch(br)
        {

            case 0:
                return 120;
                break;
            case 1:
                return 250;
                break;
            case 2:
                return 350;
                break;
            default:
                return 0;
        }

    }
       else
    {
        srand(time(NULL));
        int br=rand()%4;
           switch(br)
        {

            case 0:
                return 120;
                break;
            case 1:
                return 250;
                break;
            case 2:
                return 320;
                break;
            case 3:
                return 390;
                break;
            default:
                return 0;
        }

    }

}
