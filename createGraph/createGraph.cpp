#include <iostream>
#include <fstream>
#include <cmath>

// Функция, которую нужно вычислить
double myFunction(double x) {
    return cos(4 + 32 * x - 2 * pow(x, 3)); // Пример функции x^2
}

// Функция записи аргументов и функций
void writeGraph(const std::string& filename, double startX, double endX, double step) {
    std::ofstream file(filename); // Открываем файл для записи

    double x = startX;
    file << "x" << "\t" << "y" << std::endl;
    while (x <= endX) {
        double y = myFunction(x); // Вычисляем значение функции

        file << x << "\t" << y << std::endl; // Записываем аргумент и значение функции в файл

        x += step; // Увеличиваем аргумент на шаг
    }

    file.close(); // Закрываем файл
}

int main() {
    setlocale(LC_ALL, "Russian");
    double startX = 1;
    double endX = 10.0;
    double step = 1;

    std::string filename = "output.txt";

    writeGraph(filename, startX, endX, step);

    std::cout << "Значения функции успешно сохранены в файле " << filename << std::endl;

    return 0;
}
