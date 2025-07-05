#include <iostream>
#include <cmath>
#include <vector>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);

    char choice;
    
    do {
        double a, b, R;
        cout << "Введите координаты центра окружности (a b): ";
        cin >> a >> b;
        cout << "Введите радиус окружности R: ";
        cin >> R;

        double x[3], y[3];
        cout << "Введите координаты трёх точек (x1 y1 x2 y2 x3 y3): ";
        for (int i = 0; i < 3; i++) {
            cin >> x[i] >> y[i];
        }

        vector<int> inside_points;
        for (int i = 0; i < 3; i++) {
            double distance_squared = pow(x[i] - a, 2) + pow(y[i] - b, 2);
            if (distance_squared < R * R) {
                inside_points.push_back(i);
            }
        }

        cout << "Количество точек внутри окружности: " << inside_points.size() << endl;
        if (!inside_points.empty()) {
            cout << "Это точки с координатами: ";
            for (int idx : inside_points) {
                cout << "(" << x[idx] << ", " << y[idx] << ") ";
            }
            cout << endl;
        }

        cout << "Начать с начала? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
