#include <iostream>
#include "Matrix.h"
#include "Neuron.h"

int main() {
    int vCount, vSizeX, vSizeY;
    std::vector<std::vector<double>> xVector, yVector;
    std::vector<double> xTest, yTest;
    std::cout << "Enter number of vectors:" << std::endl;
    std::cin >> vCount;
    std::cout << "Enter size of vectors x:" << std::endl;
    std::cin >> vSizeX;
    std::cout << "Enter size of vectors y:" << std::endl;
     std::cin >> vSizeY;
    Neuron neuron(vSizeY, vSizeX);
    xVector.resize(vCount, std::vector<double>(vSizeX));
    yVector.resize(vCount, std::vector<double>(vSizeY));
    xTest.resize(vSizeX);
    yTest.resize(vSizeY);
    std::cout << "Enter x vectors:" << std::endl;
    for (int i = 0; i < vCount; ++i) {
        for (int j = 0; j < vSizeX; ++j) {
            std::cin >> xVector[i][j];
        }
    }
    std::cout << "Enter y vectors:" << std::endl;
    for (int i = 0; i < vCount; ++i) {
        for (int j = 0; j < vSizeY; ++j) {
            std::cin >> yVector[i][j];
        }
    }
    std::cout << "Enter x test vector:" << std::endl;
    for (int i = 0; i < vSizeX; ++i) {
        std::cin >> xTest[i];
    }
    neuron.train(xVector, yVector);
    Matrix ans = neuron.test(xTest);
    ans.print();
    return 0;
}
