#ifndef FILE_H
#define FILE_H

#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using std::fstream;
using std::vector;

std::vector<std::string> passDelimetedString(std::string line);

void readFile(std::vector<std::string>& v);

#endif /* FILE_H */
