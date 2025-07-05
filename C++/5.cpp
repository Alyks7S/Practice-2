#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h> 

int main() {
    SetConsoleOutputCP(CP_UTF8);

    double V;
    int N;

    std::cout << "Введите начальную скорость (V, км/ч): ";
    std::cin >> V;
    std::cout << "Введите количество кругов (N): ";
    std::cin >> N;

    std::cout << "———————————————————————————————\n";
    std::cout << "  Круг  |  Скорость (км/ч)  \n";
    std::cout << "———————————————————————————————\n";

    for (int i = 1; i <= N; ++i) {
        double current_speed = V * std::pow(0.9, i - 1);
        std::cout << std::setw(6) << i << "  |  " 
                  << std::fixed << std::setprecision(2) << current_speed << "\n";
    }

    double last_speed = V * std::pow(0.9, N - 1);
    std::cout << "———————————————————————————————\n";
    std::cout << "Скорость на последнем круге: " << last_speed << " км/ч\n";

    return 0;
}