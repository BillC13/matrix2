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

    switch (matrix.readFile(filename)) {
    case(1):
        std::cout << "Couldn't open " << filename << std::endl;
        break;
    case(2):
        std::cout << "Invalid matrix specifier " << std::endl;
        break;
    case(0):
        std::cout << "Enter the matrix multiplier" << std::endl;
        double mtim;
        std::cin >> mtim;

        matrix.calcRes(mtim);

        matrix.matRes(mtim);

        if (matrix.checkRes() == 0) {
            std::cout << "The calculation was correct!" << std::endl;
            matrix.printRes();
        }
        else {
            std::cout << "There was an error!" << std::endl;
        }

        return 0;
    }
}
