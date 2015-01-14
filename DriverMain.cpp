
/*
 * Course: cs110c
 * group: Lucas Hom, Felix Chan Lee, Alan Chan
 * filename: driver.cpp
 */

#include <iostream>
#include "SpinningWheel.h"
#include "GamePlayer.h"

using namespace std;

void checkWinner2(GamePlayer[], int);

int main()
{
char playAgain = 'y', answer = 'y';

//Holds amount of points to add to player's points
int addAmount;

do
{
    const int NUM_OF_PLAYERS = 3;

    GamePlayer driverPlayers[NUM_OF_PLAYERS];

    for (int i = 0; i < NUM_OF_PLAYERS; i++)
    {
        cout << "Player " << i + 1;

        //Prompts for how much points to add to player's points
        cout << "\nFirst spin: Enter spin amount: ";

        cin >> addAmount;

        driverPlayers[i].addPoints(addAmount);

        cout << "\nPoints so far: " << driverPlayers[i].getTotalPoints();


        if (i == 2 && //we're on the last player and...
            driverPlayers[0].getTotalPoints() > 100 && //both players are
            driverPlayers[1].getTotalPoints() > 100)   //over 100 points
        {
            //Skip the spin...
        }
        else
        {
            cout << "\nSpin again (y/n)? ";

            cin >> answer;

            if (answer == 'y')
            {
                cout << "Enter spin amount: ";

                cin >> addAmount;

                driverPlayers[i].addPoints(addAmount);
            }

            if (driverPlayers[i].getTotalPoints() > 100)
            {
                cout << "\nOver 100" << endl;
            }
            else
            {
                cout << "\nTotal points: " << driverPlayers[i].getTotalPoints() << endl;
            }
        }
    }

    //Update who are our winners
    checkWinner2(driverPlayers, NUM_OF_PLAYERS);

    cout << "\nWinners: Players ";

    for(int j=0; j<NUM_OF_PLAYERS; j++)
    {
        if(driverPlayers[j].isWinner())
        {
            cout  << j+1 << ", \n";
        }
    }

    cout << "PLAY AGAIN? ";

    cin >> playAgain;
}
while (playAgain == 'y');
}


/*
 * purpose: this function searches through the array of player to check who is winner
 * @param the array of players and total number of players
 * @pre Array must contain the 3 players and total number of players must be 3
 * @post Players in array have winning status modified using their member functions
 */
void checkWinner2(GamePlayer players[], int totalPlayers) {
    int index = 0;
    //loop through to compare scores of players
    for (int i = 0; i < totalPlayers; i++)
    {
        if (players[index].getTotalPoints() > 100 && index < 2)
        {
            index++;
        }

        if (players[i].getTotalPoints() > 100)
        {
            players[i].setEliminated(true);
        } else if ((players[i].getTotalPoints() > players[index].getTotalPoints()))
        {
            index = i;
        }
    }

    //He is the winner...

    players[index].setWinner(true);

    //Check for ties... with the winner

    for (int j = 0; j < totalPlayers; j++)
    {
        if (players[j].getTotalPoints() == players[index].getTotalPoints())
        {
            players[j].setWinner(true);
        }
    }
}

