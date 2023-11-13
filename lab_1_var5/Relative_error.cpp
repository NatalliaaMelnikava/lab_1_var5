#include "Libraries.h"

// function for calculating the relative error of the Gauss method
void relative_error(vector<vector<double>>& A, vector<double>& b2, const vector<double>& x) {
    auto x2 = gauss(A, b2);

    // calculate error
    double max_diff = fabs(x2[0] - x[0]);
    double max_x = fabs(x[0]);
    auto size = x.size();

    for (int i = 1; i < size; i++) {
        max_diff = max(max_diff, fabs(x2[i] - x[i]));
        max_x = max(max_x, fabs(x[0]));
    }

    cout << "Relative error value: " << max_diff / max_x << endl;
    
}
