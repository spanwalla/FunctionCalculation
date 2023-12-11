//
// Created by wwwod on 11.12.2023.
//

#include "CosineFunction.h"

CosineFunction::CosineFunction(double a, double b, double c, double d): a(a), b(b), c(c), d(d) {}

double CosineFunction::calc(double x) {
    return a*cos(b*x + c) + d;
}

