#include <iostream>
#include "Matrix.h"

int main() {
    int row = 0, col = 0;
    std::cin >> row >> col; 
    Matrix m(row, col);
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            m[i][j] = i + j;
        }
    }
    std::vector<double> vec;
    vec.resize(col, 1);
    Matrix q = m * vec;
    m = m * 2;
    m.print();
    q.print();
    return 0;
}
