#pragma once 
#include <vector> 

class Matrix{
    private: 
        std::vector<double> data; 
        size_t row{}; 
        size_t col{}; 
    public: 
        Matrix(size_t r, size_t c); 
        Matrix(std::vector<double> data, size_t r, size_t c);
        Matrix(std::vector<std::vector<double>> data);

        double& operator()(size_t r, size_t c, bool row_maj = true){
            return data[c*row + r];  //column major format for faster calculation of XtX
        }
        const double& operator()(size_t r, size_t c, bool row_maj = true) const{
            return data[c*row + r];
        }
        
        size_t rows() const{return row;}
        size_t cols() const{return col;}
};
