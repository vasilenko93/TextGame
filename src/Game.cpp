#include "Game.h"

const string Game::GAME_NAME = "TextGame";

Game::Game()
{
}

int Game::mainloop( )
{
    while( true )
    {
        int menureturn = showmainmenu( );

        // If no game active
        if( menureturn == 1 )
            createnewgame();

        if( menureturn == 2 )
            //Load

        if( menureturn == 3 )
            return 0;

        // If game is active
        if( menureturn == 6 )
            closeactivegame();

        printf("\n\n\n" );
    }
    return 0;
}


int Game::showmainmenu( )
{
    CommandInput input;

    printmainmenu();
    while( true )
    {
        input.getInput();
        switch ( input.command )
        {
            case 'n':
            case 'N':
                if( !activegame )
                    return 1; else printf("Your input was invalid, please try again.\n" );
                break;
            case 'l':
            case 'L':
                if( !activegame )
                    return 2; else printf("Your input was invalid, please try again.\n" );
                break;
            case 'q':
            case 'Q':
                if( !activegame )
                    return 3; else printf("Your input was invalid, please try again.\n" );
                break;
            case 'r':
            case 'R':
                if( activegame )
                    return 4; else printf("Your input was invalid, please try again.\n" );
                break;
            case 's':
            case 'S':
                if( activegame )
                    return 5; else printf("Your input was invalid, please try again.\n" );
                break;
            case 'c':
            case 'C':
                if( activegame )
                    return 6; else printf("Your input was invalid, please try again.\n" );
                break;
            default:
                printf("Your input was invalid, please try again.\n" );
        }
    }
    return 0;
}

void Game::printmainmenu( )
{
    printf("%s\n", GAME_NAME.c_str() );
    if( activegame )
    {
        printf("Current player: %s\n\n", activegame->player->getname().c_str() );

        printf("(R)eturn to Game\n");
        printf("(S)ave Game\n"     );
        printf("(C)lose Game\n"    );
    }
    else
    {
        printf("(N)ew Game\n"  );
        printf("(L)oad Game\n" );
        printf("(Q)uit Game\n" );
    }
}

void Game::closeactivegame( )
{
    if( !activegame || activegame == NULL )
        return;

    // TODO
    // Free up space used by memebers in activegame

    delete activegame;
    activegame = 0;
}

void Game::printcurrentposition( )
{
    worldmap->PrintLocation( activegame->player->getposition() );
}

void Game::createnewgame()
{
    if( activegame != 0 )
        closeactivegame();

    activegame = new ActiveGame( );

    worldmap = new WorldMap( );
    activegame->player = new Player( 0 );
}
