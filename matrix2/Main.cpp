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
    int err = 0;

    matrix.readFile(filename, err);
    if (err == 1) {
        std::cout << "Couldn't open " << filename << std::endl;
    }
    else if (err == 2) {
        std::cout << "Invalid matrix specifier " << std::endl;
    }
    else {
        std::cout << "Enter the matrix multiplier" << std::endl;
        double mtim;
        std::cin >> mtim;

        matrix.calcRes(mtim);

        matrix.matRes(mtim);

        err = 0;
        matrix.checkRes(err);
        
        if (err == 0) {
            std::cout << "The calculation was correct!" << std::endl;
            matrix.printRes();
        }
        else {
            std::cout << "There was an error!" << std::endl;
        }
    }

    return 0;
}