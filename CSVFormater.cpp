#include <iostream>
#include <cstdio>
#include "CSVFormater.h"

CSVFormater::CSVFormater(const char* m_file_path_in) 
{
	m_column_count = 0;
	m_row_count = 0;
	m_file_path = NULL;
	m_file_size = 0;
	m_max = 0;
	m_length_file_name = strlen(m_file_path_in);
	m_file_path = new char[m_length_file_name];
	strcpy(m_file_path, m_file_path_in);
}

CSVFormater::~CSVFormater() 
{
	delete m_file_data;
	std::cout << "\nSucessfully deleted m_file_data";
	//delete m_file_path;
	std::cout << "Successfully deleted m_file_path";
}

unsigned int CSVFormater::load_Data_From_File()
{
	FILE* fp = fopen(m_file_path, "rb");
	rewind(fp);
	if (fp != NULL) {
		fseek(fp, 0, SEEK_END);	//move cursor to the end of the file
		m_file_size = ftell(fp); //reveal position of the cursor to get size in bytes
		rewind(fp); //move the cursor back to the beginning of the file
		m_file_data = new char[m_file_size + 1];	// plus 1 to add NULL at the end of string
		fread(m_file_data, sizeof(char) ,m_file_size, fp); // perform (m_file_size) times read, each time reading one byte (sizeof(char))
		*(m_file_data + m_file_size) = NULL; // add null to end of file
		fclose(fp);
        m_file_data_head = m_file_data;
		return 1;	// SUCCESS
	}
	else return 0;	// FAIL
}

void CSVFormater::find_max() 
{
	char* ptr_tail;
	ptr_tail = m_file_data_head;
	int max = 0;
	int max_set = 0;
	int size = 0;
	while (*ptr_tail != '\0') {
		if (max_set == 0 && *ptr_tail == ';') {
			max_set = 1;
			max = ptr_tail - m_file_data; //calulate how many bytes the word is
			ptr_tail++; // move tail pointer to after ;
			m_file_data = ptr_tail; // sets new starting position to first char of next word
		}
		else {
			if (max_set == 1 && (*ptr_tail == ';' || *ptr_tail == '\n')) {
				size = ptr_tail - m_file_data;//calculates how many bytes the word is
				if (size > max) {
					max = size;
				}
				ptr_tail++;//movest tail pointer to after ;
				m_file_data = ptr_tail;// sets new starting position to first char of next word
			}
			else {
				ptr_tail++;//char is not ; or \n so continue moving cursor one char forward
			}
		}
	}
    m_file_data = m_file_data_head;
	m_max = max;
}

Table* CSVFormater::ToTable(unsigned int columns, unsigned int rows)
{
	Table toReturn = new char** [rows];
	Table* ptr_toReturn = &toReturn;
	for (int i = 0; i < rows; i++) {
		toReturn[i] = new char* [columns];
	}
	return ptr_toReturn;
}

void CSVFormater::print_table(Table array, const char* string, const char* ptr_head, unsigned int columns, unsigned int rows, unsigned int max)
{
    const char* ptr_tail;
    ptr_tail = ptr_head;
    char space = ' ';
    int size = 0;
    int i = 0;
    int j = 0;
    int k = 0;
    while (*ptr_tail != '\0') {
        if (*ptr_tail == ';') {
            size = ptr_tail - string; //calulate how many bytes the word is
            array[i][j] = new char[max];
            for (int k = 0; k < size; k++) {
                array[i][j][k] = *string;
                string++;
            }
            for (int s = size; s < max; s++) {
                array[i][j][s] = space;
            }
            if (j == columns - 1) {
                j = 0;
            }
            else {
                j++;
            }
            ptr_tail++; // move tail pointer to after ;
            string = ptr_tail; // sets new starting position to first char of next word
        }
        else if (*ptr_tail == '\n') {
            size = ptr_tail - string;
            array[i][j] = new char[max];
            for (int k = 0; k < size; k++) {
                array[i][j][k] = *string;
                string++;
            }
            for (int s = size; s < max; s++) {
                array[i][j][s] = space;
            }
            if (j == columns - 1) {
                j = 0;
            }
            else {
                j++;
            }
            i++;
            ptr_tail++;
            string = ptr_tail;
        }
        else {
            ptr_tail++;
        }
    }
    size = ptr_tail - string;
    array[i][j] = new char[max];
    for (int k = 0; k < size; k++) {
        array[i][j][k] = *string;
        string++;
    }
    for (int s = size; s < max; s++) {
        array[i][j][s] = space;
    }
    if (j == columns - 1) {
        j = 0;
    }
    else {
        j++;
    }
    i++;
    ptr_tail++;
    string = ptr_tail;
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < max; j++) {
            std::cout << "-";
        }
        std::cout << "+";
    }
    std::cout << std::endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            for (int k = 0; k < max; k++) {
                std::cout << array[i][j][k];
            }
            std::cout << "|";
        }
        std::cout << std::endl;
    }
}

void CSVFormater::count_columns() 
{
	int columns = 1;
	while (*m_file_data != '\0') {

		if (*m_file_data == '\n')break;
		else if (*m_file_data == ';')columns++;

		m_file_data++;
	}
	m_file_data = m_file_data_head;
	m_column_count = columns;
}

void CSVFormater::count_rows() 
{
	int rows = 1;
	while (*m_file_data != '\0') {
		if (*m_file_data == '\n') rows++;
		m_file_data++;
	}
	m_file_data = m_file_data_head;
	m_row_count = rows;	
}

unsigned int CSVFormater::get_column_count()
{
	return m_column_count;
}

unsigned int CSVFormater::get_row_count()
{
	return m_row_count;
}

const char *CSVFormater::get_file_path()
{
	return m_file_path;
}

const char* CSVFormater::get_file_data()
{
	return m_file_data;
}
unsigned int CSVFormater::get_max()
{
    return m_max;
}

const char* CSVFormater::get_file_data_head()
{
    return m_file_data_head;
}