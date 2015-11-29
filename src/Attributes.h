#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H

enum SkillTypes { STRENGTH = 0, STAMINA, DEXTERITY, INTELLIGENCE, LUCK, CHARISMA,

                SWORDSMANSHIP, ARCHERY, WOODCUTTING, GATHERING, MINING,
                FARMING, FISHING, COOKING, HEALING, MEDICINE, CRAFTING,
                READING, WRITING };

typedef struct
{
    unsigned char level;
    int  experiance;
} Skills;

class Attributes
{
public:
    Attributes( bool = true );

    char getskilllevel( SkillTypes );
    int  getskillxp( SkillTypes );
    int  getnextlevelxp( SkillTypes );

    void setskill( SkillTypes, char );
    void upgradeskill( SkillTypes );
    void gainexperiance( SkillTypes, int );

    bool Has_Skills( ) { return has_skills; };

    static Attributes* GenerateMalePlayerAttributes();
    static Attributes* GenerateFemalePlayerAttributes();
    static Attributes* GenerateBearAttributes();
    // .
    // .
    // .
    // Hope this works

private:
    bool    has_skills;
    Skills* skills = 0;

    const int  kTotalAttributes = 6;
    const int  kTotalSkills     = 13;
    const char kMaxLevel        = 125;

    void GenerateBlankSkills( );
    //int GetIndexBySkill( SkillTypes ); //Do not need this anymore
};

#endif
