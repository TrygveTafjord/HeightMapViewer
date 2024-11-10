#include "renderer.h"
#include <iostream>


Renderer::Renderer(float &window_scaling){

    if(SDL_Init(SDL_INIT_VIDEO)!=0){
        std::cout<<("Failed to init SDL: ", SDL_GetError()) << '\n';
    }

    SDL_DisplayMode dm;

    if (SDL_GetDesktopDisplayMode(0, &dm) != 0)
    {
         SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
         return;
    }

    this->width = dm.w*window_scaling;
    this->height = dm.h*window_scaling;

}

void Renderer::init(){

    this->window = SDL_CreateWindow("Mountain Map", 0, 0, this->width, this->height, 0);
    if(this->window == nullptr){
        std::cout << "Failed to create window" << SDL_GetError() << '\n';
    }

    this->renderer = SDL_CreateRenderer(this->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(this->window == nullptr){
        std::cout << "Failed to create renderer" << SDL_GetError() << '\n';
    }

    is_running = true;
}


void Renderer::render(){
    SDL_RenderPresent(this->renderer);
}

void Renderer::events(){
    SDL_Event event;
    SDL_PollEvent(&event);

    switch(event.type){
        case SDL_QUIT:
            this->quit();
            break;
    }

}

void Renderer::quit(){
    this->is_running = false;
}



