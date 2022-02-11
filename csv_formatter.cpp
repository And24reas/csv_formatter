// csv_formatter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<sstream>
#pragma warning(suppress : 4996)

struct Table_entry {
    std::string name;
    std::string surname;
    std::string age;
    std::string address;
    std::string plz;
    std::string phone_no;
};

//std::vector<Table_entry> fill_up_array(vector<string> &data_to_store, File &fp) {}
/*
std::ostream& operator<<(ostream& stream, const Table_entry& table_entry) {
    stream << table_entry.name << " | " << table_entry.surname
        << " | " << table_entry.age << " | " << table_entry.age
        << " | " << table_entry.address << " | " << table_entry.plz
        << " | " << table_entry.phone_no << endl;

}
*/

int main()
{
    std::vector<Table_entry> table_entries;
    std::vector<std::string> data_to_store;
    
    FILE* fp;
    char c=NULL;
    fp=fopen("data.csv","r");
    std::string data="";
    while (c != EOF) {
        c = fgetc(fp);
        data.push_back(c); 
    }
    fclose(fp);
    //data_to_store.push_back(current);
    std::stringstream s(data);

    while (std::getline(s, data, ';')) {
        data_to_store.push_back(data);
    }
    
    for (std::string s : data_to_store) {
        std::cout << s << std::endl;
    }
    
    
    return 0;

}
