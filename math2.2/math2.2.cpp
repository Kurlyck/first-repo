#include <iostream>
#include <vector>

using namespace std;

const int n = 3; // Количество уравнений

vector<vector<double>> A = { {34.35, 2.42, 4.85},
                             {2.31, 25.49, 5.52},
                             {3.48, 4.85, 30.04} }; // Матрица коэффициентов
vector<double> B = { 20.14, 10.24, 12.24 }; // Вектор свободных членов

vector<double> Seidel() {
    vector<double> x(n, 0); // Начальное приближение
    vector<double> x_new(n, 0); // Новое значение x

    const int max_iter = 5;
    const double eps = 0.00001;

    for (int k = 0; k < max_iter; k++) {
        for (int i = 0; i < n; i++) {
            double sum1 = 0;
            for (int j = 0; j < i; j++) {
                sum1 += A[i][j] * x_new[j];
            }

            double sum2 = 0;
            for (int j = i + 1; j < n; j++) {
                sum2 += A[i][j] * x[j];
            }

            x_new[i] = (B[i] - sum1 - sum2) / A[i][i];
        }

        double error = 0;

        cout << "Iteration " << k + 1 << ":" << endl;
        for (int i = 0; i < n; i++)
            cout << "x[" << i + 1 << "] = " << x_new[i] << endl;


        for (int i = 0; i < n; i++) {
            error = abs(x[i] - x_new[i]);
            if (error < eps) {
                return x_new;
            }
        }
        x = x_new;
    }

    return x_new;
}

int main() {
    vector<double> result = Seidel();

    cout << "Solution:" << endl;
    for (int i = 0; i < n; i++)
        cout << "x[" << i + 1 << "] = " << result[i] << endl;

    return 0;
}
