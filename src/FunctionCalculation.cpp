//
// Created by wwwod on 11.12.2023.
//

#include "FunctionCalculation.h"

FunctionCalculation::FunctionCalculation(Function *func, double start, double end, double step): func(func), start(start), end(end), step(step) {
    if (step == 0)
        throw std::invalid_argument("Step can't be a zero.");
    if (start > end)
        std::swap(this->start, this->end);
}

std::ostream& operator<<(std::ostream &os, const FunctionCalculation &obj) {
    auto result = obj.Values();
    /* for (const auto& p : result) {
        os << "(" << p.first << ", " << p.second << ")\n";
    } */
    for (int i = 0; i < result.size(); ++i) {
        os << "(" << result[i].first << ", " << result[i].second << ")";
        if (i + 1 != result.size())
            os << " ";
    }
    return os;
}

std::vector<double> FunctionCalculation::yValues() const {
    std::vector<double> result = xValues();
    for (double& i : result)
        i = func->calc(i);
    return result;
}

std::vector<double> FunctionCalculation::xValues() const {
    std::vector<double> result;
    double from = step > 0 ? start : end;
    double to = step > 0 ? end : start;
    while (step > 0 ? (from <= to) : (from >= to)) {
        result.push_back(from);
        from += step;
    }
    return result;
}

std::vector<std::pair<double, double>> FunctionCalculation::Values() const {
    std::vector<std::pair<double, double>> result;
    auto x = xValues();
    auto y = yValues();
    std::transform(x.begin(), x.end(), y.begin(), std::back_inserter(result),
                   [](double a, double b) { return std::make_pair(a, b); });
    return result;
}

std::vector<std::pair<double, double>> FunctionCalculation::ValuesAt(double x1, double x2) const {
    bool valid = true;
    std::stringstream ss;
    ss << "Invalid interval, these values missed: ";
    if (x1 < start || x1 > end) {
        ss << "x1 = " << x1;
        valid = false;
    }
    if (x2 < start || x2 > end) {
        if (!valid)
            ss << ", ";
        ss << "x2 = " << x2;
        valid = false;
    }
    if (!valid) {
        ss << ".";
        throw std::invalid_argument(ss.str());
    }

    std::vector<std::pair<double, double>> result;
    double from = step > 0 ? std::min(x1, x2) : std::max(x1, x2);
    double to = step > 0 ? std::max(x1, x2) : std::min(x1, x2);
    while (step > 0 ? (from <= to) : (from >= to)) {
        result.emplace_back(from, func->calc(from));
        from += step;
    }
    return result;
}

void FunctionCalculation::saveCsv(const std::string &filename, bool headers) const {
    CSVWriter csvFile(filename);
    if (headers) {
        // csvFile.writeLine("Interval: [" + std::to_string(start) + "; " + std::to_string(end) + "]. Step: " + std::to_string(step));
        csvFile.writeLine("x,y");
    }
    for (const auto& p : Values())
        csvFile.writeLine(std::to_string(p.first) + "," + std::to_string(p.second));
}
