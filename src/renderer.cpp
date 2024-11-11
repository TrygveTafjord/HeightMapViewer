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


void Renderer::render() {
    // Create a texture to hold the pixel data
    SDL_Texture* texture = SDL_CreateTexture(
        this->renderer,
        SDL_PIXELFORMAT_RGBA8888,
        SDL_TEXTUREACCESS_STREAMING,
        this->width,
        this->height
    );

    // Lock the texture to gain access to the pixel buffer
    Uint32* pixels = nullptr;
    int pitch = 0;
    SDL_LockTexture(texture, NULL, (void**)&pixels, &pitch);

    // Fill the texture pixel buffer with your grayscale gradient
    for (int row = 0; row < this->height; row++) {
        for (int col = 0; col < this->width; col++) {
            // Calculate the grayscale value (from left to right: 0 to 255)
            Uint8 gray = static_cast<Uint8>(col * (255.0f / this->width));

            // Set the color: R, G, B are equal (gray), and alpha is fully opaque (255)
            Uint32 color = (255 << 24) | (gray << 16) | (gray << 8) | gray;

            // Set the pixel at the current position
            pixels[row * (pitch / 4) + col] = color;
        }
    }

    // Unlock the texture and render it
    SDL_UnlockTexture(texture);
    SDL_RenderCopy(this->renderer, texture, NULL, NULL);
    SDL_RenderPresent(this->renderer);

    // Destroy the texture to free memory
    SDL_DestroyTexture(texture);
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



