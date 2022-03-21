#include <iostream>
#include <cstdio>
#include "CSVFormater.h"


CSVFormater::CSVFormater(const char* file_path_in) {
	file_path = NULL;
	file_size = 0;
	length_title = strlen(file_path_in);
	file_path = new char[length_title];
	strcpy(file_path, file_path_in);
}

CSVFormater::~CSVFormater() {
	delete file_data;

}

int CSVFormater::load_Data_From_File()
{
	FILE* fp = fopen(file_path, "rb");
	rewind(fp);
	if (fp != NULL) {
		fseek(fp, 0, SEEK_END);
		file_size = ftell(fp);
		rewind(fp);
		file_data = new char[file_size+1];	// plus 1 to add NULL at the end of string
		fread(file_data, sizeof(char) ,file_size, fp);
		*(file_data + file_size) = 0;

		fclose(fp);
		return 1;	// SUCCESS
	}
	else return 0;	// FAIL
}

const char *CSVFormater::get_file_path()
{
	return file_path;
}

const char* CSVFormater::get_file_data()
{
	return file_data;
}
