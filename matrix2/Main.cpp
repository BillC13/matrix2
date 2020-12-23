#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Matrix.h"

int main(int argc, char* argv[])
{
    // this program takes a matrix, either sparse or full, and multiplies it by a vector
    // It first performs this using triplet storage, and then checks this against a full matrix calculation

    Matrix matrix;

    switch (matrix.readFile(argv[1]))
    {
    case(1):
        std::cout << "Couldn't open " << argv[1] << std::endl;
        return 1;
    case(2):
        std::cout << "Invalid matrix specifier" << std::endl;
        return 1;
    }
   
    std::string rtim = argv[2];
    for (int i = 0; i < rtim.length(); i++)
    {
        if (isdigit(rtim[i]) == false)
        {
            std::cout << "Invalid multiplier" << std::endl;
            return 1;
        }
    }
    double mtim = std::stod(rtim);
     
    matrix.calcRes(mtim);

    matrix.matRes(mtim);

    if (matrix.checkRes() == 0)
    {
        std::cout << "The calculation was correct!" << std::endl;
        matrix.printRes();
        matrix.outRes(argv[3]);
    }
    else
    {
        std::cout << "There was an error!" << std::endl;
        return 1;
    }

    return 0;
}
