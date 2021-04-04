#include <string>
#include "EncryptionEngine.h"

using namespace std;


string XOR_Encryption(string data, char key[]) {
	string output=data;
	for (int i = 0; i < data.size(); i++) {
		output[i] = data[i] ^ key[i % (sizeof(key) / sizeof(char))];
	}
	return output;
}



EncryptionEngine::EncryptionEngine() {

}
EncryptionEngine::~EncryptionEngine() {

}

