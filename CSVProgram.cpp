#include <iostream>
#include "AshOfWar.h"
#include "AshOfWar.cpp"
#include "WepParam.h"

int main()
{
    weaponAshFile ashFile;

    ashFile = LoadAshOfWarFile();

    ashFile = ApplyDefaultAshNames(ashFile);

    ashFile.EnableAllWeapons();

    WriteAshOfWarFile(ashFile, 1);
}

