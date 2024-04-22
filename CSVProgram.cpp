#include <iostream>
#include "AshOfWar.h"
#include "AshOfWar.cpp"

int main()
{
    weaponAshFile ashFile;

    ashFile = LoadAshOfWarFile();

    ashFile = ApplyDefaultAshNames(ashFile);

    ashFile.EnableAllWeapons();

    WriteAshOfWarFile(ashFile, 1);
}

