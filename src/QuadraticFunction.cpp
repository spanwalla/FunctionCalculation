//
// Created by wwwod on 11.12.2023.
//

#include "QuadraticFunction.h"

QuadraticFunction::QuadraticFunction(double a, double b, double c): a(a), b(b), c(c) {}

double QuadraticFunction::calc(double x) {
    return a*pow(x, 2) + b*x + c;
}
