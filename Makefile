CXX = g++
CXXFLAGS = -std=c++17 -Wall

all: main

main:
	$(CXX) $(CXXFLAGS) -o main TicTacToe.cpp

clean:
	rm main
