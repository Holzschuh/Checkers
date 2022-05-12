#include "Piece.h"

Piece::Piece(){
   x = 0;
   y = 0;
   printPositionX = 0;
   printPositionY = 0;

   id = -1;
   king = false;
   alive = true;
   team = -1;
   radius = 30;
}

Piece::~Piece(){
}

void Piece::calculatePrintPositions(unsigned short x, unsigned short y, unsigned short tileSize){
   this->printPositionX = x + tileSize*0.5;
   this->printPositionY = y + tileSize*0.5;
}
