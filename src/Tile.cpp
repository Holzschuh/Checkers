#include "Tile.h"

Tile::Tile()
{
   x = -1;
   y = -1;
   printPositionX = -1;
   printPositionY = -1;

   pieceOnTile = NULL;


}

Tile::~Tile()
{
   //dtor
}

void Tile::highlight(const float& r, const float& g, const float& b, const char &size){
   setColor(r,g,b);
   rectFill(
      printPositionX,
      printPositionY,
      printPositionX + size,
      printPositionY + size
   );
   setColor(TILE_BLACK);
   if(color) setColor(TILE_WHITE);
   rectFill(
      printPositionX + 5,
      printPositionY + 5,
      printPositionX + size - 5,
      printPositionY + size - 5
   );
}










