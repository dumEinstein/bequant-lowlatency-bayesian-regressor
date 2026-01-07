#include "OLS.hpp"
#include <iostream>

int main(){
    Matrix X({
        {1.0, 1.0},
        {1.0, 2.0},
        {1.0, 3.0}
    });
    Matrix y(std::vector<std::vector<double>>{
        {1.0},
        {2.0},
        {3.0}
    });

    OLSRegressor model;
    model.fit(X, y);
    Matrix predictions = model.predict(X);

    std::cout << "Predictions:\n";
    for (size_t i = 0; i < predictions.rows(); ++i){
        std::cout << predictions(i, 0) << "\n";
    }
    std::cout << "MSE: " << model.get_mse() << "\n";

    return 0;
}