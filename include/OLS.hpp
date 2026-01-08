#pragma once
#include "Matrix.hpp"
#include <iostream> 
#include <stdexcept>

class OLSRegressor{
    private: 
        std::vector<double> coeffs; 
        double mse{};
    public:
        void fit(const Matrix& X, const Matrix& y);
        Matrix predict(const Matrix& X) const; 
        double get_mse() const{return mse;}
        std::vector<double> get_coeffs() const {return coeffs;}
};