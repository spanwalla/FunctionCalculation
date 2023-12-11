//
// Created by wwwod on 11.12.2023.
//

#include "CsvWriter.h"

CSVWriter::CSVWriter(const std::string &filename) {
    using namespace std::literals;
    if (!filename.ends_with(".csv"sv))
        file.open(filename + ".csv");
    else
        file.open(filename);

    if (!file.is_open())
        throw std::runtime_error("Unable to open file");
}

CSVWriter::~CSVWriter() {
    file.close();
}

void CSVWriter::writeLine(const std::string &string) {
    file << string << std::endl;
}


