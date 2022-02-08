#include "pch.h"
#include "../Directory-Statistics/Utils.h"
#include "../Directory-Statistics/FileReader.h"



TEST(UtilFunctions, HorizontalTab) {
	Utils Utils;
	EXPECT_EQ(Utils.hori_tab(2), "\t\t");
	EXPECT_TRUE(true);
}

TEST(UtilFunctions, TabAndNewLine) {
	Utils Utils;
	EXPECT_EQ(Utils.tab_nl(1), "\n|\t|\n|\t|\n|\t");
	EXPECT_TRUE(true);
}


TEST(UtilFunctions, StringToVector) {
	Utils Utils;
	vector<string>myVect = Utils.str2vector(',', "hello,world");
	EXPECT_EQ(2, myVect.size());
	EXPECT_TRUE(true);
}

TEST(FileReaderTest, TestName) {
	FileReader myFile("../../Directory-Statistics/data");
	EXPECT_EQ(true, myFile.is_folder());
	EXPECT_TRUE(true);
}

TEST(FileReaderTest, TestProcessFile) {
	FileReader myFile("../../Directory-Statistics/data");
	EXPECT_EQ(true, myFile.process_file().is_folder);
	EXPECT_TRUE(true);
}

TEST(FileReaderTest, TestProcessFileName) {
	FileReader myFile("../../Directory-Statistics/data/xs.txt");
	EXPECT_EQ(10, myFile.process_file().total_lines);
	EXPECT_TRUE(true);
}
