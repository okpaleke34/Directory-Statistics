#pragma once
#include "FileReader.h"
#include "Utils.h"

FileReader::FileReader(string filedir) {
    Utils Utils;
    this->file_path = filedir;
    file_name_vect = Utils.str2vector('\\', this->file_path);
    file_name = file_name_vect[file_name_vect.size() - 1];
}
bool FileReader::is_folder() {
    std::string path = this->file_path;
    //check if diretory/path exists
    struct stat buffer;
    if (stat(path.c_str(), &buffer) == 0) {
        //try to open it as a file
        fstream file(path, std::ios::in);
        if (file.is_open())
        {
            //cout << "Not a folder \n";
            return true;
        }
        else {

            try {
                //try to open it as a folder
                int i = 0;
                for (const auto& file : directory_iterator(path)) {
                    //convert path type to string
                    std::string path_string{ file.path().u8string() };
                    i++;
                }
                //cout << i << " files in a folder\n"; here
                return true;
            }
            catch (filesystem_error& e) {
                // There is an error in checking the files in the folder
                //cerr << e.what() << endl;
                return false;
            }

        }
    }
    else {
        //Directory does not exist
        return false;
    }
}
 PathDetail  FileReader::process_file() {
    PathDetail thisPath;
    vector<vector<string>> content;
    vector<string> row;
    string line, word;

    fstream file(this->file_path, std::ios::in);
    std::string retVal;
    if (file.is_open())
    {
        int totalLines = 0, filledLines = 0, emptyLines = 0;
        while (getline(file, line))
        {
            totalLines++;
            row.clear();
            if (line == "") {
                emptyLines++;
            }
            else {
                filledLines++;
            }
        }


        thisPath.full_path = this->file_path;
        thisPath.name = file_name;
        thisPath.is_folder = false;
        thisPath.total_lines = totalLines;
        thisPath.filled_lines = filledLines;
        thisPath.empty_lines = emptyLines;
        file.close();
    }
    else
    {
        if (this->is_folder()) {
            thisPath.full_path = this->file_path;
            thisPath.name = file_name;
            thisPath.is_folder = true;
            thisPath.total_lines = 0;
            thisPath.filled_lines = 0;
            thisPath.empty_lines = 0;
        }
        else {
            thisPath.full_path = this->file_path;
            thisPath.name = file_name;
            thisPath.is_folder = false;
            thisPath.total_lines = -1;
            thisPath.filled_lines = -1;
            thisPath.empty_lines = -1;
        }
    }
    return thisPath;
 }