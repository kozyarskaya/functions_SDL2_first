#include "SDL2/SDL.h"
#include <iostream>
#include <vector>
#define WINDOW_WIDTH 700

using namespace std;

void enter_vector(vector <int > &mass, int n){
    int c;
  for(int i = 0; i < n; i++){
        cin >> c;
        mass.push_back(c);
    }
}



void draw_point(SDL_Renderer *render, SDL_Window *window){

    SDL_Event event;
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &render);
    SDL_SetRenderDrawColor(render, 0, 0, 0, 0);
    SDL_RenderClear(render);
    SDL_SetRenderDrawColor(render, 255, 255, 255, 255);
    SDL_RenderDrawPoint(render, WINDOW_WIDTH / 2, WINDOW_WIDTH / 2);
    SDL_RenderPresent(render);
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();

}



void it_horizontalLine(SDL_Renderer *render, int x, int y, int lenght){
    SDL_SetRenderDrawColor(render, 255, 0, 0, 0);
    bool side = false;
    if (lenght < 0){
        side = true;
        lenght *= -1;
    }
    for(int i = 0; i < lenght; i++){
        SDL_RenderDrawPoint(render, x, y);
        if(side)
            x -= 1;
        else
            x += 1;
    }
}

void it_verticalLine(SDL_Renderer *render, int x, int y, int lenght){
SDL_SetRenderDrawColor(render, 255, 0, 0, 0);
    bool side = false;
    if (lenght < 0){
        side = true;
        lenght *= -1;
    }
    for(int i = 0; i < lenght; i++){
        SDL_RenderDrawPoint(render, x, y);
        if(side)
            y += 1;
        else
            y -= 1;
    }
}

void it_rect(SDL_Renderer *render, int x, int y, int height, int width){
SDL_SetRenderDrawColor(render, 255, 0, 0, 0);
    for(int i = 0; i < width; i++){
        it_verticalLine(render, x, y, height);
        x += 1;
    }
}

void it_verticalDiagram(SDL_Renderer *render, vector <int> numbers){
    int width = 20, height, x = WINDOW_WIDTH / numbers.size(), y = WINDOW_WIDTH / 3;
    it_horizontalLine(render, x, y, (25 * numbers.size()) - 5);
    for(int i = 0; i < numbers.size(); i++){
        height = numbers[i];
        it_rect(render, x, y, height, width);
        x += 25;
    }

}

void it_horizontalDiagram(SDL_Renderer *render, vector <int> numbers){
int width, height = 20, y = WINDOW_WIDTH - (WINDOW_WIDTH / numbers.size()), x = WINDOW_WIDTH / 10;
    it_verticalLine(render, x, y, (25 * numbers.size()) - 5);
    for(int i = 0; i < numbers.size(); i++){
        width = numbers[i];
        it_rect(render, x, y, height, width);
        y -= 25;
    }
}

int main( int argc, char* args[]){
    /*SDL_Init(SDL_INIT_VIDEO);
    SDL_Renderer *render;
    SDL_Window *window;
    draw_point(render, window);*/

    /*int x, y, lenght;
    cin >> x >> y >> lenght;*/


    /*int x, y, h, w;
    cin >> x >> y >> h >> w;*/

    vector <int> mass;
    int n;
    cin >> n;
    enter_vector(mass, n);

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Renderer *render;
    SDL_Window *window;
    SDL_Event event;
    SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &render);
    SDL_SetRenderDrawColor(render, 255, 255, 255, 0);
    SDL_RenderClear(render);
    //it_horizontalLine(render, x, y, lenght);
    //it_verticalLine(render, x, y, lenght);
    //it_rect(render, x, y, h, w);
    //it_verticalDiagram(render, mass);
    //it_horizontalDiagram(render, mass);

    SDL_RenderPresent(render);
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;
}
