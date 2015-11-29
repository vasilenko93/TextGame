#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <cstring>

#include "Utilities.h"
#include "WorldMap.h"
#include "Player.h"

using namespace std;

typedef struct {
    Player* player;
    string  savename;
} ActiveGame;

class Game
{
public:
    Game();

    int mainloop();

    int showmainmenu();
    void printmainmenu();

    void closeactivegame();

    void printcurrentposition( );
    void createnewgame( );

    //Public varuables
    static const string GAME_NAME; // Change this later
private:
    ActiveGame* activegame = 0;
    WorldMap*   worldmap   = 0;
};

#endif
