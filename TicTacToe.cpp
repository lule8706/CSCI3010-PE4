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
