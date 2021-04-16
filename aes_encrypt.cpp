#include <iostream>
#include <cstring>
#include "utils.h"

using namespace std;



void KeyExpansionCore(unsigned char* in, unsigned char i){
    unsigned int* q = (unsigned int*) in;
    *q = (*q >> 8) | ((*q & 0xff) << 24);

    in[0]=s[in[0]];
    in[1]=s[in[1]];
    in[2]=s[in[2]];
    in[3]=s[in[3]];

    in[0] ^= rcon[i];
}

void KeyExpansion(unsigned char* inputKey,unsigned char* expandedKeys){
    for(int i =0;i<16;i++){
        expandedKeys[i] = inputKey[i];
    }
    int bytesGenerated = 16;
    int rconIteration=1;
    unsigned char tmp[4];

    while(bytesGenerated<176){
        for(int i=0;i<4;i++){
            tmp[i]=expandedKeys[i+bytesGenerated-4];
        }
        if(bytesGenerated%16==0){
            KeyExpansionCore(tmp,rconIteration);
            rconIteration++;
        }
        for(unsigned char a=0;a<4;a++){
            expandedKeys[bytesGenerated]=expandedKeys[bytesGenerated-16]^tmp[a];
            bytesGenerated++;
        }
    }
}


void SubBytes(unsigned char* state){
    for(int i=0;i<16;i++){
        state[i]=s[state[i]];
    }
}
void ShiftRows(unsigned char* state){
    unsigned char tmp[16];

    tmp[0]=state[0];
    tmp[1]=state[5];
    tmp[2]=state[10];
    tmp[3]=state[15];

    tmp[4]=state[4];
    tmp[5]=state[9];
    tmp[6]=state[14];
    tmp[7]=state[3];

    tmp[8]=state[8];
    tmp[9]=state[13];
    tmp[10]=state[2];
    tmp[11]=state[7];

    tmp[12]=state[12];
    tmp[13]=state[1];
    tmp[14]=state[6];
    tmp[15]=state[11];

    for(int i = 0;i<16;i++){
        state[i]=tmp[i];
    }
}
void MixColumns(unsigned char* state){
    unsigned char tmp[16];

    tmp[0] = (unsigned char)(mul2[state[0]] ^ mul3[state[1]] ^ state[2] ^ state[3]);
    tmp[1] = (unsigned char)(state[0] ^ mul2[state[1]] ^ mul3[state[2]] ^ state[3]);
    tmp[2] = (unsigned char)(state[0] ^ state[1] ^ mul2[state[2]] ^ mul3[state[3]]);
    tmp[3] = (unsigned char)(mul3[state[0]] ^ state[1] ^ state[2] ^ mul2[state[3]]);

    tmp[4] = (unsigned char)(mul2[state[4]] ^ mul3[state[5]] ^ state[6] ^ state[7]);
    tmp[5] = (unsigned char)(state[4] ^ mul2[state[5]] ^ mul3[state[6]] ^ state[7]);
    tmp[6] = (unsigned char)(state[4] ^ state[5] ^ mul2[state[6]] ^ mul3[state[7]]);
    tmp[7] = (unsigned char)(mul3[state[4]] ^ state[5] ^ state[6] ^ mul2[state[7]]);

    tmp[8] = (unsigned char)(mul2[state[8]] ^ mul3[state[9]] ^ state[10] ^ state[11]);
    tmp[9] = (unsigned char)(state[8] ^ mul2[state[9]] ^ mul3[state[10]] ^ state[11]);
    tmp[10] = (unsigned char)(state[8] ^ state[9] ^ mul2[state[10]] ^ mul3[state[11]]);
    tmp[11] = (unsigned char)(mul3[state[8]] ^ state[9] ^ state[10] ^ mul2[state[11]]);

    tmp[12] = (unsigned char)(mul2[state[12]] ^ mul3[state[13]] ^ state[14] ^ state[15]);
    tmp[13] = (unsigned char)(state[12] ^ mul2[state[13]] ^ mul3[state[14]] ^ state[15]);
    tmp[14] = (unsigned char)(state[12] ^ state[13] ^ mul2[state[14]] ^ mul3[state[15]]);
    tmp[15] = (unsigned char)(mul3[state[12]] ^ state[13] ^ state[14] ^ mul2[state[15]]);

    for(int i =0;i<16;i++){
        state[i]=tmp[i];
    }
}
void AddRoundKey(unsigned char* state,unsigned char* roundKey){
    for(int i=0;i<16;i++){
        state[i] ^= roundKey[i];
    }
}


void Encrypt(unsigned char* message,unsigned char* key){

    unsigned char state[16];
    for(int i=0;i<16;i++){
        state[i]=message[i];
    }

    int NOR = 9;

    unsigned char expandedKey[176];
    KeyExpansion(key,expandedKey);
    AddRoundKey(state,key);

    for(int i=0;i<NOR;i++){
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        AddRoundKey(state,expandedKey+(16*(i+1)));

    }
    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state,expandedKey+160);

    for(int i = 0;i<16;i++){
        message[i]=state[i];
    }
}




int main(){

    
   
    string message_string;
    unsigned char key[16];
    cout << "Message to encrypt: ";
    
    getline(cin,message_string);
    cout << message_string;
    int n = message_string.length();
    char message[n+1];
    strcpy(message,message_string.c_str());
    
    cout << "Encryption key: ";
    for(int i=0;i<16;i++){
        cin >> key[i];
    }
    cout << "\n";





    int originalLen = strlen((const char*)message);
    int lenOfPaddedMessage = originalLen;

    if(lenOfPaddedMessage%16!=0){
        lenOfPaddedMessage=(lenOfPaddedMessage/16+1)*16;
    }
    unsigned char* paddedMessage = new unsigned char[lenOfPaddedMessage];
    for(int i =0;i<lenOfPaddedMessage;i++){
        if(i>=originalLen) paddedMessage[i]=0;
        else paddedMessage[i]=message[i];
    }
    for(int i = 0;i<lenOfPaddedMessage;i+=16){
    Encrypt(paddedMessage+i,key);
    }
    cout << "Encrypted Message: " <<endl;
    for(int i =0;i<lenOfPaddedMessage;i++){
        PrintHex(paddedMessage[i]);
        cout << " ";
    }
    delete[] paddedMessage;
    return 0;
}