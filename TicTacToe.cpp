#include <iostream>

int ** CreateBoard () {
  int **answer = new int*[3];

  for (int i = 0; i < 3; i++) {
	  answer[i] = new int[3];
  }

  return answer;
}

/**
  Displays 3x3 tic-tac-toe board.

  @param board 3x3 matrix containing int values 0-2 representing tic-tac-toe symbols.
*/
void DisplayBoard(int **board) {

  for (int i = 0; i < 3; i++) {

    for (int j = 0; j < 3; j++) {

      if (board[i][j] == 0) { // 0 represents empty
        std::cout << "~";
      } else if (board[i][j] == 1) { // 1 represents X
        std::cout << "X";
      } else { // 2 or any other numbers represent O
        std::cout << "O";
      }
    }

    std::cout << std::endl;
  }
}

/**
  Places the respective marker at the location in the function argument.

  @param pos 2-element array containing position
  @param marker Number code for marker
  @param board Board to be changed
*/
void PlaceMarker(int *pos, int marker, int **board) {
  board[pos[0]][pos[1]] = marker;
}

int main(int argc, char const *argv[]) {
  int **board = CreateBoard();

  DisplayBoard(board);
  return 0;
}
