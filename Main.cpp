#include <SDL.h>




int main(int argn, char * args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * Window = SDL_CreateWindow("Test", 50, 80, 800, 640, SDL_WINDOW_SHOWN);
	SDL_Surface * Surface =	SDL_GetWindowSurface(Window);
	SDL_Event evnt;
	bool quit = false;

	SDL_Surface * image = SDL_LoadBMP("Sprites//MR_BG_Grid_bmp.bmp");



	while (!quit)
	{
		// Draw

		SDL_BlitSurface(image, NULL, Surface, NULL);
		SDL_UpdateWindowSurface(Window);


		// Update



		// Event pipe
		while (SDL_PollEvent(&evnt) != 0)
		{
			if (evnt.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	SDL_Quit();

	return 0;
}




