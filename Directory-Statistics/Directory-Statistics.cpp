#include <iostream>
#include <vector>
#include <string>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <thread>


#include "Threadpool.h"
#include "FileReader.h"
#include "Utils.h"



using std::filesystem::recursive_directory_iterator;
using std::cout;

int main(int argc, char* argv[]) {

    int num_threads = std::thread::hardware_concurrency();

    ThreadPool Pool(num_threads);
    std::vector<std::future<PathDetail>> futures;

    
    string path = "./data";
    FileReader mainPath(path);
    //check if the path suplied is a folder
    if (mainPath.is_folder()) {
        int i = 0;
        for (const auto& file : recursive_directory_iterator(path)) {
            //convert path type to string
            std::string path_string{ file.path().u8string() };
            FileReader CurrentFile(path_string);
            futures.push_back(Pool.execute(&FileReader::process_file, CurrentFile));
            i++;
        }

        cout << path;
        Utils Utils;
        string folder = "()";
        for (auto& fut : futures) {
            PathDetail myPath;
            myPath = fut.get();
            std::stringstream str_stream;
            str_stream << myPath.name << "~~[Total lines: " << myPath.total_lines << ", Filled Lines: " << myPath.filled_lines << ", Empty Lines: " << myPath.empty_lines << "]";
            string data = str_stream.str();
            if (myPath.is_folder) {
                int subFolder = Utils.str2vector('\\', myPath.full_path).size();
                subFolder = subFolder - 2;
                cout << Utils.tab_nl(subFolder) << "-------" << myPath.name;
                folder = myPath.name;
            }
            else {
                size_t found = myPath.full_path.find(folder);
                if (found != string::npos) {
                    int subFolder = Utils.str2vector('\\', myPath.full_path).size();
                    subFolder = subFolder - 2;
                    cout << Utils.hori_tab(subFolder) << "\n|" << Utils.hori_tab(subFolder) << "|\n|" << Utils.hori_tab(subFolder) << "|\n" << "|" << Utils.hori_tab(subFolder) << "-------" << data;
                }
                else {
                    cout << "\n|\n|\n" << "|-----" << data;
                }

            }
        }
        cout << "\n\n\n";
    }
    else {
        cout << "The provided path is not a folder.\n\n";
    }


    return 0;
}