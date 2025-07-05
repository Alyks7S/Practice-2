#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <windows.h> 

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

double totalDistance(double x[], double y[], int n) {
    double total = 0.0;
    for (int i = 0; i < n - 1; i++) {
        total += distance(x[i], y[i], x[i + 1], y[i + 1]);
    }
    return total;
}

int main() {
     SetConsoleOutputCP(CP_UTF8);
    double x[] = {1.0, 2.0, 3.0, 4.0};
    double y[] = {1.0, 3.0, 2.0, 5.0};
    int n = sizeof(x) / sizeof(x[0]);

    std::cout << "Суммарное расстояние: " << totalDistance(x, y, n) << std::endl;

    return 0;
}