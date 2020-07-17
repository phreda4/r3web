#include "emscripten.h"
#include "SDL.h"

SDL_Window*          win;

SDL_Renderer*        renderer;
SDL_Texture*         screen_texture;
Uint32*              screen_pixels;
int v=0;
SDL_Surface *screen;


int action_loop()
{
    unsigned long pixel_amount = 100 * 100 * 4;
    screen_pixels = (Uint32*)malloc(pixel_amount * sizeof(Uint32));
    if (!screen_pixels)
    {
        printf("action_loop: malloc screen_pixels failed\n");
        return 5;
    }

    while (1)
    {
v++;
	SDL_Delay(10);
        emscripten_sleep(10);
	Uint32*p=screen_pixels;
	for (int i=0;i<32000;i++) *p++=(i<<7)+v; 
        SDL_UpdateTexture(screen_texture, NULL, screen_pixels, 100 * 4);
        SDL_RenderCopy(renderer, screen_texture, NULL, NULL);
//        printf("Before potentially unreachable SDL_RenderPresent\n");
        SDL_RenderPresent(renderer);
//        printf("After potentially unreachable SDL_RenderPresent\n");        
//	SDL_UpdateWindowSurface(win);
    }
    return 0;
}

int main(int argc, char **argv)
{
SDL_SetHint(SDL_HINT_EMSCRIPTEN_ASYNCIFY, "0");
    if (SDL_Init(SDL_INIT_VIDEO) == 0)
    {
        win = SDL_CreateWindow("QNICE Emulator", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 100, 100, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);
/*
screen = SDL_GetWindowSurface(win);
screen_pixels=(Uint32*)screen->pixels;
}
return 1;
/*/

        if (win)
        {
            renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
            if (renderer)
            {
                SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
                screen_texture = SDL_CreateTexture( renderer,
                                                    SDL_PIXELFORMAT_ARGB8888,
                                                    SDL_TEXTUREACCESS_STREAMING,
                                                    100,
                                                    100);
                if (!screen_texture)
                {
                    printf("Unable to screen texture: %s\n", SDL_GetError());
                    return 2;
                }
                else
                {
                    printf("INIT: OK\n");
                    return action_loop();
                }

            }
            else
            {
                printf("Unable to create renderer: %s\n", SDL_GetError());
                return 3;
            }
        }
        else
        {
            printf("Unable to create window: %s\n", SDL_GetError());
            return 4;
        }
    }
    else
        return 1;
/**/
}
