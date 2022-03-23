#include <cstdio>;
#include <cstring>;
#include <iostream>;
#include "CSVFormater.h";

int main()
{
	//FILE* fp = fopen("text_file.txt", "rb+");
	const char* text = "This is some random text to be parsed";
	const char* temp;
	int columns = 0;
	FILE* fp;
	/* 
	* fp = fopen("sample.txt", "w");
	fprintf(fp, text);
	fclose(fp);
	*/
    CSVFormater example("data.csv");
	example.load_Data_From_File();
	temp = example.get_file_data();
	std::cout << temp;
	example.count_columns();
	columns = example.get_column_count();
	
	std::cout << '\n' << columns;
	return 0;
}
