#include "Utilities.h"

void _CommandInput::getInput()
{
    string buffer;
    bool valid_input = false;
    while( !valid_input )
    {
        printf("(Enter a command)---> ");
        //cin.ignore(INT_MAX);
        //cin.clear();
        getline(cin, buffer);
        for( int i = 0; i < 25; i++ )
        {
            if( buffer[i] == '\n' || buffer[i] == '\0' )
                break;
            if( isalpha(buffer[i]) )
            {
                valid_input = true;
                command = buffer[i];
                break;
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
