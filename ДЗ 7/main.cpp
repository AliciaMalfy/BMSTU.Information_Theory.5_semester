#include <iostream>
using namespace std;

int main() {
    int mas1[5][3] = {
            1, 1, 1,
            -1, 1, -1,
            -1, 1, -1,
            -1, 1, -1,
            1, 1, 1,
    };

    int mas2[5][3] = {
            1, -1, 1,
            1, -1, 1,
            1, -1, 1,
            1, -1, 1,
            -1, 1, -1,
    };

    int mas3[5][3] = {
            1, -1, 1,
            1, -1, 1,
            -1, 1, -1,
            1, -1, 1,
            1, -1, 1,
    };

    int x1[15] = {1, 1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, 1, 1};
    int x2[15] = {1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1};
    int x3[15] = {1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1};

    int x[3][15] = {
            1, 1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, 1, 1,
            1, -1, 1, 1, -1, 1, 1, -1, 1, 1, -1, 1, -1, 1, -1,
            1, -1, 1, 1, -1, 1, -1, 1, -1, 1, -1, 1, 1, -1, 1,
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
            if (x_T[i][j] > 0) {
                cout << " " << x_T[i][j] << " ";
            } else {
                cout << x_T[i][j] << " ";
            }
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
            if (W[i][j] < 0) {
                cout << W[i][j] << " ";
            } else {
                cout << " " << W[i][j] << " ";
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

       int n = 1;
    float y = 0.1;

    cout << "Изменим любые два бита в векторах (10%):" << endl;

    for (int i = 0; i < 2; i++) {
        int c = rand() % 15;
        if (x1[c] > 0) {
            x1[c] = -1;
        } else {
            x1[c] = 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        int c = rand() % 15;
        if (x2[c] > 0) {
            x2[c] = -1;
        } else {
            x2[c] = 1;
        }
    }

    for (int i = 0; i < 2; i++) {
        int c = rand() % 15;
        if (x3[c] > 0) {
            x3[c] = -1;
        } else {
            x3[c] = 1;
        }
    }

    for (int i = 0; i < 15; i++) {
        cout << x1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 15; i++) {
        cout << x2[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 15; i++) {
        cout << x3[i] << " ";
    }
    cout << endl << endl;

    cout << "Посчитаем выход нейронов первого слоя:" << endl;

    int x_new[3][15] = {
            1, -1, 1, -1, 1, -1, -1, 1, -1, -1, 1, -1, 1, -1, 1,
            1, -1, 1, 1, -1, 1, 1, -1, 1, 1, 1, 1, 1, 1, -1,
            1, -1, 1, 1, -1, 1, -1, 1, 1, 1, 1, 1, 1, -1, 1,
    };

    cout << "Получим паттерны:" << endl;

    for (int k = 0; k < 15; k++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 15; j++) {
                sum = sum + x[i][j] * W[j][k];
            }
            x_new[i][k] = sum;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 15; j++) {
            cout << x_new[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Посчитаем выход нейронов второго слоя" << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            W[i][j] = W[i][j] + x_new[i][j] * n;
        }
    }

    cout << "Вектор W:" << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (W[i][j] < 0) {
                cout << W[i][j] << " ";
            } else {
                cout << " " << W[i][j] << " ";
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

    cout << "Получим паттерны:" << endl;

    for (int k = 0; k < 15; k++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 15; j++) {
                sum = sum + x[i][j] * W[j][k];
            }
            x_new[i][k] = sum;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 15; j++) {
            cout << x_new[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    cout << "Так как они совпадают по знакам, то преобразуем их и получим исходные вектора:" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 15; j++) {
            if (x_new[i][j] > 0) {
                x_new[i][j] = 1;
                cout << x_new[i][j] << " ";
            } else {
                x_new[i][j] = -1;
                cout << x_new[i][j] << " ";
            };
        }
        cout << endl;
    }

    return 0;
}
