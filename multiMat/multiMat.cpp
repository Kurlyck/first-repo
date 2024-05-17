#include <iostream>
#include <vector>

using matrix_t = std::vector<std::vector<int>>;


void multiplyMatrix(matrix_t& matrix1, matrix_t& matrix2) {
    setlocale(LC_ALL, "Russian");

    if (matrix1[0].size() != matrix2.size()) {
        std::cout << "Умножение матриц невозможно. Количество столбцов первой матрицы должно быть равно количеству строк второй матрицы.\n";
        return;
    }

    matrix_t resultMatrix(matrix1.size());
    for (int i = 0; i < resultMatrix.size(); i++)
        resultMatrix[i].resize(matrix2[0].size());

    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix2[0].size(); j++) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < matrix1[0].size(); k++) {
                resultMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    std::cout << "Результат умножения матриц:\n";
    for (int i = 0; i < matrix1.size(); i++) {
        for (int j = 0; j < matrix2[0].size(); j++) {
            std::cout << resultMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    matrix_t matrix1{
        {3, 4, 8},
        {5, 2, 1},
        {9, 10, 7}
    };

    matrix_t matrix2{
        {7, 1, 2},
        {6, 2, 0},
        {6, 10, 8}
    };
    multiplyMatrix(matrix1, matrix2);
}