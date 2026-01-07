#include "OLS.hpp"


void OLSRegressor::fit(Matrix X, Matrix y){
    if (X.rows() != y.rows()){
        throw std::invalid_argument("Invalid dimensions: X rows must match y rows");
    }
    coeffs.resize(X.cols());
    //finding XTX 
    Matrix XTX(X.cols(), X.cols());
    for (int i = 0; i < X.cols(); ++i){
        for (int j = 0; j < X.cols(); ++j){
            double sum = 0.0;
            for (int k = 0; k < X.rows(); ++k){
                sum += X(k, i) * X(k, j);
            }
            XTX(i, j) = sum;
        }
    }
    //finding XTy
    Matrix XTy(X.transpose().mul(y));
    //calculating coefficients using normal equation coeffs = (XTX)^-1 * XTy
    //Using Gaussian elimination to solve for coeffs for now (will optimize later)
    int n = XTX.rows();
    Matrix augmented(n, n + 1);
    for (int j = 0; j < n; ++j){
        for (int i = 0; i < n; ++i){
            augmented(i, j) = XTX(i, j);
        }
    }
    for (int i = 0; i < n; ++i){
        augmented(i, n) = XTy(i, 0);
    }
    std::vector<double> pivot_col_factors(n); 

    for (int i = 0; i < n; ++i) {
        double pivot = augmented(i, i);
        if (std::abs(pivot) < 1e-9) {
            throw std::runtime_error("Singular matrix");
        }
        for(int k = 0; k < n; ++k) {
            pivot_col_factors[k] = augmented(k, i);
        }
        for (int j = i + 1; j < n + 1; ++j) {
            augmented(i, j) /= pivot;
            double pivot_row_val = augmented(i, j); 
            for (int k = 0; k < n; ++k) {
                if (k != i) {
                    augmented(k, j) -= pivot_col_factors[k] * pivot_row_val;
                }
            }
        }
        

        augmented(i, i) = 1.0;
        for(int k=0; k<n; ++k) if(k!=i) augmented(k, i) = 0.0;
    }
    
    for (int i = 0; i < n; ++i){
        coeffs[i] = augmented(i, n);
    }
    //Calculating MSE
    Matrix predictions = predict(X);
    double error_sum = 0.0;
    for (int i = 0; i < y.rows(); ++i){
        double error = y(i, 0) - predictions(i, 0);
        error_sum += error * error;
    }
    mse = error_sum / y.rows();
}

Matrix OLSRegressor::predict(Matrix X) const{
    if (X.cols() != coeffs.size()){
        throw std::invalid_argument("Invalid dimensions: X columns must match number of coefficients");
    }
    Matrix coeffs_matrix(coeffs, coeffs.size(), 1);
    Matrix predictions = X.mul(coeffs_matrix);
    return predictions;
}