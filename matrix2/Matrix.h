#ifndef Matrix_h
#define Matrix_h

#include <vector>
#include <string>

class Matrix {
private:
	std::string mtyp;
	std::vector<std::vector<double>> mtrp;
	std::vector<double> mres;
	std::vector<double> cres;
	int k, err;

public:
	void readFile(std::string);
	void calcRes();
	void matRes();
	void checkRes();
	};

#endif /* Matrix_h */