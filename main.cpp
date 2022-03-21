#include <cstdio>;
#include <cstring>;
#include <iostream>;
#include "CSVFormater.h";

int main()
{
	//FILE* fp = fopen("text_file.txt", "rb+");
	const char* text = "This is some random text to be parsed";
	const char* temp;
	FILE* fp;
	/* 
	* fp = fopen("sample.txt", "w");
	fprintf(fp, text);
	fclose(fp);
	*/
	
	const char* p = "sssss";
    CSVFormater example("data.csv");
	example.load_Data_From_File();
	temp = example.get_file_data();
	std::cout << temp;
	
	
	return 0;
}
