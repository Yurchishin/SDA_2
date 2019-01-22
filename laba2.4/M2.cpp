#include "M2.h"
#include "M1.h"

#include <iostream>

using namespace std;

void s5()
{
    string str =  "Function s5, M2: work\n";
    Err(str);
    string strEnd = "Function S5, M2: end";
    Err(strEnd);
}

void s6()
{
    string str =  "Function s6, M2: work\n";
    Err(str);
    string strEnd = "Function S6, M2: end";
    Err(strEnd);
}

void s7(int flag)
{
    string str;
    str =  "Function s7, M2: work\n";
    Err(str);
    if(flag == 0) {
        str = "Error\n";
        Err(str);
        string strEnd = "Function S7, M2: end";
        Err(strEnd);
    }
    if(flag > 0) s2(flag - 1);
}