# Directory Statistics
A multithread application that will analyze and show statistics of specified directory and it will handle recursive directories.  
It prints list of files under the folder they are contained in and total number of lines combined with empty and non-empty lines in each file. Google gtest is used as unit test. 
The program contains two projects 
- Directory-Statistics
   This is the main project solution. It contains the ThreadPool, FileReader, Util Classes.
- G-UnitTest
    This contains the test for the project. It runs unit test for the functions in Utils and FileReader Class

## Configuration Settings for Visual Studio 2022
Both of the projects are running on C++17, its my bad I didnt have much time to wrap it around docker container. 
But since the description requests for the use of std::filesystem I guess I am being expected to use c++17 or later. In other words the C++ language standard can be changed in
`Project > properties > Configuration Properties > C++ Language Standard ` then change to ISO C++17 Standard (/std:c++17)

 ## Directory-Statistics
 As this is the main project solution. In the  Directory-Statistics.cpp which contraions the main function, the vairable 'path' on line 27 holds the dir. to path that can be used to test the project. So you can change it to dir of any other folder to be worked on.
 The program gets the num_threads of threads of the computer then checks if the path supplied is a folder and  recursively open all files and folder in the path. Each path is converted into a string then pass it into FileReader constructor. 
 The FileReader::process_file() method gets the statistics of the file but it uses a thread pool to assign the work to different threads so that it can be doing {num_threads} at the same time.

## GTest is used for unit testing in the program. 
To make the test change the go to `Directory-Statistics > properties > Configuration Properties > Configuration Type` then change the Application (.exe) to Static library (.lib)
In the test that test for folders and files, the debug in VS 22 is running at `Directory-Statistics\x64\Debug\` so i have to move backwords to link it to the data folder that is used as a dummy test folder 

