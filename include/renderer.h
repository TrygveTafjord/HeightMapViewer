#pragma once
#include <SDL2/SDL.h>


// NOTES FOR RENDERER CLASS 
// This class should handle the rendering and display of a given sceene
// input: Window-size, Matrix, Transformation
// methods: set up and manage SDL window, render heightmap with colour, draw path given a vector
// note that z buffering mus tbe applied to each point in order to determin what is the closest point to the camera
// Should be the class doing the up/down sampeling, when we iterate over the matrix, iterate over 4x4 (if 4->1 downsampling is nessesary) and use the average of them as the datapoint. Then perform transformation on the new points


class Renderer{
    private:
      SDL_Window* window;
      SDL_Renderer* renderer;
      int height, width;
      bool is_running = false;

    public:
      inline bool isRunning() {return this->is_running;}
      Renderer(float &window_size);
      void render();
      void init();
      void events();
      void quit();


};