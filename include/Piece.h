#ifndef PIECE_H
#define PIECE_H

#include "../src/gl_canvas2d.h"


class Piece
{
   public:
      Piece();
      virtual ~Piece();

      unsigned char x,y;
      unsigned short printPositionX;
      unsigned short printPositionY;
      unsigned char team;
      bool king;
      bool alive;
      unsigned char id;
      unsigned char radius;

      void calculatePrintPositions(unsigned short x, unsigned short y, unsigned short tileSize);


   protected:

   private:
};

#endif // PIECE_H
