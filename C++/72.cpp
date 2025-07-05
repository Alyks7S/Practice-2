#include <iostream>
#include <cmath>
#include <windows.h> 

void inputPoints(double x[], double y[], int &n) {
    SetConsoleOutputCP(CP_UTF8);
    std::cout << "Введите количество точек: ";
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cout << "Точка " << i + 1 << ": ";
        std::cin >> x[i] >> y[i];
    }
}

void printPoints(double x[], double y[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << "(" << x[i] << ", " << y[i] << ")" << std::endl;
    }
}

bool isInSquare(double x, double y, double R) {
    return (fabs(x) < R) && (fabs(y) < R);
}

void filterPoints(double x[], double y[], int &n, double R) {
    int new_n = 0;
    for (int i = 0; i < n; i++) {
        if (isInSquare(x[i], y[i], R)) {
            x[new_n] = x[i];
            y[new_n] = y[i];
            new_n++;
        }
    }
    n = new_n;
}

int main() {
    const int MAX_POINTS = 100;
    double x[MAX_POINTS], y[MAX_POINTS];
    int n;
    double R;

    inputPoints(x, y, n);
    std::cout << "Исходные точки:" << std::endl;
    printPoints(x, y, n);

    std::cout << "Введите R: ";
    std::cin >> R;

    filterPoints(x, y, n, R);
    std::cout << "Точки внутри квадрата |x| < " << R << ", |y| < " << R << ":" << std::endl;
    printPoints(x, y, n);

    return 0;
}