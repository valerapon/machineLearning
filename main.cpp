#include <iostream>
#include "Matrix.h"

int main() {
    Matrix m(5, 5);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            m[i][j] = i * j;
        }
    }
    m.print();
    m = m * m;
    m.print();
    return 0;
}
