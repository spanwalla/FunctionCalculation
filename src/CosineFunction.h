//
// Created by wwwod on 11.12.2023.
//

#ifndef FUNCTIONCALCULATION_COSINEFUNCTION_H
#define FUNCTIONCALCULATION_COSINEFUNCTION_H

#include <cmath>
#include "Function.h"

class CosineFunction: public Function {
public:
    CosineFunction(double a, double b, double c, double d);
    double calc(double x) override;
private:
    double a;
    double b;
    double c;
    double d;
};


#endif //FUNCTIONCALCULATION_COSINEFUNCTION_H
