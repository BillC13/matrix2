#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "mat.h"

int main()
{
    std::string mtyp, filename;  // Matrix type
    std::cout << "Enter the matrix filename" << std::endl;
    getline(std::cin, filename);

    mat mat;

    mat.readFile(filename);

    mat.calcRes();

    mat.matRes();

    mat.checkRes();

    return 0;
}