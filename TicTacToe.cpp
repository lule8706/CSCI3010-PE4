#include <iostream>

int ** CreateBoard () {
  int **answer = new int*[3];

  for (int i = 0; i < 3; i++) {
	  answer[i] = new int[3];
  }

  return answer;
}


void DisplayBoard(int **board){
	//Iterates through the rows first, the colums so it can print out rows before endline
	for(int row = 0; row < 3; row++){
		for(int col = 0; col < 3; col++){
			std::cout << board[row][col];
		}
		std::cout << std::endl;
	}
}

int main(int argc, char const *argv[]) {
  int **board = CreateBoard();

  DisplayBoard(board);
  return 0;
}
