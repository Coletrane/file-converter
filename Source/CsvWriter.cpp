#include "CsvWriter.h"

CsvWriter::CsvWriter(std::string filePath): outFilePath(std::move(filePath)) {
    if (!endsWith(outFilePath, ".csv")) {
        std::stringstream ss;
        ss << "The output file path: " << outFilePath << "does not specify a CSV file!";
        throw std::invalid_argument(ss.str());
    }
    // Is this what RAII means?
    outFile.open(outFilePath.c_str());
}

void CsvWriter::setHeaders(const std::vector<std::string> &headersToSet) {
    headers = headersToSet;
}

void CsvWriter::setData(const std::vector<std::vector<std::string>> &dataToSet) {
    data = dataToSet;
}

