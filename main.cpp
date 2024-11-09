#include <SDL2/SDL.h>
#include <iostream>

int main()
{

    std::cout << "we are in business baby!";



    if(SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "Error: " << SDL_GetError();
        return 1;
    }

    //To do: Lage ett vindu

    SDL_DisplayMode dm;

    if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
    {
         SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
         return 1;
    }

    int w, h;
    w = dm.w;
    h = dm.h;

    SDL_Window* window = SDL_CreateWindow("Testing Window", 0, 0, dm.w*0.25, dm.h*0.25, SDL_WINDOW_SHOWN);
    SDL_Delay(5000);
    SDL_DestroyWindow(window);

    //Tegne Pixler i vinduet

    //Beregne hvordan 3d-matrisen ser ut i ett 2d-rom

    //Fjerne pixler bak hoorisonten

    //Farge pixler basert på høyde

    //Downsample matrisen basert på vindustørrelse

    //Muliggjør flytting av kamera




    return 1;
    
}

