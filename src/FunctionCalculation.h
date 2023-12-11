//
// Created by wwwod on 11.12.2023.
//

#ifndef FUNCTIONCALCULATION_FUNCTIONCALCULATION_H
#define FUNCTIONCALCULATION_FUNCTIONCALCULATION_H

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "Function.h"
#include "CsvWriter.h"

class FunctionCalculation {
public:
    FunctionCalculation(Function* func, double start, double end, double step);
    [[nodiscard]] std::vector<double> yValues() const;
    [[nodiscard]] std::vector<double> xValues() const;
    [[nodiscard]] std::vector<std::pair<double, double>> Values() const;
    [[nodiscard]] std::vector<std::pair<double, double>> ValuesAt(double x1, double x2) const;
    void saveCsv(const std::string& filename, bool headers) const;
    friend std::ostream& operator<<(std::ostream& os, const FunctionCalculation& obj);
private:
    Function* func;
    double start;
    double end;
    double step;
};


#endif //FUNCTIONCALCULATION_FUNCTIONCALCULATION_H
