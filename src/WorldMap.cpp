#include "WorldMap.h"


// WorldMap functions
WorldMap::WorldMap( )
{
    current_quadrant = new Quadrant( 0 );
}

void WorldMap::PrintLocation( const int location )
{
    Tile* current_tile = current_quadrant->getTile( location );
    //Tile* north_tile = 0;
    //Tile* south_tile = 0;
    //Tile* east_tile  = 0;
    //Tile* west_tile  = 0;

    printf( "Your current enviroment: " );
    PrintTileInfo( current_tile );

    printf( "\n" );

    delete current_tile;
    //delete north_tile;
    //delete east_tile;
    //delete west_tile;
}

const char* WorldMap::GetTerrainString( const TerrainTypes terraintype )
{
    switch (terraintype) {
        case GRASSLAND:    return "Grasslands";
        case ROCKY:        return "Rocks";
        case TUNDRA:       return "Tundra";
        case SNOW:         return "Snow";
        case DESERT:       return "Desert";
        case FOREST:       return "Forst";
        case JUNGLE:       return "Jungle";
        case FLOOD_PLAINS: return "Flood Plains";
        case MARSH:        return "Marsh";
        case OCEAN:        return "Ocean";

        default:           return "Grasslands";
    }
    return "Grasslands";
}

TerrainTypes WorldMap::GetTerrainType( const Tile* tile )
{
    TerrainTypes type = GRASSLAND;
    if( !tile )
        return type;

    // The ten is for number of terrain types, exluding hills
    for( int i = 0; i < 10; i++ )
    {
        if( tile->bits[i] )
            type = static_cast<TerrainTypes>(i);
    }

    return type;
}

void WorldMap::PrintTileInfo( const Tile* tile )
{
    if( !tile )
        return;

    const char* tile_type_str = GetTerrainString( GetTerrainType( tile ) );

    if( tile->bits[HILLS] )
        printf( "Uneven %s", tile_type_str );
    else
        printf( "Flat %s", tile_type_str );
}





// Quadrant functions

Quadrant::Quadrant( const int position )
{

    GenerateEmptyQuadrant( position );
}

void Quadrant::GenerateEmptyQuadrant( const int position )
{
    quadrant_position = position;

    if( quadrant_array == 0 || quadrant_array == NULL )
        quadrant_array = new short[ kTilesPerQuadrant * kTilesPerQuadrant ];
    else
        return;

    for( int i = 0; i < kTilesPerQuadrant * kTilesPerQuadrant; i++ )
        quadrant_array[i] = (short) kDefaultTileValue;
}

Tile* Quadrant::getTile( const int position )
{
    Tile* tile = 0;

    if( position >= kTilesPerQuadrant * kTilesPerQuadrant )
        return 0;

    tile = new Tile( );

    short tiledata = quadrant_array[position];
    for( int i = 0; i < kBitsPerTile; i++ )
        tile->bits[i] = CHECK_BIT( tiledata, i );
    return tile;
}

Tile* Quadrant::getTile( int position_x, int position_y )
{
    if( position_x > kTilesPerQuadrant )
        position_x = kTilesPerQuadrant;
    else if( position_y > kTilesPerQuadrant )
        position_y = kTilesPerQuadrant;

    int position = (position_y * kTilesPerQuadrant) + position_x;
    return getTile( position );
}
