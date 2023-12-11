//
// Created by wwwod on 11.12.2023.
//

#ifndef FUNCTIONCALCULATION_FUNCTION_H
#define FUNCTIONCALCULATION_FUNCTION_H


class Function {
public:
    virtual double calc(double x) = 0;
    virtual ~Function() = default;
};


#endif //FUNCTIONCALCULATION_FUNCTION_H
