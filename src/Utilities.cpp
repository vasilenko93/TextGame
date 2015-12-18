#include "Utilities.h"

void _CommandInput::getInput()
{
    string buffer;
    bool valid_input = false;
    while( !valid_input )
    {
        printf("(Enter a command)---> ");
        getline(cin, buffer);
        for( int i = 0; i < (int)buffer.size(); i++ )
        {
            if( buffer[i] == '\n' || buffer[i] == '\0' )
                break;
            if( isalpha(buffer[i]) )
            {
                valid_input = true;
                command = buffer[i];
            }
        }
        if( !valid_input )
            printf("Your input was invalid, please try again.\n" );
    }
}

void _BooleanInput::getInput()
{
    string buffer;
    bool valid_input = false;
    while( !valid_input )
    {
        printf("(Enter [Y]es or [N]o)---> ");
        getline(cin, buffer);
        for( int i = 0; i < (int)buffer.size(); i++ )
        {
            if( buffer[i] == '\n' || buffer[i] == '\0' )
                break;
            if( toupper(buffer[i]) == 'Y' )
            {
                boolean = true;
                valid_input = true;
            }
            else if( toupper(buffer[i]) == 'N' )
            {
                boolean = false;
                valid_input = true;
            }
        }
        if( !valid_input )
            printf("Your input was invalid, please try again.\n" );
    }
}

void _CommandArgumentInput::getInput()
{
    char buffer[25];
    cin.get( buffer, 24 );
}

void _CommandNumberInput::getInput()
{
    //TODO
}

void _NumberNumberInput::getInput()
{
    //TODO
}

string EnterPlayerName( )
{
    string buffer;
    bool good_input = false;
    while( !good_input )
    {
        BooleanInput command;
        printf( "(Enter your name)---> " );
        getline(cin, buffer);
        printf("Do you want to keep \"%s\" as your name?\n", buffer.c_str() );
        command.getInput();
        good_input = command.boolean;
    }
    return buffer;
}
