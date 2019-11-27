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

    cout << "Задание 2:" << endl;
    cout << "Укороченный код:" << endl << endl;

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

    cout << "Расширенный код:" << endl << endl;

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

    cout << "Задание 3:" << endl;
    cout << "Укороченный код:" << endl << endl;

    int e2_sh[15];
    int W2_sh[15];
    int S2_sh[4];
    bool ind = false;
    int j = 1;

    for (int i = 0; i < 15; i++) {
        e2_sh[i] = 0;
    }

    for (int i = 0; i < 114; i++) {
        if (ind) {
            j = i + 1;
            ind = false;
        }

        e2_sh[i] = 1;


        for (j; j < 15; j++) {
            e2_sh[j] = 1;

            for (int k = 0; k < 4; k++) {
                int sum = 0;
                for (int n = 0; n < 15; n++) {
                    sum = (sum + e2_sh[n] * H_sh_T[n][k]) % 2;
                }
                S2_sh[k] = sum;
            }

            cout << "Если S = {";

            for (int m = 0; m < 4; m++) {
                if (m == 3) {
                    cout << S2_sh[m];
                } else {
                    cout << S2_sh[m] << ", ";
                }
            }
            cout << "}, то" << endl;

            cout << "e = {";
            for (int k = 0; k < 15; k++) {
                if (k == 14) {
                    cout << e2_sh[k];
                } else {
                    cout << e2_sh[k] << ", ";
                }
            }

            cout << "}," << endl;

            cout << "W = {";

            for (int k = 0; k < 15; k++) {
                W2_sh[k] = (V_sh[k] + e2_sh[k]) % 2;
                if (k == 14) {
                    cout << W2_sh[k];
                } else {
                    cout << W2_sh[k] << ", ";
                }
            }

            cout << "}, значит ошибка допущена в " << i << " и " << j << " бите и" << endl;
            cout << "V = {";

            W2_sh[i] = (W2_sh[i] + 1) % 2;
            W2_sh[j] = (W2_sh[j] + 1) % 2;

            for (int m = 0; m < 15; m++) {
                if (m == 14) {
                    cout << W2_sh[m] << "}" << endl << endl;
                } else {
                    cout << W2_sh[m] << ", ";
                }
            }

            e2_sh[j] = 0;
        }

        e2_sh[i] = 0;
        ind = true;
    }

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

    int e2_ex[16];
    int W2_ex[16];
    int S2_ex[5];
    bool ind_ex = false;
    int j_ex = 1;

    for (int i = 0; i < 16; i++) {
        e2_ex[i] = 0;
    }

    for (int i = 0; i < 119; i++) {
        if (ind_ex) {
            j_ex = i + 1;
            ind_ex = false;
        }

        e2_ex[i] = 1;

        for (j_ex; j_ex < 16; j_ex++) {
            e2_ex[j_ex] = 1;

            cout << "e = {";
            for (int k = 0; k < 16; k++) {
                if (k == 15) {
                    cout << e2_ex[k];
                } else {
                    cout << e2_ex[k] << ", ";
                }
            }

            cout << "}," << endl;

            cout << "W = {";

            for (int k = 0; k < 16; k++) {
                W2_ex[k] = (V_ex[k] + e2_ex[k]) % 2;
                if (k == 15) {
                    cout << W2_ex[k];
                } else {
                    cout << W2_ex[k] << ", ";
                }
            }

            cout << "}, значит ошибка допущена в " << i << " и " << j_ex << " бите и" << endl;

            for (int k = 0; k < 5; k++) {
                int sum = 0;
                for (int n = 0; n < 16; n++) {
                    sum = (sum + e2_ex[n] * H_ex_T[n][k]) % 2;
                }
                S2_ex[k] = sum;
            }

            cout << "при S = {";

            for (int m = 0; m < 5; m++) {
                if (m == 4) {
                    cout << S2_ex[m];
                } else {
                    cout << S2_ex[m] << ", ";
                }
            }
            cout << "} ";

            cout << "V = {";

            W2_ex[i] = (W2_ex[i] + 1) % 2;
            W2_ex[j_ex] = (W2_ex[j_ex] + 1) % 2;

            for (int m = 0; m < 16; m++) {
                if (m == 15) {
                    cout << W2_ex[m] << "}" << endl << endl;
                } else {
                    cout << W2_ex[m] << ", ";
                }
            }

            e2_ex[j_ex] = 0;
        }

        e2_ex[i] = 0;
        ind_ex = true;
    }

    cout << "Для заданий 4 и 5 приведём несколько примеров" << endl;
    cout << "Задание 4:" << endl;
    cout << "Укороченный код:" << endl;

    int e3_sh[15] = {1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0};
    int e3_ex[16] = {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0};

    int W3_sh[15];
    int W3_ex[15];

    int S3_sh[4];
    int S3_ex[5];

    cout << "e = ";
    for (int i = 0; i < 15; i++) {
        cout << e3_sh[i] << " ";
    }
    cout << endl;

    cout << "V = ";
    for (int i = 0; i < 15; i++) {
        cout << V_sh[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 15; i++) {
        W3_sh[i] = (V_sh[i] + e3_sh[i]) % 2;
    }

    cout << "W = ";
    for (int i = 0; i < 15; i++) {
        cout << W3_sh[i] << " ";
    }
    cout << endl;

    for (int k = 0; k < 4; k++) {
        int sum = 0;
        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                sum = (sum + e3_sh[j] * H_sh_T[j][k]) % 2;
            }
            S3_sh[k] = sum;
        }
    }

    cout << "S = ";
    for (int j = 0; j < 4; j++) {
        cout << S3_sh[j] << " ";
    }
    cout << ", значит ошибка допущена в 0, 3 и 10 битах" << endl;
    // cout<<"Вариант необнаруживаемой ошибки:"<< endl;
    // cout<<"W = "

    cout << "Расширенный код:" << endl;

    cout << "e = ";
    for (int i = 0; i < 16; i++) {
        cout << e3_ex[i] << " ";
    }
    cout << endl;

    cout << "V = ";
    for (int i = 0; i < 16; i++) {
        cout << V_ex[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 16; i++) {
        W3_ex[i] = (V_ex[i] + e3_ex[i]) % 2;
    }

    cout << "W = ";
    for (int i = 0; i < 16; i++) {
        cout << W3_ex[i] << " ";
    }
    cout << endl;

    for (int k = 0; k < 5; k++) {
        int sum = 0;
        for (int n = 0; n < 16; n++) {
            sum = (sum + e3_ex[n] * H_ex_T[n][k]) % 2;
        }
        S3_ex[k] = sum;
    }

    cout << "S = ";
    for (int j = 0; j < 5; j++) {
        cout << S3_ex[j] << " ";
    }
    cout << ", значит ошибка допущена в 0, 4 и 12 битах" << endl << endl;

    cout << "Задание 5:" << endl;
    cout << "Расширенный код:" << endl;

    int e4_ex[16] = {0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0};
    int W4_ex[16];
    int S4_ex[5];

    cout << "e = ";
    for (int i = 0; i < 16; i++) {
        cout << e4_ex[i] << " ";
    }
    cout << endl;

    cout << "V = ";
    for (int i = 0; i < 16; i++) {
        cout << V_ex[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 16; i++) {
        W4_ex[i] = (V_ex[i] + e4_ex[i]) % 2;
    }

    cout << "W = ";
    for (int i = 0; i < 16; i++) {
        cout << W4_ex[i] << " ";
    }
    cout << endl;

    for (int k = 0; k < 5; k++) {
        int sum = 0;
        for (int n = 0; n < 16; n++) {
            sum = (sum + e4_ex[n] * H_ex_T[n][k]) % 2;
        }
        S4_ex[k] = sum;
    }

    cout << "S = ";
    for (int j = 0; j < 5; j++) {
        cout << S4_ex[j] << " ";
    }

    cout<<", значит ошибка допущена во 2, 5, 8 и 16 битах"<<endl;

    return 0;
}
