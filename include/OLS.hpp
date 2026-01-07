#include "Matrix.hpp"
#include <iostream> 
#include <stdexcept>

class OLSRegressor{
    private: 
        std::vector<double> coeffs; 
        double mse{};
    public:
        void fit(Matrix X, Matrix y);
        Matrix predict(Matrix X) const; 
        double get_mse() const{return mse;}
};