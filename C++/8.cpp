#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

void inputTrees(double x[], double y[], int &n) {
    cout << "Введите количество деревьев: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Дерево " << i + 1 << " (x y): ";
        cin >> x[i] >> y[i];
    }
}

double distance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void findMinEnclosingCircle(double x[], double y[], int n, double &centerX, double &centerY, double &radius) {
    centerX = 0;
    centerY = 0;
    for (int i = 0; i < n; i++) {
        centerX += x[i];
        centerY += y[i];
    }
    centerX /= n;
    centerY /= n;

    radius = 0;
    for (int i = 0; i < n; i++) {
        double dist = distance(centerX, centerY, x[i], y[i]);
        if (dist > radius) {
            radius = dist;
        }
    }
}

double calculateFenceArea(double radius, double height) {
    const double PI = 3.141592653589793;
    return 2 * PI * radius * height;
}

int main() {
    const int MAX_TREES = 100;
    double x[MAX_TREES], y[MAX_TREES];
    int n;
    double centerX, centerY, radius;
    const double FENCE_HEIGHT = 5.0;

    inputTrees(x, y, n);

    findMinEnclosingCircle(x, y, n, centerX, centerY, radius);

    double fenceArea = calculateFenceArea(radius, FENCE_HEIGHT);

    cout << "\nРезультаты:\n";
    cout << "Центр забора: (" << centerX << ", " << centerY << ")\n";
    cout << "Минимальный радиус: " << radius << " м\n";
    cout << "Площадь сетки для забора: " << fenceArea << " м²\n";

    return 0;
}