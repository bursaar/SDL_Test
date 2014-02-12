#pragma once
#include <SDL.h>
#include "Maze.h"
#include "Pathfinder.h"

using namespace std;

int HowMany(float pFloat1, float pFloat2)
{
	float answer = pFloat2;
	int count = 0;
	while (answer > 0.0f)
	{
		answer = pFloat1 - pFloat2;
		pFloat1 = answer;
		count++;
	}

	return count - 1;
}

enum directions {UP, RIGHT, DOWN, LEFT};

bool AmIColliding(SDL_Rect pLocation, cPathfinder pNodeMap, int pDirection)
{
	int xindex = 0;
	int yindex = 0;
	
	if (pDirection == DOWN || pDirection == RIGHT)
	{
		xindex = HowMany((pLocation.x + pLocation.w), pLocation.w);
		yindex = HowMany((pLocation.y + pLocation.h), pLocation.h);
	}
	if (pDirection == UP || pDirection == LEFT)
	{
		xindex = HowMany((pLocation.x), pLocation.w);
		yindex = HowMany((pLocation.y), pLocation.h);
	}

	if (pNodeMap.cell_currentNodeMap[xindex][yindex].state == 0)
	{
		return false;
	}

	if (pNodeMap.cell_currentNodeMap[xindex][yindex].state == 1)
	{
		return true;
	}
}
