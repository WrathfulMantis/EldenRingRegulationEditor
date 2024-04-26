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
    
    WepParamFile wepParamFile;

    wepParamFile = LoadWepParamFile();
    wepParamFile = ApplyDefaultwepParamNames(wepParamFile);

    std::cout << "Done";
}

