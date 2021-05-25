#include <iostream>
using namespace std;
size_t strlen(const char* string)
{
    size_t size=0;
    while(string[size]!='\0')
        size++;
    return size;
}
void printText(char** text, size_t size)
{
    for(size_t i=0;i<size;i++)
        cout << text[i] << endl;
}
void freeText(char** text, size_t size)
{
    for(size_t i=0;i<size;i++)
        delete[] text[i];
    delete [] text;
}
void push_back(char*** text, char* string, size_t* size)
{
    char** copy = new char*[*size+1];
    for(size_t i=0;i<*size;i++)
        copy[i] = (*text)[i];
    copy[*size]=string;
    delete [] *text;
    *text = copy;
    *size=*size+1;
}
int main()
{
    size_t stringsCount=0;
    char** strings = new char*[stringsCount];
    char* str;
    do{
        str = new char[4096];
        cin.getline(str, 4096, '\n');
        push_back(&strings,str,&stringsCount);
    }
    while(strlen(str)>0);
    printText(strings,stringsCount);
    freeText(strings,stringsCount);
    return 0;
}