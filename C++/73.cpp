#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

void generateRandomPoints(double x[], double y[], int n, double min, double max) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        x[i] = min + (max - min) * (rand() / (double)RAND_MAX);
        y[i] = min + (max - min) * (rand() / (double)RAND_MAX);
    }
}

int* filterByRadius(double x[], double y[], int n, double R, int &new_size) {
    int *indices = new int[n];
    new_size = 0;
    for (int i = 0; i < n; i++) {
        double r = sqrt(x[i] * x[i] + y[i] * y[i]);
        if (r < R) {
            indices[new_size++] = i;
        }
    }
    return indices;
}

int main() {
    const int MAX_POINTS = 100;
    double x[MAX_POINTS], y[MAX_POINTS];
    int n;
    double R;

    std::cout << "Введите количество точек: ";
    std::cin >> n;
    generateRandomPoints(x, y, n, -10.0, 10.0);

    std::cout << "Сгенерированные точки:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "(" << x[i] << ", " << y[i] << ")" << std::endl;
    }

    std::cout << "Введите R: ";
    std::cin >> R;

    int filtered_size;
    int *filtered_indices = filterByRadius(x, y, n, R, filtered_size);

    std::cout << "Номера точек с радиусом < " << R << ":" << std::endl;
    for (int i = 0; i < filtered_size; i++) {
        std::cout << filtered_indices[i] << " ";
    }
    std::cout << std::endl;

    delete[] filtered_indices;
    return 0;
}