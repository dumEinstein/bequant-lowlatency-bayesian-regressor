#include "Matrix.hpp"

Matrix::Matrix(size_t r, size_t c): row{r}, col{c}, data(r*c){}
Matrix::Matrix(std::vector<double> data, size_t r, size_t c): row{r}, col{c}, data(data){}
Matrix::Matrix(std::vector<std::vector<double>> mat): Matrix(mat.size(), mat[0].size()){
    for (int j = 0; j < col; ++j) {
        for (int i = 0; i < row; ++i) {
            data[j * row + i] = mat[i][j];
        }
    }
}