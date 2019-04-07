#include <iostream>
#include <vector>

class Matrix {
    int row_, col_;
    std::vector<std::vector<double>> data_;
public:
    Matrix();
    Matrix(const int row, const int col);
    Matrix operator+(Matrix &right) const;
    Matrix operator-(Matrix &right) const;
    Matrix operator*(Matrix &right) const;
    Matrix operator=(Matrix &right);
    Matrix operator=(Matrix right);
    std::vector<double> &operator[](const int index);
    void print() const;
};