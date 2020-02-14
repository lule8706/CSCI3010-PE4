/**
Lukas Leibfried, Griffen Cook
PE4
This program allows users to play a game of tic-tac-toe.
*/

#include <iostream>

/**
  Makes a new empty 3x3 board.

  @return New empty 3x3 board
*/
int ** CreateBoard () {
  int **answer = new int*[3]; // Allocates array of int arrays.

  for (int i = 0; i < 3; i++) { // Allocates each array in int array.
	  answer[i] = new int[3];
  }

  for (int row = 0; row < 3; row++) { // Sets each space in array to empty.
    for (int col = 0; col < 3; col++) {
      answer[row][col] = 0;
    }
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

  int turn_count = 0;

  //The choice array is used to store user input
  int *choice = new int[2];

  //uses turn count to run for 9 turns
  while(turn_count < 9){
	  choice = new int[2];
	  DisplayBoard(board);
	  //for 0 through 8 turn_count % 2 will return 0 for 0, 2, 4, 6, 8 aka player ones turn, and 1 for player two's turn
	  //By adding one to this number we can accurately express who's turn it is
	  std::cout << "Player" << (turn_count % 2) + 1<< "'s turn:" << std::endl;
	  GetPlayerChoice(choice);
	  PlaceMarker(choice, (turn_count % 2) + 1, board);
	  turn_count++;
  }

  DisplayBoard(board);

  return 0;
}
