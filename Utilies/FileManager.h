#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include "../Manager.h"
#include <string>
#include <fstream>
using namespace std;

class FileManager {
public:
    static void loadAll(Manager& manager);
    static void saveAll(Manager& manager);   
};

#endif