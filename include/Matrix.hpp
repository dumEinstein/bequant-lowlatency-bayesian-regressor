#pragma once 
#include <vector> 
#include <stdexcept>

class Matrix{
    private: 
        std::vector<double> data; 
        size_t row{}; 
        size_t col{}; 
    public: 
        Matrix(size_t r, size_t c); 
        explicit Matrix(std::vector<double> data, size_t r, size_t c);
        explicit Matrix(std::vector<std::vector<double>> data);
        Matrix(const Matrix& other) = default;
        Matrix(Matrix&& other) noexcept = default;

        double& operator()(size_t r, size_t c){
            return data[c*row + r];  //column major format for faster calculation of XtX
        }
        const double& operator()(size_t r, size_t c) const{
            return data[c*row + r];
        }
        
        size_t rows() const{return row;}
        size_t cols() const{return col;}

        Matrix mul(const Matrix& other) const;
        Matrix transpose() const;
        Matrix trans_mul(const Matrix& other) const; 
};
