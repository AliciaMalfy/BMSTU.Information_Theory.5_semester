#include <iostream>
using namespace std;

int main() {
    int mas1[5][3] = {
            1, 1, 1,
            0, 1, 0,
            0, 1, 0,
            0, 1, 0,
            1, 1, 1,
    };

    int mas2[5][3] = {
            1, 0, 1,
            1, 0, 1,
            1, 0, 1,
            1, 0, 1,
            0, 1, 0,
    };

    int mas3[5][3] = {
            1, 0, 1,
            1, 0, 1,
            0, 1, 0,
            1, 0, 1,
            1, 0, 1,
    };

    int x1[15] = {1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1};
    int x2[15] = {1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0};
    int x3[15] = {1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1};

    int x[3][15] = {
            1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,
            1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0,
            1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
    };

    int x_T[15][3];

    cout << "Матрица векторов X:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 15; j++) {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 3; j++) {
            x_T[i][j] = x[j][i];
        }
    }

    cout << "Матрица векторов X транспонированная:" << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 3; j++) {
            cout << x_T[i][j] << " ";
        }
        cout << endl;
    }

    int W[15][15];

    cout << endl;

    for (int k = 0; k < 15; k++) {
        int sum = 0;
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 3; j++) {
                sum = sum + x_T[i][j] * x[j][k];
            }
            W[i][k] = sum;
        }
    }

    cout << "Вектор W:" << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (W[i][j] < 10) {
                cout << W[i][j] << "  ";
            } else {
                cout << W[i][j] << " ";
            }
        }
        cout << endl;
    }

    cout << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (i == j) {
                W[i][j] = 0;
            }
        }
    }

    cout << "Обнуляем главную диагональ:" << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (W[i][j] < 10) {
                cout << W[i][j] << "  ";
            } else {
                cout << W[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
