#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <cctype>
#include <climits>

using namespace std;

typedef struct
{
    char command;

    void getInput()
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

} CommandInput;

typedef struct
{
    char command;
    char argument;

    void getInput()
    {
        char buffer[25];
        cin.get( buffer, 24 );
    }
} CommandArgumentInput;

typedef struct
{
    char command;
    int  number;

    void getInput()
    {
        //TODO
    }
} CommandNumberInput;

typedef struct
{
    int number1;
    int number2;

    void getInput()
    {
        //TODO
    }
} NumberNumberInput;

#endif
