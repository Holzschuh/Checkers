#ifndef BOARD_H
#define BOARD_H

#define INIT_TAB_X 100
#define INIT_TAB_Y 0
#define END_TAB_X 700
#define END_TAB_Y 600

#include <vector>
#include "Tile.h"
#include "MatrixIndex.h"
//
//typedef struct{
//   unsigned char i,j;
//}MatrixIndex;

class Board{
   public:
      unsigned char sizeX;
      unsigned char sizeY;
      unsigned char nPieces;
      unsigned char tileSize;

      Tile tiles[8][8];

      Piece *p1;
      Piece *p2;

      MatrixIndex selectTile;
      MatrixIndex selectedTile;

      bool hasPossibleMove;
      bool player1;
      std::vector<MatrixIndex*> possibleMoves;

      bool hasSelectedTile;

      Board();
      virtual ~Board();

      void print();
      void printPieces(Piece *player);
      void movePiece();
      void killPiece(char i, char j);
      void highlightPossibleMoves();
      void setSelectedTile();
      void calculatePossibleMoves();
      void removeMovesThatDontKill();
      void cancelSelection();
      void initBoard();
      void initPieces();
      bool selectedAgain();


   protected:

   private:
};

#endif // BOARD_H
