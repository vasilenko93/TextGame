/*
Editor rules for this project.

Make sure the editor is set to having 4 spaces for ever tab.
*/

#include <iostream>

#include "Game.h"

using namespace std;

int main( int argc, char** argv )
{
    Game *textgame = NULL;
    int gamereturncode = 0;

    bool arguments = false;
    if( argc < 2 )
        arguments = false;
    else
        arguments = true;

    if( arguments )
        textgame = new Game(/*savefile name goes here*/);
    else
        textgame = new Game();

    gamereturncode = textgame->mainloop();

    return gamereturncode;
}
