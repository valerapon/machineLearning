#ifndef NEURON_H
#define NEURON_H

#include <iostream>
#include <vector>
#include "../headers/Matrix.h"

class Neuron {
    Matrix matrix_, b_;
public:
    Neuron();
    Neuron(int row, int col);
    double difference(Matrix &a, Matrix &b) const;
    void train(std::vector<std::vector<double>> xVectors, std::vector<std::vector<double>> yVectors);
    Matrix test(std::vector<double> xVector) const;
};

#endif