
//l1=-7.3,l2=8.39,l3=8.38

#include <iostream>
#include <vector>

using namespace std;

vector<double> gauss(vector<vector<double>>& A, vector<double>& b) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int max_idx = i;
        double max_val = abs(A[i][i]);


        for (int j = i + 1; j < n; j++) {              // Выбор главного элемента по столбцу
            if (abs(A[j][i]) > max_val) {
                max_idx = j;
                max_val = abs(A[j][i]);
            }
        }


        if (max_idx != i) {                            // Перестановка строк
            swap(A[i], A[max_idx]);
            swap(b[i], b[max_idx]);
        }

        for (int j = i + 1; j < n; j++) {             // Прямой ход
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    vector<double> x(n);                           // Обратный ход
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    return x;
}


// Вычисление нормы
void norma(vector<vector<double>>& A) {
    int pos = 0;
    int n = A.size();
    double* vektor = new double[n];
    for (int i = 0; i < n; i++)
        vektor[i] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            vektor[pos] += abs(A[j][i]);
        }
        pos++;
    }
    double max = vektor[0];
    for (int i = 0; i < pos; i++)
    {
        if (vektor[i] > max) max = vektor[i];
    }
    cout << "Norma: " << max << endl;

}
// Вычисление погрешности
void residual_vector(vector<vector<double>> A, vector<double>& b, vector<double>& x) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            A[i][j] = A[i][j] * x[j];
        }
    }

    int n = A.size();
    vector<double> res(n);
    for (int i = 0; i < A.size(); i++) {
        double sum = 0.0;
        for (int j = 0; j < A.size(); j++) {
            sum += A[i][j];
        }
        res[i] = sum - b[i];
    }
    for (int i = 0; i < A.size(); i++) {
        cout << res[i] << " ";
    }
}
//Вычисление нормы вектора невязки
double norma(vector<vector<double>>& A, vector<double>& b, vector<double>& x) {
    int n = A.size();
    vector<double> r(n);

    // Вычисление вектора невязки
    for (int i = 0; i < n; i++) {
        double sum = 0.0;
        for (int j = 0; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        r[i] = b[i] - sum;
    }

    // Вычисление нормы вектора невязки
    double norm = 0.0;
    for (int i = 0; i < n; i++) {
        norm += r[i] * r[i];
    }
    norm = sqrt(norm);

    return norm;
}

int main() {
    double l_1 = 0.0, l_2 = 0.0, l_3 = 0.0;
    cout << "Enter l: " << endl;
    cin >> l_1 >> l_2 >> l_3;
    vector<vector<double>> A = { {8.64, 1.71, 5.42},
                                {-6.39, 4.25, 1.84},
                                {4.21, 7.92, -3.41} };
    vector<vector<double>> A_1 = A;
    vector<vector<double>> New_A{ {2 * l_1 + 4 * l_2, 2 * (l_1 - l_2), 2 * (l_1 - l_2)},
        {2 * (l_1 - l_2), 2 * l_1 + l_2 + 3 * l_3, 2 * l_1 + l_2 - 3 * l_3},
        {2 * (l_1 - l_2),2 * l_1 + l_2 - 3 * l_3, 2 * l_1 + l_2 + 3 * l_3 } };
    vector<vector<double>> NewA_1 = New_A;
    vector<double> b = { 10.21, 3.41, 12.29 };
    vector<double> New_b = { -4 * l_1 - 2 * l_2, -4 * l_1 + l_2 + 9 * l_3, -4 * l_1 + l_2 - 9 * l_3 };
    vector<double> x = gauss(A, b);
    cout << "system solution:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << "x[" << i << "] = " << x[i] << endl;

    }
    norma(A);
    residual_vector(A_1, b, x);
    cout << endl;
    double norm = norma(A, b, x);
    cout << endl << "Norma of residual vector: " << norm << endl;
    vector<double> x_New = gauss(New_A, New_b);
    cout << "system solution 2:" << endl;
    for (int i = 0; i < x_New.size(); i++) {
        cout << "x[" << i << "] = " << x_New[i] << endl;

    }
    norma(New_A);
    residual_vector(NewA_1, New_b, x_New);
    double norm_New = norma(New_A, New_b, x_New);
    cout << endl << "Norma of residual vector: " << norm_New << endl;
    return 0;
}