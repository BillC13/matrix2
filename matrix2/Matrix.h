#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <string>

class Matrix {
private:
	std::string mtyp;
	std::vector<std::vector<double>> mtrp;
//	std::vector<double> mres;
//	std::vector<double> cres;
	int k;

public:
	void readFile(std::string);
	std::vector<double> calcRes(double);
	std::vector<double> matRes(double);
	void checkRes(std::vector<double>, std::vector<double>);
	void printRes(std::vector<double>);
	};

#endif /* Matrix_h */