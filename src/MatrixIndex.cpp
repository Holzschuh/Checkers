#include "MatrixIndex.h"

MatrixIndex::MatrixIndex()
{
   //ctor
}
MatrixIndex::MatrixIndex(unsigned char i, unsigned char j){
   this->i = i;
   this->j = j;
   killedPieceI = -1;
   killedPieceJ = -1;
}

MatrixIndex::MatrixIndex(unsigned char i, unsigned char j, char killedPieceI, char killedPieceJ){
   this->i = i;
   this->j = j;
   this->killedPieceI = killedPieceI;
   this->killedPieceJ = killedPieceJ;
}

MatrixIndex::~MatrixIndex()
{
   //dtor
}
