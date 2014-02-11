#include <SDL.h>
#include "Maze.h"
#include "Pathfinder.h"


int main(int argn, char * args[])
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * Window = SDL_CreateWindow("Test", 50, 80, 1000, 1000, SDL_WINDOW_SHOWN);
	SDL_Surface * Surface =	SDL_GetWindowSurface(Window);
	SDL_Event evnt;
	bool quit = false;

	SDL_Surface * image = SDL_LoadBMP("Sprites//MR_BG_Grid_bmp.bmp");


	bool LevelOneCode[338] = { 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

	cMaze MazeOne(LevelOneCode);
	cPathfinder PathOne;
	PathOne.create(MazeOne);

	SDL_Surface * redsquare = SDL_LoadBMP("redsquare.bmp");
	SDL_Surface * bluesquare = SDL_LoadBMP("bluesquare.bmp");

	float BlueX = 0.0f;
	float BlueY = 0.0f;


	int LastFrameTime = 0;

	LastFrameTime = SDL_GetTicks();

	// Main Loop
	while (!quit)
	{
		// Draw
		SDL_FillRect(Surface, NULL, 0xff000000);


		for (int y = 0; y < 25; y++)
		{
			for (int x = 0; x < 25; x++)
			{
				if (PathOne.cell_currentNodeMap[x][y].state == 1)
				{
					SDL_Rect Destination;

					Destination.x = x * redsquare->w;
					Destination.y = y * redsquare->h;
					Destination.w = redsquare->w;
					Destination.h = redsquare->h;

					SDL_BlitSurface(redsquare, NULL, Surface, &Destination);
				}
			}
		}

		SDL_Rect BlueDestination;


		BlueDestination.x = BlueX;
		BlueDestination.y = BlueY;
		BlueDestination.w = bluesquare->w;
		BlueDestination.h = bluesquare->h;

		SDL_BlitSurface(bluesquare, NULL, Surface, &BlueDestination);

		SDL_UpdateWindowSurface(Window);


		// Update

		int NewFrameTime = SDL_GetTicks();
		float TimeSinceLastFrame = ((NewFrameTime - LastFrameTime) / 1000.0f);	// milliseconds


		// We know how long this stuff takes.
		const Uint8 * KeyboardState = SDL_GetKeyboardState(NULL);

		if (KeyboardState[SDL_SCANCODE_RIGHT])
		{
			BlueX += (15 * TimeSinceLastFrame);
		}

		LastFrameTime = NewFrameTime;


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




