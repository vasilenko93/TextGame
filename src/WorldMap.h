#ifndef WORLDMAP_H
#define WORLDMAP_H

// Give credit where credit is due
// http://stackoverflow.com/a/523737
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

#include <string>
#include <iostream>

using namespace std;

const static int kBitsPerTile = 16;

enum TerrainTypes { GRASSLAND = 0, ROCKY, TUNDRA, SNOW, DESERT, FOREST, JUNGLE,
                    FLOOD_PLAINS, MARSH, OCEAN, HILLS, EMPTY1, EMPTY2, EMPTY3,
                    DROPPED_ITEM, SPECIAL };

typedef struct
{
    bool bits[16];
}Tile;

class Quadrant;

class WorldMap
{
public:
    WorldMap(  );

    void PrintLocation( const int );

private:
    Quadrant* current_quadrant = 0;
    Quadrant* north_qudrant    = 0;
    Quadrant* south_quadrant   = 0;
    Quadrant* west_quadrant    = 0;
    Quadrant* east_quadrant    = 0;
    Quadrant* north_west_quadrant = 0;
    Quadrant* north_east_quadrant = 0;
    Quadrant* south_west_quadrant = 0;
    Quadrant* south_east_quadrant = 0;

    string filename;
    int total_quadrants_x = 0;
    int total_quadrants_y = 0;


    void PrintTileInfo( const Tile* );
    const char* GetTerrainString( const TerrainTypes );
    TerrainTypes GetTerrainType( const Tile* tile );

};

class Quadrant
{
public:
    Quadrant( const int = 0 );

    Tile* getTile( const int );
    Tile* getTile( int, int );

    int getQuadrantPosition( ) { return quadrant_position; };


private:
    const int kQuadrantPrefetchZone = 5;
    const int kTilesPerQuadrant     = 100;
    const short kDefaultTileValue   = (short) 1;

    short *quadrant_array = 0;
    int quadrant_position;


    void GenerateEmptyQuadrant( const int );

};

#endif
