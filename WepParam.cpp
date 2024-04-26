#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "WepParam.h"

WepParamFile LoadWepParamFile()
{
    //Variable that stores the decoded file
    WepParamFile loadFile;
    int entryAmount = 5572; //Add a check here for the file length so that the correct size can be reserved
    loadFile.CreateFilespace(entryAmount);

    //Variable that holds the file to be read
    std::ifstream fileToLoad;
    fileToLoad.open("EquipParamWeapon.csv"); //Add a way to import different files
    std::string csvFileLine = "";
    std::getline(fileToLoad, csvFileLine);

    //Loop to add each value to a string vector
    std::vector<std::string> loadedFileLine;
    loadedFileLine.reserve(264);

    std::string subString = "";
    int stringPosision = 0;
    size_t foundPosision = 0;

    for (int j = 0; j < entryAmount; j++)
    {
        stringPosision = 0;
        foundPosision = 0;
        loadedFileLine.clear();
        for (int i = 0; i < 264; i++)
        {
            if (stringPosision == 0)
            {
                foundPosision = csvFileLine.find(';');
            }
            else
            {
                foundPosision = csvFileLine.find(';', foundPosision + 1);
            }
            subString = csvFileLine.substr(stringPosision, foundPosision - stringPosision);
            loadedFileLine.insert(loadedFileLine.begin() + i, subString);
            stringPosision = foundPosision + 1;
        }
        //Sends string vector to the file class for processing
        loadFile.LoadFileLineFromCSV(loadedFileLine);
        std::getline(fileToLoad, csvFileLine);
    }

    fileToLoad.close();

    return loadFile;
}

WepParamFile ApplyDefaultwepParamNames(WepParamFile file)
{
    class wepParamName
    {
    public:
        int wepParamID = 0;
        std::string wepParamName;
    };

    std::vector<wepParamName> wepParamNameVector;
    wepParamNameVector.reserve(264);

    std::ifstream wepParamNameFile;
    wepParamNameFile.open("DefaultWepParamNames.txt");

    std::string currentFileLine = "";
    std::getline(wepParamNameFile, currentFileLine);

    wepParamName currentLine;
    int foundPosision = 0;
    int stringPosision = 0;
    for (int i = 0; i < 264; i++)
    {
        foundPosision = 0;
        foundPosision = currentFileLine.find(';');
        stringPosision = foundPosision + 1;
        currentLine.wepParamID = stoi(currentFileLine.substr(0, foundPosision));
        foundPosision = currentFileLine.find(';', foundPosision + 1);
        currentLine.wepParamName = currentFileLine.substr(stringPosision, foundPosision - stringPosision);

        wepParamNameVector.push_back(currentLine);

        std::getline(wepParamNameFile, currentFileLine);
    }

    for (int i = 0; i < file.wepParamLineVector.size(); i++)
    {
        for (int j = 0; j < wepParamNameVector.size(); j++)
        {
            if (file.wepParamLineVector[i].rowID / 10000 == wepParamNameVector[j].wepParamID / 10000)
            {
                file.wepParamLineVector[i].rowName = wepParamNameVector[j].wepParamName;
            }
        }
    }

    return file;
}
