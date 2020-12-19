#ifndef mat_h
#define mat_h

#include <vector>
#include <string>

class mat {
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

#endif /* mat_h */