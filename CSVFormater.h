#include <iostream>
#include <cstdio>
#include <string>
#include <iostream>
typedef  char*** Table;

class CSVFormater
{
	public:
		CSVFormater(const char* file_path_in);
		~CSVFormater();
		unsigned int load_Data_From_File();
		const char* get_file_path() ;
		const char* get_file_data();
		void count_columns();
		void count_rows();
		unsigned int get_column_count();
		unsigned int get_row_count();
		void find_max();
		unsigned int get_max();
		const char* get_file_data_head();
		void print_table(Table array, const char* string, const char* ptr_head, unsigned int columns, unsigned int rows, unsigned int max);
		Table* ToTable(unsigned int columns, unsigned int rows);
		//Table* ToTable(const char** ap_str, unsigned int a_row_count);
	private:
		unsigned int m_column_count;
		unsigned int m_row_count;
		unsigned int m_max;
		
		char* m_file_data=NULL;
		char* m_file_path=NULL;
		char* m_file_data_head = NULL;

		unsigned int m_length_file_name=0;

		// used to keep track of beginning of the string and the actual current position of the cursor
		const char* m_head_cursor;
		const char* m_current_pos_cursor;
		size_t m_file_size = 0;
		//char** table;		
};
