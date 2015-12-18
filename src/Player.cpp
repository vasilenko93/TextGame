#include "Player.h"


Player::Player( int position )
: LivingCreature( position )
{
    name = EnterPlayerName( );

}
