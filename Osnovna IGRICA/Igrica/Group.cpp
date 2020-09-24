#include "group.h"


Group::Group()
{

}


int  Group::kolizijasaPoklonom(Dedamraz *sprite, Poklon *poklon)
{
    int xSprite = sprite->spriteRect->x;
    int xPoklon = poklon->spriteRect->x;
    int ySprite = sprite->spriteRect->y;
    int yPoklon = poklon->spriteRect->y;

    int x = xSprite - xPoklon;
    int y = ySprite - yPoklon;
    int distanca = sqrt(x*x + y*y);

    if ( distanca < 16+16 ) //16+16 mislim da je to visina igraca?!
    {

        scor ++;


        poklon->spriteRect->x = poklon->randomBroj()*10;
        poklon->spriteRect->y = poklon->ogranicenje();


    }
    return scor;
}
void Group::kolizijaMonstrumDeda(Dedamraz*sprite, Protivnik* protivnik)
{
    int xSprite = sprite->spriteRect->x;
    int xProtivnik = protivnik->spriteRect->x;
    int ySprite = sprite->spriteRect->y;
    int yProtivnik = protivnik->spriteRect->y;

    int x = xSprite - xProtivnik;
    int y = ySprite - yProtivnik;
    int distanca = sqrt(x*x + y*y);

    if ( distanca < 16+16 )
    {
        cout<< "Uhvacen!\n";
        scor =0;
        cout << scor;
        //slucajevi da random izabere gdje ce stati da ne ide ukrug
        int slucaj = protivnik->randomBroj();
        switch(slucaj)
        {
            case 1:
                protivnik->spriteRect->x = 2;
                protivnik->spriteRect->y = 4;
                break;
            case 2:
                protivnik->spriteRect->x = 200;
                protivnik->spriteRect->y = 480;
                break;
            case 4:
                protivnik->spriteRect->x =400;
                protivnik->spriteRect->y = 400;
                break;
            case 8:
                protivnik->spriteRect->x = 170;
                protivnik->spriteRect->y = 15;
                break;
            default:
                protivnik->spriteRect->x = 23;
                protivnik->spriteRect->y = 232;
        }
    }
}
void  Group::kolizijaMonstrumPoklon(Protivnik* protivnik, Poklon* poklon)
{

    int xIR = protivnik->spriteRect->x;
    int xB = poklon->spriteRect->x;
    int yIR = protivnik->spriteRect->y;
    int yB = poklon->spriteRect->y;

    int x = xIR - xB;
    int y = yIR - yB;
    int distanca = sqrt(x*x + y*y);

    if ( distanca < 16+16 )
    {
        scor --;
        cout << scor;
        //par slucajeva i onda random  izaberem gdje ce da stane

        poklon->spriteRect->x = poklon->randomBroj();
        poklon->spriteRect->y = poklon->ogranicenje();
        protivnik->spriteRect->x = 170;
        protivnik->spriteRect->y = 15;


    }
}



