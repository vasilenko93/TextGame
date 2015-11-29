#include "Attributes.h"

Attributes::Attributes( bool needskills )
{
    has_skills = needskills;

    if( has_skills )
        skills = new Skills[kTotalAttributes + kTotalSkills];
    else
        skills = new Skills[kTotalAttributes];

    GenerateBlankSkills( );
}

char Attributes::getskilllevel( SkillTypes skilltype )
{
    return skills[skilltype].level;
}

int  Attributes::getskillxp( SkillTypes skilltype )
{
    return skills[skilltype].experiance;
}


void Attributes::setskill( SkillTypes skilltype, char newlevel )
{
    if( newlevel <= kMaxLevel )
        skills[skilltype].level = newlevel;
    else
        skills[skilltype].level = kMaxLevel;

    skills[skilltype].experiance = 0;
}

// This is a helper function, all it does is raise the level number
void Attributes::upgradeskill( SkillTypes skilltype )
{
    char current_level = skills[skilltype].level;

    if( current_level == kMaxLevel )
        return;

    skills[skilltype].level = current_level + 1;
}

void Attributes::gainexperiance( SkillTypes skilltype, int experiance )
{
    if( experiance < 0 )
        return;

    char current_level = skills[skilltype].level;
    int  current_experiance = skills[skilltype].experiance;
    int  next_level_experiance = getnextlevelxp( skilltype );

    if( (current_experiance + experiance) >= next_level_experiance )
    {
        int xp_remainder = (current_level + experiance) - next_level_experiance;
        upgradeskill( skilltype );
        skills[skilltype].experiance = xp_remainder;
    }


}

int Attributes::getnextlevelxp( SkillTypes skilltype )
{
    int m = 50; // Multiplier
    int l = skills[skilltype].level;
    if( l == kMaxLevel )
        return (m * l * l * l) - ( m * l );
    else
    {   l++; return (m * l * l * l) - ( m * l ); }
}


void Attributes::GenerateBlankSkills( )
{
    int total = 0;
    if( has_skills )
        total = kTotalAttributes + kTotalSkills;
    else
        total = kTotalAttributes;

    for( int i = 0; i < total; i++)
    {
        skills[i].level      = 0;
        skills[i].experiance = 0;
    }

}

/*
This function is no longer needed. Enums already have
int values assigned to them...the way I need them to be.
int Attributes::GetIndexBySkill( SkillTypes skilltype )
{
    switch (skilltype) {
        //Attributes
        case STRENGTH     : return 0;
        case STAMINA      : return 1;
        case DEXTERITY    : return 2;
        case INTELLIGENCE : return 3;
        case LUCK         : return 4;
        case CHARISMA     : return 5;

        //Skills
        case SWORDSMANSHIP: return 6;
        case ARCHERY      : return 7;
        case WOODCUTTING  : return 8;
        case GATHERING    : return 9;
        case MINING       : return 10;
        case FARMING      : return 11;
        case FISHING      : return 12;
        case COOKING      : return 13;
        case HEALING      : return 14;
        case MEDICINE     : return 15;
        case CRAFTING     : return 16;
        case READING      : return 17;
        case WRITING      : return 18;

        default: return 0; // To remove warnings
    }
    return 0; // To remove warnings
}

*/

Attributes* Attributes::GenerateMalePlayerAttributes()
{
    // Players need attributes and skills. That is why true is set.
    Attributes* attributes = new Attributes( true );
    attributes->setskill( STRENGTH, 15 );
    /*
        *
        * And so on.
        *
    */

    return attributes;
}

Attributes* Attributes::GenerateFemalePlayerAttributes()
{
    // Players need attributes and skills. That is why true is set.
    Attributes* attributes = new Attributes( true );
    attributes->setskill( STRENGTH, 10 );

    return attributes;
}

Attributes* Attributes::GenerateBearAttributes()
{
    // Animals need only attributes. That is why false is set.
    Attributes* attributes = new Attributes( false );

    return attributes;
}
