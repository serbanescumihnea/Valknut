//
// Created by serba on 5/15/2021.
//

#ifndef RANSOMCLION_UTILS_H
#define RANSOMCLION_UTILS_H






using namespace std;
#include <iostream>
#include <sys/stat.h>






// -----------------------------------------------------------------------------------------------Utilities-----------------------------------------------------------------------------------------------


void KeyExpansionCore(unsigned char* in, unsigned char i);

void KeyExpansion(unsigned char* inputKey, unsigned char* expandedKeys);

void PrintHex(unsigned char x);

long long int GetFileSize(string filename);





#endif //RANSOMCLION_UTILS_H
