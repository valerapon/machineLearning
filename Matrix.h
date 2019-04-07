#include <iostream>
#include <vector>
#include <utility>

class Matrix {
    int row_, col_;
    std::vector<std::vector<double>> data_;
public:
    Matrix();
    Matrix(const int row, const int col);
    Matrix(const std::vector<double> &vector);
    std::pair<int, int> getSize() const;
    Matrix operator+(Matrix &right) const;
    Matrix operator-(Matrix &right) const;
    Matrix operator*(Matrix &right) const;
    Matrix operator*(std::vector<double> &right) const;
    Matrix operator*(const double value) const;
    Matrix operator=(Matrix right);
    std::vector<double> &operator[](const int index);
    void print() const;
};