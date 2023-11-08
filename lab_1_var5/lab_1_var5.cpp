
//l1=-7.3,l2=8.39,l3=8.38
#include <iostream>
#include <vector>

using namespace std;

vector<double> gauss( vector<vector<double>>& A,vector<double> &b) {
    int n = A.size();

    for (int i = 0; i < n; i++) {
        int max_idx = i;
        double max_val = abs(A[i][i]);


        for (int j = i + 1; j < n; j++) {              // Selecting the main element by column
            if (abs(A[j][i]) > max_val) {
                max_idx = j;
                max_val = abs(A[j][i]);
            }
        }


        if (max_idx != i) {                            // Swaping strings
            swap(A[i], A[max_idx]);
            swap(b[i], b[max_idx]);
        }

        for (int j = i + 1; j < n; j++) {             // Straight running
            double factor = A[j][i] / A[i][i];
            for (int k = i; k < n; k++) {
                A[j][k] -= factor * A[i][k];
            }
            b[j] -= factor * b[i];
        }
    }

    vector<double> x(n,0);                           // Reverse course
    for (int i = n - 1; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < n; j++) {
            sum += A[i][j] * x[j];
        }
        x[i] = (b[i] - sum) / A[i][i];
    }

    return x;
}


// function for calculating the relative error of the Gauss method
double relative_error(vector<vector<double>>& A, vector<double>& b2, const vector<double>& x) {
    vector<double> x2(A.size());
    x2 = gauss(A, b2);
    double max_x = abs(x2[0]-x[0]);
    double maxd = max_x;
    for (int i = 0; i < x.size();i++) {
        if (maxd < abs(x2[i] - x[i]))
            maxd = abs(x2[i] - x[i]);
      /*  if (max_x < x[i])max_x = x[i];*/
        if (max_x < abs(x[i])) max_x = abs(x[i]);
    }
    
    return maxd/max_x;
}

// calculating residual vector
double residual_vector(vector<vector<double>>& A, vector<double> b2,const vector<double>& x, vector<double>& res) {
    vector<double>B = { 10.21, 3.41, 12.29 };
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
             b2[i] += A[i][j] * x[j];
        }
        res[i] = b2[i] - B[i];
    }
    double norma = res[0];
    for (int i = 0; i < res.size(); i++) {
        if (norma < res[i])norma = res[i];
    }
    return norma;
}

void displaying_x(const vector<double>&x) {
    cout << endl << "system solution:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << "x[" << i << "] = " << x[i] << endl;

    }

}

void output(vector<double>&x,vector<vector<double>>&a,vector<double>&b,vector<vector<double>>&A_1,vector<double>&b2) {
    x = gauss(a, b);
    displaying_x(x);

    vector<double>res(a.size());
    
    cout << "Norma residual:" << residual_vector(A_1, b2, x, res) << endl;
    cout << "residual vector: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << "relative error: " << relative_error(A_1, b2, x) << endl;
}

int main() {

    double l_1 = 0.0, l_2 = 0.0, l_3 = 0.0;
    cout << "Enter l: " << endl;
    cin >> l_1 >> l_2 >> l_3;

    vector<vector<double>> A = { {8.64, 1.71, 5.42},
                                {-6.39, 4.25, 1.84},
                                {4.21, 7.92, -3.41} };
    vector<double> b = { 10.21, 3.41, 12.29 };
   
    vector<vector<double>> A_1 = A;
    vector<double> x(A.size());
    vector<double> b2(A.size());
   
    vector<vector<double>> New_A{ {2 * l_1 + 4 * l_2, 2 * (l_1 - l_2), 2 * (l_1 - l_2)},
        {2 * (l_1 - l_2), 2 * l_1 + l_2 + 3 * l_3, 2 * l_1 + l_2 - 3 * l_3},
        {2 * (l_1 - l_2),2 * l_1 + l_2 - 3 * l_3, 2 * l_1 + l_2 + 3 * l_3 } };
    vector<vector<double>> NewA_1 = New_A;
   
    vector<double> New_b = { -4 * l_1 - 2 * l_2, -4 * l_1 + l_2 + 9 * l_3, -4 * l_1 + l_2 - 9 * l_3 };
   
    vector<double> x_New(New_A.size());
  
    output(x, A, b, A_1, b2);

    output(x_New, New_A, New_b, A_1, b2);
    

    return 0;
}