//
// Created by wwwod on 11.12.2023.
//

#ifndef FUNCTIONCALCULATION_QUADRATICFUNCTION_H
#define FUNCTIONCALCULATION_QUADRATICFUNCTION_H

#include "Function.h"
#include <cmath>

class QuadraticFunction: public Function {
public:
    QuadraticFunction(double a, double b, double c);
    double calc(double x) override;
private:
    double a;
    double b;
    double c;
};


#endif //FUNCTIONCALCULATION_QUADRATICFUNCTION_H
