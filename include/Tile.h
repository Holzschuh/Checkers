#ifndef TILE_H
#define TILE_H

#include "Piece.h"

class Tile
{
   public:
      unsigned short printPositionX;
      unsigned short printPositionY;
      unsigned char x,y;
      unsigned char color;
      Piece *pieceOnTile;

      Tile();
      virtual ~Tile();

      void highlight(const float& r, const float& g, const float& b, const char &size);

   protected:

   private:
};

#endif // TILE_H
