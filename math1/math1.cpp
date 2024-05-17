#include <iostream>
#include <cmath>

//Итерации
double f3(double x) {
    return (pow(exp(1), (2 - (pow(sin((x + 3) / 2), 2)))));
}

double solution3(double a, double epsilon, double b) {
    double x = (a + b) / 2;
    a = x;
    do {
        x = f3(a);
        b = a;
        a = x;
    } while (abs(x - a) > epsilon);
    return x;
}

//-----------------------------------------

int main() {
    double a = 1.88;
    double b = 2.4;
    double epsilon = 0.0001;

    double solutionResult3 = solution3(a, epsilon, b);

    std::cout << "Solution third method: " << solutionResult3 << std::endl;

    return 0;
}