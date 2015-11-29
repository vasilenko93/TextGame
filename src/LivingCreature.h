#ifndef LIVINGCREATURE_H
#define LIVINGCREATURE_H

#include <iostream>
#include <cstring>

#include "Attributes.h"

using namespace std;

class LivingCreature
{
public:
    LivingCreature( int = 0, int = 100, bool = false );

    void takehealth( int );
    void givehealth( int );

    int    gethealth  (){ return health;   };
    int    getposition(){ return position; };
    string getname    (){ return name;     };

    void   setname( string );


protected:
    int health;
    int max_health;
    string name;
    int position;
    Attributes* attributes;
};

#endif
