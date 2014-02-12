#pragma once
#include <SDL.h>
#include "Maze.h"
#include "Pathfinder.h"

using namespace std;

bool AmIColliding(SDL_Rect pLocation, cPathfinder pNodeMap)
{
	int xindex = 0.0f;
	int yindex = 0.0f;

	xindex = ((pLocation.x + (2 * pLocation.w)) / pLocation.w);
	yindex = ((pLocation.y + pLocation.h) / pLocation.h);

	if (pNodeMap.cell_currentNodeMap[xindex][yindex].state == 0)
	{
		return false;
	}

	if (pNodeMap.cell_currentNodeMap[xindex][yindex].state == 1)
	{
		return true;
	}
}