#include <iostream>
#include <vector>

using matrix_t = std::vector<std::vector<int>>;
using mass_t = std::vector<int>;

matrix_t transposeMatrix(const matrix_t& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    matrix_t transposed(cols, mass_t(rows));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }

    return transposed;
}

int printMatrix(matrix_t& transp) {
    for (int i = 0; i < transp.size(); i++) {
        for (int j = 0; j < transp[0].size(); j++) {
            std::cout << transp[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

int main() {
    matrix_t matrix { 
        {1, 2, 3, 10},
        {4, 5, 6, 11},
        {7, 8, 9, 12} 
    };

    matrix_t transp = transposeMatrix(matrix);
    printMatrix(transp);
    
    return 0;
}
