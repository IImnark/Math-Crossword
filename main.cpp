#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    std::cout << "SDL2, SDL2_image, and SDL2_ttf initialized successfully!" << std::endl;

    SDL_Quit();
    return 0;
}