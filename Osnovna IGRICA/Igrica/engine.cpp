#include "engine.h"
#include <windows.h>



Engine::Engine(string title)
{
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void Engine::addTileset(Tileset *tileset, const string &name)
{
    tilesets[name] = tileset;
}

void Engine::addTileset(istream &inputStream, const string &name)
{
    addTileset(new Tileset(inputStream, renderer), name);
}

void Engine::addTileset(const string &path, const string &name)
{
    ifstream tilesetStream(path);
    addTileset(tilesetStream, name);
}

Tileset* Engine::getTileset(const string &name)
{
    return tilesets[name];
}

void Engine::addDrawable(Drawable *drawable)
{
    drawables.push_back(drawable);
}

void Engine::run()
{
    initPoklon();
    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;

    bool running = true;
    SDL_Event event;



    initDeda();


    /// =======   prvi bishop ==============
    ///Cikica koji moze da se sakrije
    ///HidingSprite *hs = new HidingSprite(sheet);
    ///hs->setFrameSkip(4);
    ///hs->hidden = true;
    ///Player *p = new Player(hs);
    ///drawables.push_back(p);
    ///movables.push_back(p);
    ///eventListeners.push_back(p);

	///======== pravljenje boarda i load =========

	///Board tabla = Board();
    ///tabla.dodajLovca(bsp);
    ///tabla.dodajLovca(bsp2);
    ///tabla.dodajLovca(sp);

	///========================================
    ///pravljenje formacije
    ///Formation *lista = new Formation();
    ///lista->load();/// pozvati load posle 1.pozivanja save

    ///lista->dodajFormaciju(hs);
    ///lista->dodajFormaciju(hs1);

	/// na kraju posle pokretanja save(), dodati tabla.load();
    bool prosao = false, instr = false;
    while(running)
    {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event))
        {
            if (GetAsyncKeyState(0x33)) running=false;
            for(size_t i = 0; i < eventListeners.size(); i++)
            {
                eventListeners[i]->listen(event);
            }
        }
        ispitivanjeKolizije();
        if (g->kolizijasaPoklonom(sp, pok) == 5)
        {
            drawables.clear();                                                      // brisem sve sto je nacrtano da bih crtala novo
            addTileset("resources/tilesets/grass_tileset.txt", "default");
            ifstream levelStream("resources/levels/level2.txt");

            Level *nivo2 = new Level(levelStream, getTileset("default"));
            addDrawable(nivo2);
            noviNivo();
            break;
        }
        bool meni = true;
        if(prosao == false)
        {
        prosao = true;
        SDL_Texture *pozadina = SDL_CreateTextureFromSurface(renderer, IMG_Load("C:/Users/Ica/Desktop/Osnovna IGRICA/Igrica/resources/opcije/meni.png"));
        SDL_Rect *pozadina_rect = new SDL_Rect();
        pozadina_rect->x = 0;
        pozadina_rect->y = 0;
        pozadina_rect->w = 640;
        pozadina_rect->h = 480;
        SDL_RenderCopy(renderer, pozadina, NULL, pozadina_rect);
        SDL_RenderPresent(renderer);
        while(meni)
            {
                if(GetAsyncKeyState(0x31))
                {
                    meni=false;

                }

                if(GetAsyncKeyState(0x32) && instr == false)
                    {
                        Sleep(200);
                        instr = true;
                        SDL_Texture *pozadina = SDL_CreateTextureFromSurface(renderer, IMG_Load("C:/Users/Ica/Desktop/Osnovna IGRICA/Igrica/resources/opcije/instruction.png"));
                        SDL_RenderCopy(renderer, pozadina, NULL, pozadina_rect);
                        SDL_RenderPresent(renderer);
                    }
                if(GetAsyncKeyState(0x32) && instr == true)
                    {
                        Sleep(200);
                        instr = false;
                        SDL_Texture *pozadina = SDL_CreateTextureFromSurface(renderer, IMG_Load("C:/Users/Ica/Desktop/Osnovna IGRICA/Igrica/resources/opcije/meni.png"));
                        SDL_RenderCopy(renderer, pozadina, NULL, pozadina_rect);
                        SDL_RenderPresent(renderer);
                    }
                if(GetAsyncKeyState(0x33)) {running=false; meni=false;}
            }
        }


        SDL_RenderClear(renderer);
        for(size_t i = 0; i < movables.size(); i++)
        {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++)
        {
            drawables[i]->draw(renderer);
        }
   ///     drawScore(g->scor, renderer);
      //  cout<<"skor"<< g->scor;

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay)
        {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
}
void Engine:: noviNivo()
{
    initDeda();
    initPoklon();
    pok->nivo=2;
    sp->nivo=2;

    bool running = true;
    SDL_Event event;

    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;


    while(running)
    {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event))
        {
            if (GetAsyncKeyState(0x33)) running=false;
            for(size_t i = 0; i < eventListeners.size(); i++)
            {
                eventListeners[i]->listen(event);
            }
        }
        ispitivanjeKolizije();
        if (g->kolizijasaPoklonom(sp, pok) == 5)
        {
            drawables.clear();                                                      // brisem sve sto je nacrtano da bih crtala novo
            addTileset("resources/tilesets/grass_tileset.txt", "default");
            ifstream levelStream("resources/levels/level3.txt");

            Level *nivo3 = new Level(levelStream, getTileset("default"));
            addDrawable(nivo3);
            nivoTri();
            break;
        }


        SDL_RenderClear(renderer);
        for(size_t i = 0; i < movables.size(); i++)
        {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++)
        {
            drawables[i]->draw(renderer);
        }
   ///     drawScore(g->scor, renderer);
      //  cout<<"skor"<< g->scor;

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay)
        {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
    cout<<"Treba da predje na novi nivo!";
}
void Engine:: nivoTri()
{
    initDeda();
    initPoklon();
    pok->nivo=3;
    sp->nivo=3;

    bool running = true;
    SDL_Event event;

    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;


    while(running)
    {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event))
        {
            if (GetAsyncKeyState(0x33)) running=false;
            for(size_t i = 0; i < eventListeners.size(); i++)
            {
                eventListeners[i]->listen(event);
            }
        }
        ispitivanjeKolizije();
        if (g->kolizijasaPoklonom(sp, pok) == 5)
        {
            drawables.clear();                                                      // brisem sve sto je nacrtano da bih crtala novo
            addTileset("resources/tilesets/grass_tileset.txt", "default");
            ifstream levelStream("resources/levels/level4.txt");

            Level *nivo4 = new Level(levelStream, getTileset("default"));
            addDrawable(nivo4);
            nivoCetiri();
            break;
        }


        SDL_RenderClear(renderer);
        for(size_t i = 0; i < movables.size(); i++)
        {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++)
        {
            drawables[i]->draw(renderer);
        }
   ///     drawScore(g->scor, renderer);
      //  cout<<"skor"<< g->scor;

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay)
        {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
    cout<<"Treba da predje na novi nivo!";

}
void Engine:: nivoCetiri()
{
    initDeda();
    initPoklon();
    pok->nivo=4;
    sp->nivo=4;
    initProtivnik();

    bool running = true;
    SDL_Event event;

    int maxDelay = 1000/frameCap;
    int frameStart = 0;
    int frameEnd = 0;


    while(running)
    {
        frameStart = SDL_GetTicks();
        while(SDL_PollEvent(&event))
        {
            if (GetAsyncKeyState(0x33)) running=false;
            for(size_t i = 0; i < eventListeners.size(); i++)
            {
                eventListeners[i]->listen(event);
            }
        }
        ispitivanjeKolizije();
        if (g->kolizijasaPoklonom(sp, pok) == 5)
        {
            drawables.clear();                                                      // brisem sve sto je nacrtano da bih crtala novo
            addTileset("resources/tilesets/grass_tileset.txt", "default");
            ifstream levelStream("resources/levels/level4.txt");

            Level *nivo4 = new Level(levelStream, getTileset("default"));
            addDrawable(nivo4);
            nivoCetiri();
            break;
        }


        SDL_RenderClear(renderer);
        for(size_t i = 0; i < movables.size(); i++)
        {
            movables[i]->move();
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        for(size_t i = 0; i < drawables.size(); i++)
        {
            drawables[i]->draw(renderer);
        }
   ///     drawScore(g->scor, renderer);
      //  cout<<"skor"<< g->scor;

        SDL_RenderPresent(renderer);

        frameEnd = SDL_GetTicks();
        if(frameEnd - frameStart < maxDelay)
        {
            SDL_Delay(maxDelay - (frameEnd - frameStart));
        }
    }
    cout<<"Treba da predje na novi nivo!";

}
void Engine::initPoklon()
{
    ///napravila poklon

    ifstream spriteSheetStream3("resources/creatures/poklon_sheet.txt");
    sheet3=new SpriteSheet(spriteSheetStream3, renderer);

    pok = new Poklon(sheet3);
    pok -> spriteRect -> x = pok -> randomBroj();
    pok -> spriteRect -> y = pok -> ogranicenje();
    p3=new Player(pok);
    drawables.push_back(p3);


    g=new Group();
}
void Engine::drawScore(int rezultat, SDL_Renderer* renderer)
{
    TTF_Font* font = TTF_OpenFont("font/comicbd.ttf", 24);
    SDL_Color white = {255, 255, 255};
    stringstream ss;
    ss << "Trenutni rezultat [ " << rezultat << " ]";
    SDL_Surface* sm = TTF_RenderText_Solid(font, ss.str().c_str(), white);
    SDL_Texture* poruka = SDL_CreateTextureFromSurface(renderer, sm);
    SDL_Rect poruka_box; //create a rect
    poruka_box.x = 320-sm->w/2;
    poruka_box.y = 480-sm->h;
    poruka_box.w = sm->w;
    poruka_box.h = sm->h;
    SDL_RenderCopy(renderer, poruka, NULL, &poruka_box);
}
void Engine:: ispitivanjeKolizije()
{
   g->kolizijasaPoklonom(sp, pok);
  // g->kolizijaMonstrumDeda(sp, protivnik);
   g->kolizijaMonstrumPoklon(protivnik, pok);
}
void Engine:: initDeda()
{
    ifstream spriteSheetStream("resources/creatures/sprite_sheet.txt");
    SpriteSheet *sheet = new SpriteSheet(spriteSheetStream, renderer);

    //Sprite *sp = new Sprite(sheet);
    //sp->setFrameSkip(4);
    sp=new Dedamraz(sheet);

    Player *player = new Player(sp);

    drawables.push_back(player);
    movables.push_back(player);
    eventListeners.push_back(player);
}
void Engine::initProtivnik()
{
    /// 5 da se razlikuje
    ifstream spriteSheetStream5("resources/creatures/monstrum.txt");
    sheet5 = new SpriteSheet(spriteSheetStream5, renderer);
    protivnik = new Protivnik(sheet5);
    protivnik->setFrameSkip(4);
    p5 = new Player(protivnik);
    drawables.push_back(p5);
    movables.push_back(p5);
}
Engine::~Engine()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

