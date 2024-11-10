#include <SDL2/SDL.h>
#include <iostream>
#include "heightmap.h"
#include "renderer.h"


int main()
{

    //const std::string path = "dtm1/data/dtm1_33_115_135.tif";
    float window_scaling = 0.5; 

    Renderer engine{window_scaling};

    engine.init();

    while(engine.isRunning()){
        engine.events();
        engine.render();
    
    }

    std::cout << "og der var vi ferdig.." << '\n';


    //window.displa

    //Tegne Pixler i vinduet

    //Beregne hvordan 3d-matrisen ser ut i ett 2d-rom

    //Fjerne pixler bak hoorisonten

    //Farge pixler basert på høyde

    //Downsample matrisen basert på vindustørrelse

    //Muliggjør flytting av kamera


    SDL_Quit();



    return 1;
    
}

