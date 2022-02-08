#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using std::string;
using std::vector; using std::stringstream;

class Utils {
	public:
		//converts a string to vector with a delimeter
		vector<string> str2vector(char delimeter, string line);
		//returns number of horizontal \t tabs passed as parameter
		string hori_tab(int num);
		string tab_nl(int num);
};