#include "Utils.h";


vector<string> Utils::str2vector(char delimeter, string line) {
    vector<string> row;
    string word;
    stringstream str(line);
    while (getline(str, word, delimeter)) {
        row.push_back(word);
    }
    return row;
}

string Utils::hori_tab(int num) {
    string retVal = "";
    for (int i = 0; i < num; i++)
    {
        retVal += "\t";
    }
    return retVal;
}

string Utils::tab_nl(int num) {
    string retVal = "";
    for (int i = 0; i < 3; i++)
    {
        retVal += (i == 0) ? "\n" : "|\n";
        if (num > 0) {
            retVal += "|";
            for (int j = 0; j < num; j++)
            {
                retVal += "\t";
            }
        }

    }
    retVal += (num == 0) ? "|" : "";
    return retVal;
}