#include <iostream>
#include <fstream>
#include <cstring>
#include "src/include/wren.hpp" //MAKE THIS POINT TO WREN.HPP IF IT DOESN'T ALREADY
#include "wren-embed.h"

namespace WrenEmbed {

    std::ofstream file;

    void wrenWrite(WrenVM* p_vm, const char* p_text) { //prints to console
        std::cout << p_text;
    }

    void wrenError(WrenVM* p_vm, WrenErrorType p_type, const char* p_module, int p_line, const char* p_message) { //prints error diagnostics
        std::cout << "Type: " << p_type << std::endl;
        std::cout << "Module: " << p_module << std::endl;
        std::cout << "Line: " << p_line << std::endl;
        std::cout << "Message: " << p_message << std::endl;
    }

    char* readFile(const char* p_fileName) { //returns contents of file
        std::ifstream in(p_fileName);
        std::string contents((std::istreambuf_iterator<char>(in)), 
            std::istreambuf_iterator<char>());
        char* f_string = new char[contents.length()];
        strcpy(f_string, contents.c_str());
        return f_string;
    }

    char* loadModule(WrenVM* p_vm, const char* p_moduleName) { //returns contents of file using module name

        const char* wrenExt = ".wren";
        char* fileName = new char[strlen(p_moduleName) + strlen(wrenExt)];
        strcpy(fileName, p_moduleName);
        strcat(fileName, wrenExt);

        return readFile(fileName);
    }
    
    void initWrenConfig(WrenConfiguration& p_config) {
        p_config.writeFn = wrenWrite;
        p_config.errorFn = wrenError;
        p_config.loadModuleFn = loadModule;
    }
}
