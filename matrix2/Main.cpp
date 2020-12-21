#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Matrix.h"

int main()
{
    std::string mtyp, filename;  // Matrix type
    std::cout << "Enter the matrix filename" << std::endl;
    getline(std::cin, filename);

    Matrix matrix;

    matrix.readFile(filename);

    std::cout << "Enter the matrix multiplier" << std::endl;
    double mtim;
    std::cin >> mtim;

    std::vector<double> cres;
    matrix.calcRes(mtim);

    std::vector<double> mres;
    matrix.matRes(mtim);

    matrix.checkRes(mres, cres);

    return 0;
}