#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int Matrix::readFile(std::string filename)
{
    // Check to see if input file exists
    std::ifstream myfile(filename);
    if (!myfile.is_open()) return 1;
    // Open the input file
    std::string mtyp;
    //Get the matrix type
    (getline(myfile, mtyp)); 
    //Get the matrix dimensions
    myfile >> k;

    // Create the triplet vectors
    if (mtyp == "Full matrix") 
    {
        double z;
        for (int i = 0; i < k; i++) 
        {
            for (int j = 0; j < k; j++) 
            {
                myfile >> z;
                if (z != 0)
                {
                    std::vector<double> temp;
                    temp.push_back(i);
                    temp.push_back(j);
                    temp.push_back(z);
                    mtrp.push_back(temp);
                }
            }
        }
    }
    else if (mtyp == "Sparse matrix") 
    {
        double z;  // Value in sparse matrix
        int i, j; // Locations in sparse matrix
        while (myfile >> i >> j >> z) 
        {
            std::vector<double> temp;
            temp.push_back(i - 1);
            temp.push_back(j - 1);
            temp.push_back(z);
            mtrp.push_back(temp);
        }
    }
    else
    {
        myfile.close();    //close the file object. 
        return 2;
    }
    myfile.close();    //close the file object. 


    return 0;
}

void Matrix::calcRes(double mtim)
// This is the calculation using the triplet vectors
{
    for (int i = 0; i < k; i++)
    {
        cres.push_back(0);
    }

    for (int i = 0; i < mtrp.size(); i++)
    {
        cres[mtrp[i][0]] += mtrp[i][2] * mtim;
    }
}

void Matrix::matRes(double mtim)
{
    // This is the calculation using a full matrix to check
    std::vector<std::vector<double>> mate;
    for (int i = 0; i < k; i++)
    {
        std::vector<double> temp;
        for (int j = 0; j < k; j++) 
        {
            temp.push_back(0);
        }
        mate.push_back(temp);
    }

    for (int i = 0; i < mtrp.size(); i++) 
    {
        mate[mtrp[i][0]][mtrp[i][1]] = mtrp[i][2];
    }

    for (int i = 0; i < k; i++)
    {
        mres.push_back(0);                        // Initialise
        for (int j = 0; j < k; j++) 
        {
            mres[i] += mate[i][j] * mtim;       // Sum of each element
        }
    }
}

int Matrix::checkRes() { // Are the results the same?
    for (int i = 0; i < k; i++)
    {
        if (mres[i] != cres[i])
        {
            return 1;
        }
    }
    return 0;
}

void Matrix::printRes() { // Print the result
    std::cout << "The result is" << std::endl;
    for (int i = 0; i < k; i++)
    {
        std::cout << mres[i] << std::endl;
    }
}

void Matrix::outRes(std::string filename) { // Write the result
    std::ofstream myfile (filename);
    for (int i = 0; i < k; i++)
    {
        myfile << mres[i] << std::endl;
    }
    myfile.close();
}