int ** CreateBoard () {
  int **answer = new int*[3];

  for (int i = 0; i < 3; i++) {
    answer[i] = new int[3];
  }

  return answer;
}

int main(int argc, char const *argv[]) {
  int **board = CreateBoard();

  return 0;
}
