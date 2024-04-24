#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "AshOfWar.h"



//Loads an Ash of War CSV file
weaponAshFile LoadAshOfWarFile() //add option for filepath
{
    //Variable that stores the decoded file
    weaponAshFile loadFile;
    int entryAmount = 217; //Add a check here for the file length so that the correct size can be reserved
    loadFile.CreateFilespace(entryAmount);

    //Variable that holds the file to be read
    std::ifstream fileToLoad;
    fileToLoad.open("EquipParamGem.csv"); //Add a way to import different files
    std::string csvFileLine = "";
    std::getline(fileToLoad, csvFileLine);

    //Loop to add each value to a string vector
    std::vector<std::string> loadedFileLine;
    loadedFileLine.reserve(91);

    std::string subString = "";
    int stringPosision = 0;
    size_t foundPosision = 0;

    for (int j = 0; j < entryAmount; j++)
    {
        stringPosision = 0;
        foundPosision = 0;
        loadedFileLine.clear();
        for (int i = 0; i < 91; i++)
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


//Writing the saved csv to a file
void WriteAshOfWarFile(weaponAshFile file) //Add option for filepath
{
    int entryAmount = file.ashLineVector.size();
    std::ofstream fileToWrite;
    fileToWrite.open("Log.txt");

    //if there is an info line then print that first
    if (file.infoLine != "")
    {
        fileToWrite << file.infoLine << std::endl;
        fileToWrite.flush();
        entryAmount -= 1;
    }

    //Print all lines to file, decoded bytes
    for (int i = 0; i < entryAmount; i++)
    {
        fileToWrite << file.DecodedLine(i);
        fileToWrite << std::endl;
        fileToWrite.flush();
    }
}

//Writing the saved csv to a file
void WriteAshOfWarFile(weaponAshFile file, bool encoded) //Add option for filepath
{
    int entryAmount = file.ashLineVector.size();
    std::ofstream fileToWrite;
    fileToWrite.open("EquipParamGemOutput.txt");

    //if there is an info line then print that first
    if (file.infoLine != "")
    {
        fileToWrite << file.infoLine << std::endl;
        fileToWrite.flush();
        entryAmount -= 1;
    }

    if (encoded)
    {
        //Print all lines to file, encoded bytes
        for (int i = 0; i < entryAmount; i++)
        {
            fileToWrite << file.EncodedLine(i);
            fileToWrite << std::endl;
            fileToWrite.flush();
        }
    }
    else
    {
        //Print all lines to file, decoded bytes
        for (int i = 0; i < entryAmount; i++)
        {
            fileToWrite << file.DecodedLine(i);
            fileToWrite << std::endl;
            fileToWrite.flush();
        }
    }
}

weaponAshFile ApplyDefaultAshNames(weaponAshFile file)
{
    class ashName
    {
    public:
        int ashID = 0;
        std::string ashName;
    };

    std::vector<ashName> ashNameVector;
    ashNameVector.reserve(94);

    std::ifstream ashNameFile;
    ashNameFile.open("DefaultAshNames.txt");

    std::string currentFileLine = "";
    std::getline(ashNameFile, currentFileLine);

    ashName currentLine;
    int foundPosision = 0;
    int stringPosision = 0;
    for (int i = 0; i < 94; i++)
    {
        foundPosision = 0;
        foundPosision = currentFileLine.find(';');
        stringPosision = foundPosision + 1;
        currentLine.ashID = stoi(currentFileLine.substr(0, foundPosision));
        foundPosision = currentFileLine.find(';', foundPosision + 1);
        currentLine.ashName = currentFileLine.substr(stringPosision, foundPosision - stringPosision);

        ashNameVector.push_back(currentLine);

        std::getline(ashNameFile, currentFileLine);
    }

    for (int i = 0; i < file.ashLineVector.size(); i++)
    {
        for (int j = 0; j < ashNameVector.size(); j++)
        {
            if (file.ashLineVector[i].rowID == ashNameVector[j].ashID)
            {
                file.ashLineVector[i].rowName = ashNameVector[j].ashName;
            }
        }
    }

    return file;
}

void WeaponAshEditor()
{
    //Start user interface
    system("cls");

    std::cout << "========================================\n ASH OF WAR EDITOR \n========================================\n";
    std::cout << "Please select an option:\n(input one character)\n\nL : Load an ash of war file\n";

    char userResponse = NULL;
    std::cin >> userResponse;
    switch (userResponse)
    {
    case 'l':
        LoadAshOfWarFile();
        break;
    case 'L':
        LoadAshOfWarFile();
        break;
    default:
        WeaponAshEditor();
        break;
    }


}
