#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <string>

class Matrix {
private:
	std::vector<std::vector<double>> mtrp;
	std::vector<double> mres;
	std::vector<double> cres;
	std::string mtyp;
	int k;

public:
	int readFile(std::string, int err);
	void calcRes(double mtim);
	void matRes(double mtim);
	void checkRes(int err);
	void printRes();
};
#endif /* Matrix_h */