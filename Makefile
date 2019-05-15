install:
		mkdir -p bin && g++ main.cpp sources/Matrix.cpp sources/Neuron.cpp  -g -Wall -Werror -o bin/main -std=c++17
