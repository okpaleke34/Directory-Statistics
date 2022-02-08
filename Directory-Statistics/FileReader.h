#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <thread>
#include <windows.h>


//namespace fs = std::filesystem;

using std::endl; using std::string;
using std::vector; using std::fstream;
using std::filesystem::directory_iterator;
using std::filesystem::filesystem_error;

using std::filesystem::current_path;
extern struct PathDetail {
    string full_path;
    string name;
    bool is_folder;
    int total_lines;
    int filled_lines;
    int empty_lines;
};




class FileReader
{
public:
    std::string file_path;
    vector<string> file_name_vect;
    std::string file_name;
    FileReader(string filedir);
    bool is_folder();
    PathDetail  process_file();
};