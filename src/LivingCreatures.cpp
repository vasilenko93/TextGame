#include "LivingCreature.h"

LivingCreature::LivingCreature( int pos, int mhealth, bool need_skills )
{
    max_health = mhealth;
    position   = pos;

    attributes = new Attributes( need_skills );
}

//Subtracts health from creature. Can only subtract.
void LivingCreature::takehealth( int ammount )
{
    if( ammount < 0 )
        health = health - ( ammount * -1);
    else
        health = health - ammount;

    if( health < 0 )
        health = 0;
}

//Gives health to creature. Can only give.
void LivingCreature::givehealth( int ammount )
{
    if( ammount < 0 )
        health = health + ( ammount * -1);
    else
        health = health + ammount;

    if( health > max_health )
        health = max_health;
}

void LivingCreature::setname( string newname )
{   name = newname; }
