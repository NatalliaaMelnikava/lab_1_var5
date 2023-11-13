#pragma once
#include <iostream>
#include <vector>

using namespace std;

vector<double> gauss(vector<vector<double>>&, vector<double>&);
void relative_error(vector<vector<double>>&, vector<double>&, const vector<double>&);
void residual_vector(const vector<double>&, const vector<double>&);
vector<double> multiplicate_matrix_and_array(const vector<vector<double>>&, const vector<double>&);
void displaying_x(const vector<double>&);