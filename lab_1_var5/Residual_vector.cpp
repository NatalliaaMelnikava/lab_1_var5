#include "Libraries.h"

// calculating residual vector
void residual_vector(const vector<double>& b, const vector<double>& new_b) {
    vector<double> residual_vector{};
    auto size = b.size();

    cout << "Residual vector: " << endl;
    for (int i = 0; i < size; i++) {
        residual_vector.push_back(new_b[i] - b[i]);
        cout << residual_vector[i] << " ";
    }
    cout << endl;

    double norma = fabs(residual_vector[0]);
    for (const auto& item : residual_vector) {
        norma = fabs(item) > norma ? fabs(item) : norma;
    }

    cout << "Norm of residual vector: " << norma << endl;
}