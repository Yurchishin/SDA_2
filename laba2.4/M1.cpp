#include <iostream>
#include "M1.h""

using namespace std;

void s1()
{
    string str = "Error: work, Function s1, M1: work\n";
    Err(str);
    s5();
    s6();
    string strEnd = "Function S1, M1: end";
    Err(strEnd);
}

void s2(int flag)
{
    string str = "Function s2, M1: work\n";
    Err(str);
    s6();
    s7(flag);
    string strEnd = "Function S2, M1: end";
    Err(strEnd);
}

void s3()
{
    string str = "Function s3, M1: work\n";
    Err(str);
    s8();
    s9();
    s10();
    string strEnd = "Function S3, M1: end";
    Err(strEnd);
}

void s4()
{
    string str = "Function s4, M1: work\n";
    Err(str);
    s9();
    s10();
    string strEnd = "Function S4, M1: end";
    Err(strEnd);
}