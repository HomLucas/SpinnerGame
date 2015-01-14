


/*
 *  GamePlayer.cpp
 *  110clab2
 *
 *  Created by lucas on 10/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#include "GamePlayer.h"
#include <iostream>
using namespace std;

void GamePlayer::spin(SpinningWheel &wheel)
{
	int add = wheel.spin();
	points += add;
}

int GamePlayer::getTotalPoints()
{
	return points;
}

GamePlayer::GamePlayer()
{
	points = 0;
	winner = false;
	eliminated = false;
	tied = false;

}
void GamePlayer::addPoints(int value)
{
	points = points + value;
}

void GamePlayer::setEliminated(bool value)
{
    eliminated = value;
}

bool GamePlayer::isEliminated()
{
    return eliminated;
}

void GamePlayer::setWinner(bool value)
{
    winner = value;
}

bool GamePlayer::isWinner()
{
    return winner;
}

void GamePlayer::setTied(bool value)
{
    tied = value;
}

bool GamePlayer::isTied()
{
    return tied;
}






