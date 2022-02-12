// csv_formatter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
#pragma warning(suppress : 4996)

struct table_entry {
    string name;
    string surname;
    int age;
    string address;
    string plz;
    string phone_no;


};
int main()
{
    FILE* fp;
    char c=NULL;
    fp=fopen("data.csv","r");

    while (c != EOF) {
        
        while (c != '\n') {

        }
        c = fgetc(fp);
        printf("%c", c);
    }
    fclose(fp);

    return 0;

}
