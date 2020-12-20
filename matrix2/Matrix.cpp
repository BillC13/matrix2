#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <vector>

void Matrix::readFile(std::string filename)
{
    // Check to see if input file exists
    std::ifstream myfile(filename);
    if (!myfile.is_open()) {
        std::cout << "Couldn't open Matrix.txt" << std::endl;
        exit(1);
    }
    //   Open the input file
    (getline(myfile, mtyp)); //Get the matrix type
    myfile >> k; //Get the matrix dimensions
    double z;
    for (int i = 0; i < k; i++);

    // Create the triplet vectors
    if (mtyp == "Full matrix") {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                myfile >> z;
                if (z != 0) {
                    std::vector<double> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(z);
                    mtrp.push_back(temp);
                }
            }
        }
    }
    else if (mtyp == "Sparse matrix") {
        double z;  // Value in sparse matrix
        int i, j; // Locations in sparse matrix
        while (myfile >> i >> j >> z) {
            std::vector<double> temp;
            temp.push_back(i-1);
            temp.push_back(j-1);
            temp.push_back(z);
            mtrp.push_back(temp);
        }
    }
    myfile.close();    //close the file object.     

}

void Matrix::calcRes()
// This is the calculation using the triplet vectors
{
    for (int i = 0; i < k; i++) {
        cres.push_back(0);
    }

    double mtim = 1;

    for (int i = 0; i < mtrp.size(); i++) {
        cres[mtrp[i][0]] += mtrp[i][2] * mtim;
    }

}

void Matrix::matRes()
{
    // This is the calculation using a full matrix to check
    std::vector<std::vector<double>> mate;
    for (int i = 0; i < k; i++) {
        std::vector<double> temp;
        for (int j = 0; j < k; j++) {
            temp.push_back(0);
        }
        mate.push_back(temp);
    }

    for (int i = 0; i < mtrp.size(); i++) {
        mate[mtrp[i][0]][mtrp[i][1]] = mtrp[i][2];
    }

    // create multiplication vector
    std::vector<double> mult;
    for (int i = 0; i < k; i++) {
        mult.push_back(1);
    }

    for (int i = 0; i < k; i++)
    {
        mres.push_back(0);                        // Initialise
        for (int j = 0; j < k; j++)
        {
            mres[i] += mate[i][j] * mult[j];       // Sum of each element
        }
    }
}

void Matrix::checkRes()
    // Are the results the same?
{
    err = 0;
    for (int i = 0; i < k; i++)
    {
        if (mres[i] != cres[i]) {
            err = 1;
            break;
        }
    }
    if (err == 0) {
        std::cout << "The calculation was correct" << std::endl;
    }
    else {
        std::cout << "Someone fucked up somewhere" << std::endl;
    }
}
