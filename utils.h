#pragma once
#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED




using namespace std;
#include <iostream>
#include <sys/stat.h>



 


// -----------------------------------------------------------------------------------------------Utilities-----------------------------------------------------------------------------------------------


 void KeyExpansionCore(unsigned char* in, unsigned char i);

 void KeyExpansion(unsigned char* inputKey, unsigned char* expandedKeys);

 void PrintHex(unsigned char x);

 long long int GetFileSize(string filename);




#endif