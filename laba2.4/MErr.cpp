#include <fstream>
#include "MErr.h"

using namespace std;

void Err(string str)
{
    FILE * f;
    f = fopen("/home/yurass/C/SDA/Семестр 2/laba2.4/laba2.4.txt", "at");
    cout << str;
    for(int i = 0; i < str.length(); i++) fwrite(&str[i], sizeof(str[i]), 1, f);
    str = "Error work\n\n";
    cout << str;
    for(int i = 0; i < str.length(); i++) fwrite(&str[i], sizeof(str[i]), 1, f);
    fclose(f);
}

