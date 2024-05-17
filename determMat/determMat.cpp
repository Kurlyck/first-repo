#include <iostream>
#include <vector>

using matrix_t = std::vector<std::vector<double>>;
using mass_t = std::vector<double>;

double determinant2x2(matrix_t& matrix) {
    return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
}

double determinant(matrix_t& matrix) {
    setlocale(LC_ALL, "Russian");
    int n = matrix.size();

    if (n == 2) {
        return determinant2x2(matrix);
    }

    double det = 0;

    // Рекурсивное вычисление определителя
    for (int i = 0; i < n; i++) {
        matrix_t submatrix(n - 1, mass_t(n - 1));

        for (int j = 1; j < n; j++) {
            int k = 0;
            for (int l = 0; l < n; l++) {
                if (l != i) {
                    submatrix[j - 1][k] = matrix[j][l];
                    k++;
                }
            }
        }

        det += matrix[0][i] * determinant(submatrix) * (i % 2 == 0 ? 1 : -1);
    }

    std::cout << "Определитель матрицы: " << det << std::endl;
}

int main() {
    matrix_t matrix{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    determinant(matrix);
}