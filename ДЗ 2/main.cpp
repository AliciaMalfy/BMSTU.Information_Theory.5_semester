#include <iostream>

using namespace std;

int main() {
    int U[11] = {1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1};
    int V_sh[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int V_ex[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int H_sh[4][15] = {
            {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
            {0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0},
            {1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0},
            {1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1},
    };

    int H_ex[5][16] = {
            {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
            {0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0},
            {1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0},
            {1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
            {1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
    };

    cout << "Задание 1:" << endl << endl;
    cout << "Укороченный код:" << endl;

    for (int i = 0; i < 11; i++) {
        V_sh[i] = U[i];
    }

    V_sh[11] = (V_sh[4] + V_sh[5] + V_sh[6] + V_sh[7] + V_sh[8] + V_sh[9] + V_sh[10]) % 2;
    V_sh[12] = (V_sh[1] + V_sh[2] + V_sh[3] + V_sh[7] + V_sh[8] + V_sh[9] + V_sh[10]) % 2;
    V_sh[13] = (V_sh[0] + V_sh[2] + V_sh[3] + V_sh[5] + V_sh[6] + V_sh[9] + V_sh[10]) % 2;
    V_sh[14] = (V_sh[0] + V_sh[1] + V_sh[3] + V_sh[4] + V_sh[6] + V_sh[8] + V_sh[10]) % 2;

    cout << "V = {";

    for (int i = 0; i < 14; i++) {
        cout << V_sh[i] << ", ";
    }

    cout << V_sh[14] << "}" << endl << endl;
    cout << "Расширенный код:" << endl;
    cout << "V = {";

    for (int i = 0; i < 11; i++) {
        V_ex[i] = U[i];
    }

    V_ex[11] = (V_ex[4] + V_ex[5] + V_ex[6] + V_ex[7] + V_ex[8] + V_ex[9] + V_ex[10]) % 2;
    V_ex[12] = (V_ex[1] + V_ex[2] + V_ex[3] + V_ex[7] + V_ex[8] + V_ex[9] + V_ex[10]) % 2;
    V_ex[13] = (V_ex[0] + V_ex[2] + V_ex[3] + V_ex[5] + V_ex[6] + V_ex[9] + V_ex[10]) % 2;
    V_ex[14] = (V_ex[0] + V_ex[1] + V_ex[3] + V_ex[4] + V_ex[6] + V_ex[8] + V_ex[10]) % 2;
    V_ex[15] = (V_ex[0] + V_ex[1] + V_ex[2] + V_ex[4] + V_ex[5] + V_ex[7] + V_ex[10]) % 2;

    for (int i = 0; i < 15; i++) {
        cout << V_ex[i] << ", ";
    }

    cout << V_ex[15] << "}" << endl << endl;
    cout << "Задание 2:" << endl << endl;
    cout << "Укороченный код:" << endl;

    int e1_sh[15][15];

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (i == j) {
                e1_sh[i][j] = 1;
            } else {
                e1_sh[i][j] = 0;
            }
        }
    }

    /*
     вывод матрицы e1 (проверка):
          for (int i = 0; i < 15; i++) {
           for (int j = 0; j < 15; j++) {
               cout << e1_sh[i][j] << " ";
           }
           cout << endl;
        }
        cout<<endl;
     */

    int W1_sh[15][15];

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            W1_sh[i][j] = (V_sh[j] + e1_sh[i][j]) % 2;
        }
    }

    cout << "W = {" << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            if (j == 14) {
                cout << W1_sh[i][j];
            } else {
                cout << W1_sh[i][j] << ", ";
            }
        }
        cout << endl;
    }

    cout << "}" << endl << endl;

    int S1_sh[15][4];
    int H_sh_T[15][4];

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 4; j++) {
            H_sh_T[i][j] = H_sh[j][i];
        }
    }

    cout << "H_T = {" << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 3) {
                cout << H_sh_T[i][j];
            } else {
                cout << H_sh_T[i][j] << ", ";
            }
        }
        cout << endl;
    }

    cout << "}" << endl << endl;

    for (int k = 0; k < 4; k++) {
        int sum = 0;
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                sum = (sum + W1_sh[i][j] * H_sh_T[j][k]) % 2;
            }
            S1_sh[i][k] = sum;
        }
    }

    cout << "S = {" << endl;

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == 3) {
                cout << S1_sh[i][j];
            } else {
                cout << S1_sh[i][j] << ", ";
            }
        }
        cout << endl;
    }

    cout << "}" << endl << endl;

    for (int i = 0; i < 15; i++) {
        cout << "Если S = {";

        for (int j = 0; j < 4; j++) {
            if (j == 3) {
                cout << S1_sh[i][j];
            } else {
                cout << S1_sh[i][j] << ", ";
            }
        }

        cout << "} , то " << endl;
        cout << "е = {";

        for (int q = 0; q < 15; q++) {
            if (q == 14) {
                cout << e1_sh[i][q];
            } else {
                cout << e1_sh[i][q] << ", ";
            }
        }

        cout << "}" << endl;
        cout << "Значит, ошибка допущена в " << i << " бите и V = {";

        W1_sh[i][i] = (W1_sh[i][i] + 1) % 2;

        for (int m = 0; m < 15; m++) {
            if (m == 14) {
                cout << W1_sh[i][m];
            } else {
                cout << W1_sh[i][m] << ", ";
            }
        }

        cout << "}" << endl << endl;
    }

    cout<<"Расширенный код:"<<endl;

    int e1_ex[16][16];

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (i == j) {
                e1_ex[i][j] = 1;
            } else {
                e1_ex[i][j] = 0;
            }
        }
    }

    int W1_ex[16][16];

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            W1_ex[i][j] = (V_ex[j] + e1_ex[i][j]) % 2;
        }
    }

    cout << "W = {" << endl;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (j == 15) {
                cout << W1_ex[i][j];
            } else {
                cout << W1_ex[i][j] << ", ";
            }
        }
        cout << endl;
    }

    cout << "}" << endl << endl;

    int S1_ex[16][5];
    int H_ex_T[16][5];

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            H_ex_T[i][j] = H_ex[j][i];
        }
    }

    cout << "H_T = {" << endl;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 4) {
                cout << H_ex_T[i][j];
            } else {
                cout << H_ex_T[i][j] << ", ";
            }
        }
        cout << endl;
    }

    cout << "}" << endl << endl;

    for (int k = 0; k < 5; k++) {
        int sum = 0;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                sum = (sum + W1_ex[i][j] * H_ex_T[j][k]) % 2;
            }
            S1_ex[i][k] = sum;
        }
    }

    cout << "S = {" << endl;

    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 5; j++) {
            if (j == 4) {
                cout << S1_ex[i][j];
            } else {
                cout << S1_ex[i][j] << ", ";
            }
        }
        cout << endl;
    }

    cout << "}" << endl << endl;

    for (int i = 0; i < 16; i++) {
        cout << "Если S = {";

        for (int j = 0; j < 5; j++) {
            if (j == 4) {
                cout << S1_ex[i][j];
            } else {
                cout << S1_ex[i][j] << ", ";
            }
        }

        cout << "} , то " << endl;
        cout << "е = {";

        for (int q = 0; q < 16; q++) {
            if (q == 15) {
                cout << e1_ex[i][q];
            } else {
                cout << e1_ex[i][q] << ", ";
            }
        }

        cout << "}" << endl;
        cout << "Значит, ошибка допущена в " << i << " бите и V = {";

        W1_ex[i][i] = (W1_ex[i][i] + 1) % 2;

        for (int m = 0; m < 16; m++) {
            if (m == 15) {
                cout << W1_ex[i][m];
            } else {
                cout << W1_ex[i][m] << ", ";
            }
        }

        cout << "}" << endl << endl;
    }

    return 0;
}
