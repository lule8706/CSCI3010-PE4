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

//Is passed a pointer to an array that holds the choices
void GetPlayerChoice(int *choice){
	bool done = false;
	while(!done){
		done = true;
		std::cout << "what row would you like? " << std::endl;
		std::cin >> choice[0];
		if((choice[0] > 2) | (choice[0] < 0)){
			std::cout << "Please choose a row between 0 and 2" << std::endl;
			done = false;
		}
		else{
			std::cout << "what column would you like? " << std::endl;
			std::cin >> choice[1];
			if((choice[1] > 2) | (choice[1] < 0)){
				std::cout << "Please choose a column between 0 and 2" << std::endl;
				done = false;
			}
		}
	}
}

int main(int argc, char const *argv[]) {
  int **board = CreateBoard();
  
  DisplayBoard(board);

  return 0;
}
