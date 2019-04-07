#include "Matrix.h"

Matrix::Matrix() {
    row_ = 0;
    col_ = 0;
}

Matrix::Matrix(const int row, const int col) {
    row_ = row;
    col_ = col;
    data_.resize(row, std::vector<double>(col, 0));
}

Matrix Matrix::operator+(Matrix &right) const {
    Matrix newMatrix(row_, col_);
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            newMatrix[i][j] = data_[i][j] + right[i][j];
        }
    }
    return newMatrix;
}

Matrix Matrix::operator-(Matrix &right) const {
    Matrix newMatrix(row_, col_);
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            newMatrix[i][j] = data_[i][j] - right[i][j];
        }
    }
    return newMatrix;
}

Matrix Matrix::operator*(Matrix &right) const {
    double Sum = 0;
    Matrix newMatrix(row_, col_);
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            Sum = 0;
            for (int k = 0; k < col_; ++k) {
                Sum += data_[i][k] * right[k][j];
            }
            newMatrix[i][j] = Sum;
        }
    }
    return newMatrix;
}

Matrix Matrix::operator=(Matrix right) {
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            data_[i][j] = right[i][j];
        }
    }
    return right;
}

Matrix Matrix::operator=(Matrix &right) {
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            data_[i][j] = right[i][j];
        }
    }
    return right;
}

std::vector<double> &Matrix::operator[](const int index) {
    return data_[index];
}

void Matrix::print() const {
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            std::cout << data_[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
