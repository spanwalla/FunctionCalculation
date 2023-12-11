//
// Created by wwwod on 11.12.2023.
//

#ifndef FUNCTIONCALCULATION_CSVWRITER_H
#define FUNCTIONCALCULATION_CSVWRITER_H

#include <string>
#include <fstream>

class CSVWriter {
public:
    explicit CSVWriter(const std::string& filename);
    ~CSVWriter();
    void writeLine(const std::string& string);
private:
    std::ofstream file;
};


#endif //FUNCTIONCALCULATION_CSVWRITER_H
