#ifndef FILE_CONVERTER_UTILS_H
#define FILE_CONVERTER_UTILS_H

#include <string>

inline bool endsWith(std::string const & value, std::string const & ending) {
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}

#endif //FILE_CONVERTER_UTILS_H
