#include <SDL2/SDL.h>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_surface.h>
#include <SDL2/SDL_video.h>
#include <stdio.h>
#include <stdbool.h>

const int SCREEEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

void mkBoard( SDL_Window *win ){
  SDL_Surface* board = SDL_GetWindowSurface(win);
  
    }

void mkMainSurface(SDL_Window* win){
  SDL_Surface *surface = SDL_GetWindowSurface(win);
  SDL_FillRect(surface, NULL, SDL_MapRGB( surface->format, 0x1A, 0x2B, 0x3A));
  SDL_UpdateWindowSurface(win);
}

int main( int argc, char *args[] ){
  SDL_Window* window = NULL;
  
  if( SDL_Init(SDL_INIT_VIDEO) < 0 ){
    printf( "SDL could not Initialize! SDL_Error: %s\n", SDL_GetError() );
  }
  else{
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, SCREEEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(window == NULL){
      printf("Could not create window! SDL_Error: %s\n", SDL_GetError());
    }
    else{

      mkMainSurface(window);

      SDL_Event e;

      bool quit = false;

      while( quit == false ){
	while(SDL_PollEvent(&e)){
	  if(e.type == SDL_QUIT)
	    quit = true;
	}
      }
    }
  }
    SDL_DestroyWindow( window );
    SDL_Quit();

    return 0;
 }
