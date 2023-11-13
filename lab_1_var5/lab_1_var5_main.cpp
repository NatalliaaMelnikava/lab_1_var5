
//l1=-7.3,l2=8.39,l3=8.38
#include "Libraries.h"




int main() {
    // init values
    double l_1 = -7.3, l_2 = 8.39, l_3 = 8.38;
    vector<vector<double>> A = {
        { 9.64, 1.71, 5.42 },
        { 6.39, 6.25, 1.84 },
        { 4.21, 7.92, -3.41 }
    };
    vector<double> b = { 10.21, 3.41, 12.29 };

    vector<vector<double>> lambda_matrix_A{ {2 * l_1 + 4 * l_2, 2 * (l_1 - l_2), 2 * (l_1 - l_2)},
       {2 * (l_1 - l_2), 2 * l_1 + l_2 + 3 * l_3, 2 * l_1 + l_2 - 3 * l_3},
       {2 * (l_1 - l_2),2 * l_1 + l_2 - 3 * l_3, 2 * l_1 + l_2 + 3 * l_3 } };
    vector<double> lambda_array_B = { -4 * l_1 - 2 * l_2, -4 * l_1 + l_2 + 9 * l_3, -4 * l_1 + l_2 - 9 * l_3 };

    // create copy
    vector<vector<double>> copy_A(A);
    vector<double>copy_B(b);
    vector<vector<double>> copy_lambda_A(lambda_matrix_A);
    vector<double>copy_lambda_B(lambda_array_B);

    // task 1 Get answer by Gauss method
    auto answer_x = gauss(A, b);
    displaying_x(answer_x);

    auto answer_lambda_x = gauss(lambda_matrix_A, lambda_array_B);
    displaying_x(answer_lambda_x);

    // task 2 Calculate residual_vector and his norm
    auto new_B_value = multiplicate_matrix_and_array(copy_A, answer_x);
    residual_vector(copy_B, new_B_value);

    // task 3 Gauss method + error computation
    relative_error(copy_A, new_B_value, answer_x);

    return 0;
}