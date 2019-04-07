#include <iostream>
#include <vector>
#include <utility>
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

Matrix::Matrix(const std::vector<double> &vector) {
    row_ = vector.size();
    col_ = 1;
    data_.resize(row_, std::vector<double>(1));
    for (int i = 0; i < row_; ++i) {
        data_[i][0] = vector[i];
    }
}

std::pair<int, int> Matrix::getSize() const {
    return std::pair<int, int>(row_, col_);
}

Matrix Matrix::operator+(Matrix right) const {
    Matrix newMatrix(row_, col_);
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            newMatrix[i][j] = data_[i][j] + right[i][j];
        }
    }
    return newMatrix;
}

Matrix Matrix::operator-(Matrix right) const {
    Matrix newMatrix(row_, col_);
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            newMatrix[i][j] = data_[i][j] - right[i][j];
        }
    }
    return newMatrix;
}

Matrix Matrix::operator*(Matrix right) const {
    double Sum = 0;
    Matrix newMatrix(row_, right.getSize().second);
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < right.getSize().second; ++j) {
            Sum = 0;
            for (int k = 0; k < col_; ++k) {
                Sum += data_[i][k] * right[k][j];
            }
            newMatrix[i][j] = Sum;
        }
    }
    return newMatrix;
}

Matrix Matrix::operator*(std::vector<double> right) const {
    double Sum = 0;
    Matrix newMatrix(row_, 1);
    for (int i = 0; i < row_; ++i) {
        Sum = 0;
        for (int j = 0; j < col_; ++j) {
            Sum += data_[i][j] * right[j];
        }
        newMatrix[i][0] = Sum;
    }
    return newMatrix;
}

Matrix Matrix::operator*(const double value) const {
    Matrix newMatrix(row_, col_);
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            newMatrix[i][j] = data_[i][j] * value;
        }
    }
    return newMatrix;
}

Matrix Matrix::operator=(Matrix right) {
    if (row_ == 0 || col_ == 0) {
        row_ = right.getSize().first;
        col_ = right.getSize().second;
        data_.resize(row_, std::vector<double>(col_, 0));
    }
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

Matrix Matrix::transpose() {
    Matrix newMatrix(col_, row_);
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            newMatrix[j][i] = data_[i][j];
        }
    }
    return newMatrix;
}

void Matrix::print() const {
    for (int i = 0; i < row_; ++i) {
        for (int j = 0; j < col_; ++j) {
            std::cout << data_[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}
