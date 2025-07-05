#include <iostream>
#include <climits>
using namespace std;

void findSaddlePoint(int mat[][100], int n, int m) {
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        int minInRow = mat[i][0];
        int colIndex = 0;
        
        for (int j = 1; j < m; j++) {
            if (mat[i][j] < minInRow) {
                minInRow = mat[i][j];
                colIndex = j;
            }
        }
        
        bool isSaddle = true;
        for (int k = 0; k < n; k++) {
            if (mat[k][colIndex] > minInRow) {
                isSaddle = false;
                break;
            }
        }
        
        if (isSaddle) {
            cout << "Седловая точка найдена: " << minInRow << endl;
            cout << "Индексы: [" << i << "][" << colIndex << "]" << endl;
            found = true;
            return;
        }
    }
    
    if (!found) {
        cout << "Седловая точка не найдена" << endl;
    }
}

int main() {
    int n, m;
    int mat[100][100];
    
    cout << "Введите размеры матрицы (n m): ";
    cin >> n >> m;
    
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    findSaddlePoint(mat, n, m);
    
    return 0;
}