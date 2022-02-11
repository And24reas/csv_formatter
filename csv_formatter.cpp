#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include<sstream>
#pragma warning(suppress : 4996)

struct Table_entry {
    std::string name, surname, age,address, plz, phone_no;
    
};


std::ostream& operator<<(std::ostream& stream, const Table_entry& table_entry) {
    stream << table_entry.name << " ," << table_entry.surname
        << " ," << table_entry.age << " ," << table_entry.address << " ," << table_entry.plz
        << " ,"<< table_entry.phone_no << std::endl;
    return stream;
}



int main()
{
    std::vector<Table_entry> table_entries;
    std::vector<std::string> data_to_store;
    
    
    FILE* fp;
    char c=NULL;
    fp=fopen("data1.csv","r");
    std::string data="";
    while (c != EOF) {
        c = fgetc(fp);
        data.push_back(c); 
        printf("%c", c);
    }
    fclose(fp);
    
    std::stringstream s(data);

    while (std::getline(s, data, ';')) {
        data_to_store.push_back(data);
    }
    
    /*
    for (int i = 0; i < (int) data_to_store.size(); i+=6) {
     
        table_entries.push_back({data_to_store[i], data_to_store[i+1], data_to_store[i+2], data_to_store[i+3], data_to_store[i+4], data_to_store[i+5] });  
    }
    */
    for (Table_entry t : table_entries) {
       
        std::cout << t << std::endl;
    }
   
    return 0;

}
