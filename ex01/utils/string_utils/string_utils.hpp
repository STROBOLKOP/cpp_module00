#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP

#include <string>
std::string trim(const std::string& str, const std::string& whitespace = " \t");
std::string reduce(const std::string& str, const std::string& fill = " ", const std::string& whitespace = " \t");

#endif
