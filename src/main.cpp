#include <iostream>
#include <SDL2/SDL.h>

int status = 0;
const int WIDTH = 1024;
const int HEIGHT = 768;
SDL_Window* window = nullptr;
SDL_Renderer* renderer = nullptr;

void setup()
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        status = -1;
    }
    std::cout << "SDL_Init succeeded \n";
}

void createWindowRenderer(const int WIDTH, const int HEIGHT, SDL_Window* & window, SDL_Renderer* & renderer )
{
    window = SDL_CreateWindow("Video Game - SDL window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "SDL_CreateWindow failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        status = -1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "SDL_CreateRenderer failed: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        status = -1;
    }
}

void draw(SDL_Renderer* & renderer)
{
    SDL_RenderClear(renderer); //Clean the render before drawing something else
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); //Set the color RGBa of what you want to draw
    SDL_RenderDrawPoint(renderer, WIDTH/2, HEIGHT/2); //Render a point in the middle of the screen
    SDL_RenderPresent(renderer); //Show it in the window
}

void events()
{
    bool isRunning = true;
    SDL_Event event;
    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                isRunning = false;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Hello Window! \n";
    setup();
    createWindowRenderer(WIDTH, HEIGHT, window, renderer);
    if(status != 0)
    {
        return -1;
    }
    draw(renderer);
    events();

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
