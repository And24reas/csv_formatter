#include <iostream>
#include <cstdio>
#include <string>
#include <iostream>

class CSVFormater
{
	public:
		CSVFormater(const char* file_path_in);
		~CSVFormater();
		int load_Data_From_File();
		const char* get_file_path() ;
		const char* get_file_data();
	private:
		int file_size=0;
		char* file_data=NULL;
		char* file_path=NULL;
		int length_title=0;
};
