#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <cctype>
#include <climits>

using namespace std;

struct _CommandInput{
    char command;

    void getInput();
};
struct _CommandArgumentInput{
    char command;
    char argument;

    void getInput();
};
struct _CommandNumberInput{
    char command;
    int  number;

    void getInput();
};
struct _NumberNumberInput{
    int number1;
    int number2;

    void getInput();
};


typedef struct _CommandInput CommandInput;
typedef struct _CommandArgumentInput CommandArgumentInput;
typedef struct _CommandNumberInput CommandNumberInput;
typedef struct _NumberNumberInput NumberNumberInput;

#endif
