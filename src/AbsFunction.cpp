//
// Created by wwwod on 11.12.2023.
//

#include "AbsFunction.h"

AbsFunction::AbsFunction(double a, double b): a(a), b(b) {}

double AbsFunction::calc(double x) {
    return a*std::abs(x + b);
}


