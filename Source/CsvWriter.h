#ifndef FILE_CONVERTER_CSVWRITER_H
#define FILE_CONVERTER_CSVWRITER_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <fstream>
#include <exception>

#include "rapidcsv.h"

#include "utils.h"

class CsvWriter {
public:
    const std::string outFilePath;
    // TODO: figure out why .open fails when this is const
    std::ofstream outFile;
    // TODO: add export options like in CSVTool.java#setupCsvWriter()
    explicit CsvWriter(std::string outFilePath);

    void setHeaders(const std::vector<std::string> &headers);
    void setData(const std::vector<std::vector<std::string>> &data);

    int write();

private:
    std::vector<std::string> headers;
    // TODO: use stream to avoid pulling whole file into memory
    std::vector<std::vector<std::string>> data;
};


#endif //FILE_CONVERTER_CSVWRITER_H
