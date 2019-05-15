#include <iostream>
#include <vector>
#include <cmath>
#include "../headers/Neuron.h"

Neuron::Neuron() {}

Neuron::Neuron(int row, int col) {
    matrix_ = Matrix(3, 3);
    b_ = Matrix(row, 1);
}

double Neuron::difference(Matrix &a, Matrix &b) const {
    double Sum = 0.0;
    for (int i = 0; i < a.getSize().first; ++i) {
        for (int j = 0; j < a.getSize().second; ++j) {
            Sum += pow(a[i][j] - b[i][j], 2);
        }
    }
    return sqrt(Sum);
}

void Neuron::train(std::vector<std::vector<double>> xVectors, std::vector<std::vector<double>> yVectors) {
    Matrix newMatrix(yVectors[0].size(), xVectors[0].size()),
           oldMatrix(yVectors[0].size(), xVectors[0].size());
    Matrix newB(yVectors[0].size(), 1),
           oldB(yVectors[0].size(), 1);
    for (int k = 0; k < 10; ++k) {
            oldMatrix = newMatrix;
            oldB = newB;
            Matrix tmpM(yVectors[0].size(), xVectors[0].size());
            Matrix tmpB(yVectors[0].size(), 1);
            for (long unsigned int i = 0; i < xVectors.size(); ++i) {
                tmpM = tmpM + (oldMatrix * xVectors[i] - Matrix(yVectors[i]) + Matrix(oldB)) * (Matrix(xVectors[i])).transpose();
                tmpB = tmpB + (oldMatrix * xVectors[i] - Matrix(yVectors[i]) + Matrix(oldB));
            }
            newMatrix = oldMatrix - tmpM * 0.01;
            newB = oldB - tmpB * 0.01;
           
    }
    matrix_ = newMatrix;
    b_ = newB;
}
Matrix Neuron::test(std::vector<double> xVector) const {
    return matrix_ * xVector;
}