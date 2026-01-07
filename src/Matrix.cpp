#include "Matrix.hpp"

Matrix::Matrix(size_t r, size_t c): row{r}, col{c}, data(r*c){}
Matrix::Matrix(std::vector<double> data, size_t r, size_t c): row{r}, col{c}, data(data){}
Matrix::Matrix(std::vector<std::vector<double>> mat): Matrix(mat.size(), mat[0].size()){
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            (*this)(i,j) = mat[i][j];
        }
    }
}

Matrix Matrix::mul(const Matrix& other) const {
    if (col != other.row) {
        throw std::invalid_argument("Incompatible matrix dimensions for multiplication");
    }
    Matrix result(row, other.col);
    for (int j = 0; j < other.col; ++j) {
        for (int k = 0; k < col; ++k) {
            for (int i = 0; i < row; ++i) {
                result(i, j) += (*this)(i, k) * other(k, j);
            }
        }
    }
    return result;
}   

Matrix Matrix::transpose() const {
    Matrix result(col, row);
    for (int j = 0; j < col; ++j) {
        for (int i = 0; i < row; ++i) {
            result(j, i) = (*this)(i, j);
        }
    }
    return result;
}