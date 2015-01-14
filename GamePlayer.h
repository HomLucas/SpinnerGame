


/*
 *  GamePlayer.h
 *  110clab2
 *
 *  Created by lucas on 10/1/13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef GAME_PLAYER
#define GAME_PLAYER
#include "SpinningWheel.h"

class GamePlayer
{
private:
    int points;
    bool winner;
    bool eliminated;
    bool tied;

public:
    GamePlayer();
    void spin(SpinningWheel &wheel);
    int getTotalPoints();
    void addPoints(int value);
    void setEliminated(bool);
    bool isEliminated();
    void setWinner(bool);
    bool isWinner();
    void setTied(bool);
    bool isTied();

};

#endif



















