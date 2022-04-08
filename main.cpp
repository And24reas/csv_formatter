#include <cstdio>;
#include <cstring>;
#include <iostream>;
#include "CSVFormater.h";

typedef  char*** Table;
//unsigned int get_columns(const char* string, const char* ptr_head);
//unsigned int get_rows(const char* string, const char* ptr_head);
//unsigned int get_max(const char* string, const char* ptr_head);
Table *create_array(unsigned int columns, unsigned int rows, unsigned int max);
//void print_table(Table array, const char* string, const char* ptr_head, unsigned int columns, unsigned int rows, unsigned int max);
int main()
{
	 
	const char* temp;
	unsigned int columns = 0;
	unsigned int rows = 0;
    unsigned int max = 0;

    CSVFormater example("data.csv");
	example.load_Data_From_File();
	example.count_columns();
	columns = example.get_column_count();
	example.count_rows();
	rows = example.get_row_count();
    example.find_max();
    max = example.get_max();
	
    
//std::cout << '\n' << columns << '\n' << rows;
	

    const char* ptr_head = example.get_file_data_head();
    const char* ptr_string = ptr_head;
    //Table *ptr;
    //std::cout << "Columns " << columns << " Rows: " << rows << "longest: " << max;
    Table array = *example.ToTable(rows, columns);
    example.print_table(array, ptr_string, ptr_head, columns, rows, max);
    return 0;
}
/*
unsigned int get_columns(const char* string, const char* ptr_head) 
{
    int columns = 1;
    while (*string != '\0') {
        
        if (*string == '\n')break;
        else if (*string == ';')columns++;
        
        string++;
    }
    string = ptr_head;
    return columns;
}

unsigned int get_rows(const char* string, const char* ptr_head) 
{
    int rows = 1;
    while (*string != '\0') {
        if (*string == '\n') rows++;
        string++;
    }
    string = ptr_head;
    return rows;
}

unsigned int get_max(const char* string, const char* ptr_head) 
{
    const char* ptr_tail;
    ptr_tail = ptr_head;
    int max = 0;
    int max_set = 0;
    int size = 0;
    while (*ptr_tail != '\0') {
        if (max_set == 0 && *ptr_tail == ';') {
            max_set = 1;
            max = ptr_tail - string; //calulate how many bytes the word is
            ptr_tail++; // move tail pointer to after ;
            string = ptr_tail; // sets new starting position to first char of next word
        }
        else {
            if (max_set == 1 && (*ptr_tail == ';' || *ptr_tail == '\n')) {
                size = ptr_tail - string;//calculates how many bytes the word is
                if (size > max) {
                    max = size;
                }
                ptr_tail++;//movest tail pointer to after ;
                string = ptr_tail;// sets new starting position to first char of next word
            }
            else {
                ptr_tail++;//char is not ; or \n so continue moving cursor one char forward
            }
        }
    }
    return max;
}

Table *create_array( unsigned int columns, unsigned int rows, unsigned int max) 
{
    Table toReturn = new char** [rows];
    Table* ptr_toReturn = &toReturn;
    for(int i=0; i < rows; i++){
        toReturn[i] = new char*[columns];
    }
    return ptr_toReturn;
}

void print_table(Table array, const char* string, const char* ptr_head, unsigned int columns, unsigned int rows, unsigned int max) 
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
            if (j == columns-1) {
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
        for (int j = 0; j < max ; j++) {
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
}*/