#include "RansomwareApp.h"

#include <fstream>
#include <string>
using namespace std;


wxIMPLEMENT_APP(RansomwareApp);


RansomwareApp::RansomwareApp() {

}

RansomwareApp::~RansomwareApp() {

}

bool RansomwareApp::OnInit() {

	
	application_frame1 = new RansomwareMain();
	application_frame1->Show();
	
	ifstream file("test.txt");
	ofstream file2("test2.txt");
	char key[4] = { 'K','e','y','y'};
	ifstream file3("test2.txt");
	ofstream file4("test3.txt");
	for (string line; getline(file, line);) {
		file2 << XOR_Encryption(line, key);
	}


	file.close();
	file2.close();
	for(string line;getline(file3,line);){
		file4 << XOR_Encryption(line, key);
	}
	
	file3.close();
	file4.close();

	return true;
}
