#include <fstream>
#include "src/include/wren.hpp"

#ifndef WRENEMBED
#define WRENEMBED

namespace WrenEmbed {

    extern std::ofstream file;



    void wrenWrite(WrenVM* p_vm, const char* p_text);

    void wrenError(WrenVM* p_vm, WrenErrorType p_type, const char* p_module, int p_line, const char* p_message);

    char* readFile(const char* p_fileName);

    char* loadModule(WrenVM* p_vm, const char* p_moduleName);
    
    void wrenOpenFile(WrenVM* p_vm);

    void wrenOpenFileAppend(WrenVM* p_vm);

    void wrenInsertTextFile(WrenVM* p_vm);

    void wrenCloseFile(WrenVM* p_vm);

    WrenForeignMethodFn bindForeignMethod(WrenVM* p_vm, const char* p_module, const char* p_className, bool p_isStatic, const char* p_signature);
    

    void initWrenConfig(WrenConfiguration& p_config);
    
};

#endif