#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <string>

class Matrix {
private:
	std::vector<std::vector<double>> mtrp;
	std::vector<double> mres;
	std::vector<double> cres;
	int k;

public:
	void calcRes(double);
	void matRes(double);
	void checkRes();
	void printRes();
};

class Full {
private:

public:
	void readFull(std::string);
};

class Sparse {
private:

public:
	void readSparse(std::string);
};
#endif /* Matrix_h */