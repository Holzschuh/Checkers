#include "Board.h"



Board::Board(){
   p1 = NULL;
   p2 = NULL;

   sizeX = 8;
   sizeY = 8;

   tileSize = (END_TAB_X - INIT_TAB_X)/sizeX;

//   nPieces = (sizeX*0.5 + sizeY*0.5 - 1);
   nPieces = 12;

   selectTile.j = 0;
   selectTile.i = 0;

   selectedTile.j = -1;
   selectedTile.i = -1;

   hasSelectedTile = false;
   player1 = true;

}

Board::~Board()
{
   free(p1);
   free(p2);
}



void Board::print(){
   for(char i=0; i<sizeY; i++){
      for(char j=0; j<sizeX; j++){
         setColor(TILE_BLACK);
//         if(tiles[i][j].pieceOnTile == NULL) setColor(1,0,1);
         if(tiles[i][j].color) setColor(TILE_WHITE);

         rectFill(
            tiles[i][j].printPositionX,
            tiles[i][j].printPositionY,
            tiles[i][j].printPositionX + tileSize,
            tiles[i][j].printPositionY + tileSize
         );
      }
   }
   highlightPossibleMoves();
   tiles[selectTile.i][selectTile.j].highlight(TILE_SELECT, tileSize);
   if(selectedTile.j < sizeX) tiles[selectedTile.i][selectedTile.j].highlight(TILE_SELECTED, tileSize);

   setColor(PLAYER_COLOR_1);
   printPieces(p1);
   setColor(PLAYER_COLOR_2);
   printPieces(p2);



}

void Board::printPieces(Piece *player){
   for(char i=0; i<nPieces; i++){
      if(player[i].alive){
         circleFill(player[i].printPositionX,
                    player[i].printPositionY,
                    player[i].radius, 15
         );
      }
   }
}

void Board::highlightPossibleMoves(){
   for(int i=0; i<possibleMoves.size(); i++){
      tiles[possibleMoves[i]->i][possibleMoves[i]->j].highlight(TILE_POSSIBLE_MOVES, tileSize);
   }

}

void Board::initBoard(){
   tileSize = (END_TAB_X - INIT_TAB_X)/sizeX;

   for(char i=0; i<sizeY; i++){
      for(char j=0; j<sizeX; j++){
         tiles[i][j].color = 1;
         if((i+j)%2) tiles[i][j].color = 0;
         tiles[i][j].printPositionX = INIT_TAB_X + j*tileSize;
         tiles[i][j].printPositionY = INIT_TAB_Y + i*tileSize;
      }
   }
   initPieces();
   selectTile.i=0;
   selectTile.j=0;
}

void Board::initPieces(){

   p2 = (Piece*)malloc(nPieces * sizeof(Piece));
   p1 = (Piece*)malloc(nPieces * sizeof(Piece));
   char placedPieces1 = 0;
   char placedPieces2 = 0;
   for(char i=0; i<sizeY * 0.5 - 1; i++){
      for(char j=0; j<sizeX; j++){
         if((i+j)%2){
//            printf("\n%d, %d\n", selectTile.i, selectTile.i);
            p1[placedPieces1].x = j;
            p1[placedPieces1].y = i;
            p1[placedPieces1].team = 1;
            p1[placedPieces1].id = placedPieces1;
            p1[placedPieces1].radius = tileSize*0.4;

            p1[placedPieces1].calculatePrintPositions(
               tiles[p1[placedPieces1].y][p1[placedPieces1].x].printPositionX,
               tiles[p1[placedPieces1].y][p1[placedPieces1].x].printPositionY,
               tileSize
            );

            p1[placedPieces1].alive = true;
            tiles[i][j].pieceOnTile = &p1[placedPieces1];

            placedPieces1++;
         }
         else{
//            printf("\n%d, %d\n", selectTile.i, selectTile.i);
            p2[placedPieces2].x = j;
            p2[placedPieces2].y = sizeY - i;
            p2[placedPieces2].team = 2;
            p2[placedPieces2].id = placedPieces2;
            p2[placedPieces2].radius = tileSize*0.4;

            p2[placedPieces2].calculatePrintPositions(
               tiles[p2[placedPieces2].y-1][p2[placedPieces2].x].printPositionX,
               tiles[p2[placedPieces2].y-1][p2[placedPieces2].x].printPositionY,
               tileSize
            );

            p2[placedPieces2].alive = true;
            tiles[p2[placedPieces2].y-1][p2[placedPieces2].x].pieceOnTile = &p2[placedPieces2];

            placedPieces2++;
         }
      }
   }
}

void Board::setSelectedTile(){
   if(tiles[selectTile.i][selectTile.j].pieceOnTile != NULL){
      if
      ((player1 && tiles[selectTile.i][selectTile.j].pieceOnTile->team == 1) ||
      (!player1 && tiles[selectTile.i][selectTile.j].pieceOnTile->team == 2)){
         selectedTile.j = selectTile.j;
         selectedTile.i = selectTile.i;
         hasSelectedTile = true;
         hasPossibleMove = false;
         calculatePossibleMoves();
         if(!hasPossibleMove) cancelSelection();
      }
   }
}

void Board::movePiece(){
   for(unsigned char i=0; i<possibleMoves.size(); i++){
      if(selectTile.i == possibleMoves[i]->i  &&  selectTile.j == possibleMoves[i]->j){
         tiles[selectTile.i][selectTile.j].pieceOnTile = tiles[selectedTile.i][selectedTile.j].pieceOnTile;
         tiles[selectedTile.i][selectedTile.j].pieceOnTile = NULL;

         tiles[selectTile.i][selectTile.j].pieceOnTile->x = selectTile.i;
         tiles[selectTile.i][selectTile.j].pieceOnTile->y = selectTile.j;
         tiles[selectTile.i][selectTile.j].pieceOnTile->calculatePrintPositions(
            tiles[selectTile.i][selectTile.j].printPositionX,
            tiles[selectTile.i][selectTile.j].printPositionY,
            tileSize
         );

         if(possibleMoves[i]->killedPieceI != -1){
            killPiece(possibleMoves[i]->killedPieceI, possibleMoves[i]->killedPieceJ);
         }

         player1 = !player1;
         cancelSelection();
      }
   }
}

void Board::killPiece(char i, char j){
   tiles[i][j].pieceOnTile->alive = false;
   tiles[i][j].pieceOnTile = NULL;
}

void Board::calculatePossibleMoves(){
   bool someoneDies = false;

   if(selectedTile.i < sizeY-1 && player1){
      if(selectedTile.j < sizeX-1){
         if(tiles[selectedTile.i+1][selectedTile.j+1].pieceOnTile == NULL){
            possibleMoves.push_back(new MatrixIndex(selectedTile.i+1, selectedTile.j+1));
            hasPossibleMove = true;
         }
         else if(tiles[selectedTile.i+1][selectedTile.j+1].pieceOnTile->team == 2){
            if(selectedTile.i+2 < sizeY  &&  selectedTile.j+2 < sizeX){
               if(tiles[selectedTile.i+2][selectedTile.j+2].pieceOnTile == NULL){
                  possibleMoves.push_back(new MatrixIndex(selectedTile.i+2, selectedTile.j+2, selectedTile.i+1, selectedTile.j+1));
                  hasPossibleMove = true;
                  someoneDies = true;
               }
            }
         }
      }
      if(selectedTile.j > 0){
         if(tiles[selectedTile.i+1][selectedTile.j-1].pieceOnTile == NULL){
            possibleMoves.push_back(new MatrixIndex(selectedTile.i+1, selectedTile.j-1));
            hasPossibleMove = true;
         }
         else if(tiles[selectedTile.i+1][selectedTile.j-1].pieceOnTile->team == 2){
            if(selectedTile.i+2 < sizeY  &&  selectedTile.j-2 >= 0){
               if(tiles[selectedTile.i+2][selectedTile.j-2].pieceOnTile == NULL){
                  possibleMoves.push_back(new MatrixIndex(selectedTile.i+2, selectedTile.j-2, selectedTile.i+1, selectedTile.j-1));
                  hasPossibleMove = true;
                  someoneDies = true;
               }
            }
         }
      }
   }

   if(selectedTile.i > 0 && !player1){
      if(selectedTile.j < sizeX-1){
         if(tiles[selectedTile.i-1][selectedTile.j+1].pieceOnTile == NULL){
            possibleMoves.push_back(new MatrixIndex(selectedTile.i-1, selectedTile.j+1));
            hasPossibleMove = true;
         }
         else if(tiles[selectedTile.i-1][selectedTile.j+1].pieceOnTile->team == 1){
            if(selectedTile.i-2 >= 0 &&  selectedTile.j+2 < sizeX){
               if(tiles[selectedTile.i-2][selectedTile.j+2].pieceOnTile == NULL){
                  possibleMoves.push_back(new MatrixIndex(selectedTile.i-2, selectedTile.j+2, selectedTile.i-1, selectedTile.j+1));
                  hasPossibleMove = true;
                  someoneDies = true;
               }
            }
         }
      }
      if(selectedTile.j > 0){
         if(tiles[selectedTile.i-1][selectedTile.j-1].pieceOnTile == NULL){
            possibleMoves.push_back(new MatrixIndex(selectedTile.i-1, selectedTile.j-1));
            hasPossibleMove = true;
         }
         else if(tiles[selectedTile.i-1][selectedTile.j-1].pieceOnTile->team == 1){
            if(selectedTile.i-2 >= 0 &&  selectedTile.j-2 >= 0){
               if(tiles[selectedTile.i-2][selectedTile.j-2].pieceOnTile == NULL){
                  possibleMoves.push_back(new MatrixIndex(selectedTile.i-2, selectedTile.j-2, selectedTile.i-1, selectedTile.j-1));
                  hasPossibleMove = true;
                  someoneDies = true;
               }
            }
         }
      }
   }

   if(someoneDies) removeMovesThatDontKill();
}

void Board::removeMovesThatDontKill(){
   for(unsigned char i=0; i<possibleMoves.size(); i++){
      if(possibleMoves[i]->killedPieceI < 0) possibleMoves.erase(possibleMoves.begin()+i);
   }
}

void Board::cancelSelection(){
   selectedTile.j = -1;
   selectedTile.i = -1;
   hasSelectedTile = false;
   for(int i=0; i<possibleMoves.size(); i++) delete (possibleMoves[i]);
   possibleMoves.clear();
}

bool Board::selectedAgain(){
   return (selectedTile.j==selectTile.j && selectedTile.i==selectTile.i);
}






