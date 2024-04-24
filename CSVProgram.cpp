#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "AshOfWar.h"
#include "WepParam.h"



int main()
{
    
    weaponAshFile ashFile;

    ashFile = LoadAshOfWarFile();

    ashFile = ApplyDefaultAshNames(ashFile);

    ashFile.EnableAllWeapons();

    WriteAshOfWarFile(ashFile, 1);
    
    wepParamLine newLine;
    std::cout << "Done";
}

