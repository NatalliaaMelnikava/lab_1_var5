#include "Libraries.h"

vector<double> multiplicate_matrix_and_array(const vector<vector<double>>& matrix, const vector<double>& vec) {
    vector<double> result{};
    auto size = vec.size();

    for (auto i{ 0 }; i < size; ++i)
    {
        double sum = 0.;
        for (auto j{ 0 }; j < size; ++j)
        {
            sum += matrix[i][j] * vec[j];
        }
        result.push_back(sum);
    }

    return result;
}

void displaying_x(const vector<double>& x) {
    cout << endl << "system solution:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << "x[" << i << "] = " << x[i] << endl;

    }

}