//
// Created by wwwod on 11.12.2023.
//

#ifndef FUNCTIONCALCULATION_ABSFUNCTION_H
#define FUNCTIONCALCULATION_ABSFUNCTION_H

#include <cmath>
#include "Function.h"

class AbsFunction: public Function {
public:
    AbsFunction(double a, double b);
    double calc(double x) override;
private:
    double a;
    double b;
};


#endif //FUNCTIONCALCULATION_ABSFUNCTION_H
