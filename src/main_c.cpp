/*********************************************************************
// Canvas para desenho - Versao C.
//  Autor: Cesar Tadeu Pozzer
//         10/2007
//
//  Pode ser utilizada para fazer desenhos ou animacoes, como jogos simples.
//  Tem tratamento de mosue
//  Estude o OpenGL antes de tentar compreender o arquivo gl_canvas.cpp
//
//  Instruções:
//	  Para alterar a animacao, digite numeros entre 1 e 5
// *********************************************************************/

#include "GL/glut.h"
#include "GL/freeglut_ext.h" //callback da wheel do mouse.


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Board.h"


Board board;
bool firstTime = true;

//variaveis globais


//funcao chamada continuamente. Deve-se controlar o que desenhar por meio de variaveis
//globais que podem ser setadas pelo metodo keyboard()
void render(){
    if(firstTime)
    {
        board.initBoard();
        firstTime = false;
    }
//   printf("%d\n",board.nPieces);

    clear(0,0,0.2);

    board.print();

}



//funcao chamada toda vez que uma tecla for pressionada
void keyboard(int key){
    printf("\nTecla: %d", key);

   switch(key){
   case 27: /// escape
      exit(0);
      break;

   case 200: /// seta para a esquerda
      if(board.selectTile.j > 0) board.selectTile.j--;
      else board.selectTile.j = board.sizeX-1;
      break;

   case 201: /// seta para cima
      if(board.selectTile.i < board.sizeY-1) board.selectTile.i++;
      else board.selectTile.i = 0;
      break;

   case 203: /// seta para a baixo
      if(board.selectTile.i > 0) board.selectTile.i--;
      else board.selectTile.i = board.sizeY-1;
      break;

   case 202: /// seta para direita
      if(board.selectTile.j < board.sizeX-1) board.selectTile.j++;
      else board.selectTile.j = 0;
      break;

   case 'x': /// cancel
      board.cancelSelection();
      break;
   case 32:  /// espaço
      if(board.hasSelectedTile){
         if(board.selectedAgain()) board.cancelSelection();
         board.movePiece();
      }
      else board.setSelectedTile();
      break;
   case '1':
      board.player1 = true;
      break;
   case '2':
      board.player1 = false;
      break;
   }
}
//funcao chamada toda vez que uma tecla for liberada
void keyboardUp(int key)
{
    printf("\nLiberou tecla: %d", key);
}


//funcao para tratamento de mouse: cliques, movimentos e arrastos
void mouse(int button, int state, int wheel, int direction, int x, int y)
{
    y = TELAY - y;

    printf("\nmouse %d %d %d %d %d %d", button, state, wheel, direction,  x, y);

}

int main(void)
{

    initCanvas(TELAX, TELAY, "Titulo da Janela: Canvas 2D");

    runCanvas();

}
