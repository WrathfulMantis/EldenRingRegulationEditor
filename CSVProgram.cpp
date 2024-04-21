#include <conio.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

//AshOfWar_Bitmasks
#pragma region
//Affinity bools stored as bits in a 32bit unsigned int
const uint32_t AFFINITY_STANDARD_BIT = 1 << 0; //17
const uint32_t AFFINITY_HEAVY_BIT = 1 << 1; //18
const uint32_t AFFINITY_KEEN_BIT = 1 << 2; //19
const uint32_t AFFINITY_QUALITY_BIT = 1 << 3; //20
const uint32_t AFFINITY_FIRE_BIT = 1 << 4; //21
const uint32_t AFFINITY_FLAMEART_BIT = 1 << 5; //22
const uint32_t AFFINITY_LIGHTNING_BIT = 1 << 6; //23
const uint32_t AFFINITY_SACRED_BIT = 1 << 7; //24
const uint32_t AFFINITY_MAGIC_BIT = 1 << 8; //25
const uint32_t AFFINITY_COLD_BIT = 1 << 9; //26
const uint32_t AFFINITY_POISON_BIT = 1 << 10; //27
const uint32_t AFFINITY_BLOOD_BIT = 1 << 11; //28
const uint32_t AFFINITY_OCCULT_BIT = 1 << 12; //29
const uint32_t AFFINITY_13_BIT = 1 << 13; //30
const uint32_t AFFINITY_14_BIT = 1 << 14; //31
const uint32_t AFFINITY_15_BIT = 1 << 15; //32
const uint32_t AFFINITY_16_BIT = 1 << 16; //34
const uint32_t AFFINITY_17_BIT = 1 << 17; //35
const uint32_t AFFINITY_18_BIT = 1 << 18; //36
const uint32_t AFFINITY_19_BIT = 1 << 19; //37
const uint32_t AFFINITY_20_BIT = 1 << 20; //38
const uint32_t AFFINITY_21_BIT = 1 << 21; //39
const uint32_t AFFINITY_22_BIT = 1 << 22; //40
const uint32_t AFFINITY_23_BIT = 1 << 23; //41

//Affinity Options stored as 8bit unsigned int
const uint8_t IS_DISCARD_BIT = 1 << 0; //42
const uint8_t IS_DROP_BIT = 1 << 1; //43
const uint8_t IS_DEPOSIT_BIT = 1 << 2; //44
const uint8_t IS_DROP_MULTIPLAYER_BIT = 1 << 3; //45
const uint8_t SHOW_CONDITION_TYPE_BIT = 1 << 4; //47
const uint8_t DISABLE_NETWORK_TEST_BIT = 1 << 5; //2

//Weapon Mainhand stored as 32bit unsigned int
const uint32_t DAGGER_BIT = 1 << 0; //49
const uint32_t SHORTSWORD_BIT = 1 << 1; //50
const uint32_t GREATSWORD_BIT = 1 << 2; //51
const uint32_t ULTRAGREATSWORD_BIT = 1 << 3; //52
const uint32_t CURVEDSWORD_BIT = 1 << 4; //53
const uint32_t CURVEDGREATSWORD_BIT = 1 << 5; //54
const uint32_t KATANA_BIT = 1 << 6; //55
const uint32_t TWINBLADE_BIT = 1 << 7; //56
const uint32_t RAPIER_BIT = 1 << 8; //57
const uint32_t GREATRAPIER_BIT = 1 << 9; //58
const uint32_t AXE_BIT = 1 << 10; //59
const uint32_t GREATAXE_BIT = 1 << 11; //60
const uint32_t HAMMER_BIT = 1 << 12; //61
const uint32_t GREATHAMMER_BIT = 1 << 13; //62
const uint32_t FLAIL_BIT = 1 << 14; //63
const uint32_t SPEAR_BIT = 1 << 15; //64
const uint32_t LARGESPEAR_BIT = 1 << 16; //65
const uint32_t HEAVYSPEAR_BIT = 1 << 17; //66
const uint32_t HALBERD_BIT = 1 << 18; //67
const uint32_t REAPER_BIT = 1 << 19; //68
const uint32_t FIST_BIT = 1 << 20; //69
const uint32_t CLAW_BIT = 1 << 21; //70
const uint32_t WHIP_BIT = 1 << 22; //71
const uint32_t COLLOSALWEAPON_BIT = 1 << 23; //72
const uint32_t SHORTBOW_BIT = 1 << 24; //73
const uint32_t LONGBOW_BIT = 1 << 25; //74
const uint32_t GREATBOW_BIT = 1 << 26; //75
const uint32_t CROSSBOW_BIT = 1 << 27; //76
const uint32_t BALLISTA_BIT = 1 << 28; //77

//Weapon Offhand stored as 8bit unsigned int
const uint8_t STAFF_BIT = 1 << 0; //78
const uint8_t UNUSEDCATALIST_BIT = 1 << 1; //79
const uint8_t TALISMAN_BIT = 1 << 2; //80
const uint8_t SMALLSHIELD_BIT = 1 << 3; //81
const uint8_t MEDSHIELD_BIT = 1 << 4; //82
const uint8_t GREATSHIELD_BIT = 1 << 5; //83
const uint8_t TORCH_BIT = 1 << 6; //84
#pragma endregion

//Should hold every variable in the ash of war line & should have every function that can happen within one single line
class weaponAshLine
{
public:
    //RowIdentity
    int rowID = -1; //0
    std::string rowName = ""; //1

    //Bool

    uint32_t storedAffinityBytes = 0;

    uint8_t storedInventoryOptions = 0;

    uint32_t storedMainHandWeapons = 0;

    uint8_t storedOffhandWeapons = 0;

    //Int
    uint16_t iconID = 0; //3
    uint8_t rank = 0; //4
    uint8_t sortGroupID = 0; //5

    int32_t spEffectID0 = -1; //6
    int32_t spEffectID1 = -1; //7
    int32_t spEffectID2 = -1; //8

    uint32_t itemGetTutorialFlagID = 0; //9
    int32_t swortArtParamID = -1; //10
    int32_t mountID = -1; //11
    int32_t sellValue = -1; //12
    int32_t saleValue = -1; //13
    int32_t sortID = -1; //14
    int16_t achievementID = -1; //15
    int16_t achievementSequentialID = -1; //16
    int8_t rarity = 0; //33
    int8_t showDialogCondType = 0; //46
    uint8_t defaultWeaponAffinity = 0; //48

    int32_t spEffectMsgId0 = -1; //85
    int32_t spEffectMsgId1 = -1; //86
    int32_t spEffectID_ForAttack0 = -1; //87
    int32_t spEffectID_ForAttack1 = -1; //88
    int32_t spEffectID_ForAttack2 = -1; //89

    int32_t MountWepTextID = -1; //90

    //Functions
#pragma region
    void EnableAffinity(uint32_t affinity)
    {
        storedAffinityBytes = storedAffinityBytes | affinity;
    }

    bool QueryAffinity(uint32_t affinity)
    {
        if (storedAffinityBytes & affinity)
            return true;
        else
            return false;
    }

    void DisableAffinity(uint32_t affinity)
    {
        if (QueryAffinity(affinity))
            storedAffinityBytes -= affinity;
        //else
        //     it isn't there? Do nothing
    }

    void EnableAllAffinity()
    {
        storedAffinityBytes = storedAffinityBytes | 0b00000000011111111111111111111111;
    }


    void EnableOption(uint8_t option)
    {
        storedInventoryOptions = storedInventoryOptions | option;
    }

    bool QueryOption(uint8_t option)
    {
        if (storedInventoryOptions & option)
            return true;
        else
            return false;
    }

    void DisableOption(uint8_t option)
    {
        if (QueryOption(option))
            storedInventoryOptions -= option;
        //else
        //     it isn't there? Do nothing
    }


    void EnableMainhandWeapons(uint32_t weaponAffinity)
    {
        storedMainHandWeapons = storedMainHandWeapons | weaponAffinity;
    }

    bool QueryMainhandWeapons(uint32_t weaponAffinity)
    {
        if (storedMainHandWeapons & weaponAffinity)
            return true;
        else
            return false;
    }

    void DisableMainhandWeapons(uint32_t weaponAffinity)
    {
        if (QueryMainhandWeapons(weaponAffinity))
            storedMainHandWeapons -= weaponAffinity;
        //else
        //     it isn't there? Do nothing
    }

    void EnableAllMainhandWeapons()
    {
        storedMainHandWeapons = storedMainHandWeapons | 0b00011111111111111111111111111111;
    }


    void EnableOffhandWeapons(uint8_t weaponAffinity)
    {
        storedOffhandWeapons = storedOffhandWeapons | weaponAffinity;
    }

    bool QueryOffhandWeapons(uint8_t weaponAffinity)
    {
        if (storedOffhandWeapons & weaponAffinity)
            return true;
        else
            return false;
    }

    void DisableOffhandWeapons(uint8_t weaponAffinity)
    {
        if (QueryOffhandWeapons(weaponAffinity))
            storedOffhandWeapons -= weaponAffinity;
        //else
        //     it isn't there? Do nothing
    }

    void EnableAllOffhandWeapons()
    {
        storedOffhandWeapons = storedOffhandWeapons | 0b01111111;
    }
#pragma endregion
};

//Should store every line in an ash of war file using the class above
class weaponAshFile
{
public:
    //Create a vector for the ashes of war
    //217 Ashes in the basegame file
    //Maybe add an option to increase this later?
    std::vector<weaponAshLine> ashLineVector;

    void CreateFilespace()
    {
        ashLineVector.reserve(217);
    }
    void CreateFilespace(int reserveSpace)
    {
        ashLineVector.reserve(reserveSpace);
    }

    std::string infoLine = "";
    void LoadFileLineFromCSV(std::vector<std::string> stringVector)
    {
        if (stringVector[0] == "Row ID")
        {
            for (int i = 0; i < 91; i++)
            {
                infoLine.append(stringVector[i]);
                if (i != 90)
                {
                    infoLine.append(";");
                }
            }
        }
        else
        {
            ashLineVector.push_back(weaponAshLine());

            //Line Info
            ashLineVector.back().rowID = std::stoi(stringVector[0]);
            ashLineVector.back().rowName = stringVector[1];

            //Affinity byte constuctor
            uint32_t storedAffinityBytes = 0;
            #pragma region
            if (stoi(stringVector[17]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_STANDARD_BIT;
            }
            if (stoi(stringVector[18]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_HEAVY_BIT;
            }
            if (stoi(stringVector[19]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_KEEN_BIT;
            }
            if (stoi(stringVector[20]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_QUALITY_BIT;
            }
            if (stoi(stringVector[21]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_FIRE_BIT;
            }
            if (stoi(stringVector[22]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_FLAMEART_BIT;
            }
            if (stoi(stringVector[23]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_LIGHTNING_BIT;
            }
            if (stoi(stringVector[24]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_SACRED_BIT;
            }
            if (stoi(stringVector[25]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_MAGIC_BIT;
            }
            if (stoi(stringVector[26]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_COLD_BIT;
            }
            if (stoi(stringVector[27]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_POISON_BIT;
            }
            if (stoi(stringVector[28]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_BLOOD_BIT;
            }
            if (stoi(stringVector[29]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_OCCULT_BIT;
            }
            if (stoi(stringVector[30]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_13_BIT;
            }
            if (stoi(stringVector[31]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_14_BIT;
            }
            if (stoi(stringVector[32]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_15_BIT;
            }
            if (stoi(stringVector[34]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_16_BIT;
            }
            if (stoi(stringVector[35]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_17_BIT;
            }
            if (stoi(stringVector[36]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_18_BIT;
            }
            if (stoi(stringVector[37]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_19_BIT;
            }
            if (stoi(stringVector[38]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_20_BIT;
            }
            if (stoi(stringVector[39]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_21_BIT;
            }
            if (stoi(stringVector[40]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_22_BIT;
            }
            if (stoi(stringVector[41]) != 0)
            {
                storedAffinityBytes = storedAffinityBytes | AFFINITY_23_BIT;
            }
            #pragma endregion
            ashLineVector.back().storedAffinityBytes = storedAffinityBytes;

            //Option byte constructor
            uint8_t storedOptionBytes = 0;
            #pragma region
            if (stoi(stringVector[42]) != 0)
            {
                storedOptionBytes = storedOptionBytes | IS_DISCARD_BIT;
            }
            if (stoi(stringVector[43]) != 0)
            {
                storedOptionBytes = storedOptionBytes | IS_DROP_BIT;
            }
            if (stoi(stringVector[44]) != 0)
            {
                storedOptionBytes = storedOptionBytes | IS_DEPOSIT_BIT;
            }
            if (stoi(stringVector[45]) != 0)
            {
                storedOptionBytes = storedOptionBytes | IS_DROP_MULTIPLAYER_BIT;
            }
            if (stoi(stringVector[47]) != 0)
            {
                storedOptionBytes = storedOptionBytes | SHOW_CONDITION_TYPE_BIT;
            }
            if (stoi(stringVector[2]) != 0)
            {
                storedOptionBytes = storedOptionBytes | DISABLE_NETWORK_TEST_BIT;
            }
            #pragma endregion
            ashLineVector.back().storedInventoryOptions = storedOptionBytes;

            //Mainhand weapon byte constructor
            uint32_t mainHandWeaponBytes = 0;
            #pragma region
            if (stoi(stringVector[49]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | DAGGER_BIT;
            }
            if (stoi(stringVector[50]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | SHORTSWORD_BIT;
            }
            if (stoi(stringVector[51]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | GREATSWORD_BIT;
            }
            if (stoi(stringVector[52]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | ULTRAGREATSWORD_BIT;
            }
            if (stoi(stringVector[53]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | CURVEDSWORD_BIT;
            }
            if (stoi(stringVector[54]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | CURVEDGREATSWORD_BIT;
            }
            if (stoi(stringVector[55]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | KATANA_BIT;
            }
            if (stoi(stringVector[56]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | TWINBLADE_BIT;
            }
            if (stoi(stringVector[57]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | RAPIER_BIT;
            }
            if (stoi(stringVector[58]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | GREATRAPIER_BIT;
            }
            if (stoi(stringVector[59]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | AXE_BIT;
            }
            if (stoi(stringVector[60]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | GREATAXE_BIT;
            }
            if (stoi(stringVector[61]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | HAMMER_BIT;
            }
            if (stoi(stringVector[62]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | GREATHAMMER_BIT;
            }
            if (stoi(stringVector[63]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | FLAIL_BIT;
            }
            if (stoi(stringVector[64]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | SPEAR_BIT;
            }
            if (stoi(stringVector[65]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | LARGESPEAR_BIT;
            }
            if (stoi(stringVector[66]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | HEAVYSPEAR_BIT;
            }
            if (stoi(stringVector[67]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | HALBERD_BIT;
            }
            if (stoi(stringVector[68]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | REAPER_BIT;
            }
            if (stoi(stringVector[69]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | FIST_BIT;
            }
            if (stoi(stringVector[70]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | CLAW_BIT;
            }
            if (stoi(stringVector[71]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | WHIP_BIT;
            }
            if (stoi(stringVector[72]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | COLLOSALWEAPON_BIT;
            }
            if (stoi(stringVector[73]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | SHORTBOW_BIT;
            }
            if (stoi(stringVector[74]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | LONGBOW_BIT;
            }
            if (stoi(stringVector[75]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | GREATBOW_BIT;
            }
            if (stoi(stringVector[76]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | CROSSBOW_BIT;
            }
            if (stoi(stringVector[77]) != 0)
            {
                mainHandWeaponBytes = mainHandWeaponBytes | BALLISTA_BIT;
            }
            #pragma endregion
            ashLineVector.back().storedMainHandWeapons = mainHandWeaponBytes;

            //Offhand weapon byte constructor

            //Option byte constructor
            uint8_t offHandWeaponBytes = 0;
            #pragma region
            if (stoi(stringVector[78]) != 0)
            {
                offHandWeaponBytes = offHandWeaponBytes | STAFF_BIT;
            }
            if (stoi(stringVector[79]) != 0)
            {
                offHandWeaponBytes = offHandWeaponBytes | UNUSEDCATALIST_BIT;
            }
            if (stoi(stringVector[80]) != 0)
            {
                offHandWeaponBytes = offHandWeaponBytes | TALISMAN_BIT;
            }
            if (stoi(stringVector[81]) != 0)
            {
                offHandWeaponBytes = offHandWeaponBytes | SMALLSHIELD_BIT;
            }
            if (stoi(stringVector[82]) != 0)
            {
                offHandWeaponBytes = offHandWeaponBytes | MEDSHIELD_BIT;
            }
            if (stoi(stringVector[83]) != 0)
            {
                offHandWeaponBytes = offHandWeaponBytes | GREATSHIELD_BIT;
            }
            if (stoi(stringVector[84]) != 0)
            {
                offHandWeaponBytes = offHandWeaponBytes | TORCH_BIT;
            }
            #pragma endregion
            ashLineVector.back().storedOffhandWeapons = offHandWeaponBytes;

            //Int insersion
            ashLineVector.back().iconID = stoi(stringVector[3]);
            ashLineVector.back().rank = stoi(stringVector[4]);
            ashLineVector.back().sortGroupID = stoi(stringVector[5]);

            ashLineVector.back().spEffectID0 = stoi(stringVector[6]);
            ashLineVector.back().spEffectID1 = stoi(stringVector[7]);
            ashLineVector.back().spEffectID2 = stoi(stringVector[8]);

            ashLineVector.back().itemGetTutorialFlagID = stoi(stringVector[9]);
            ashLineVector.back().swortArtParamID = stoi(stringVector[10]);
            ashLineVector.back().mountID = stoi(stringVector[11]);
            ashLineVector.back().sellValue = stoi(stringVector[12]);
            ashLineVector.back().saleValue = stoi(stringVector[13]);
            ashLineVector.back().sortID = stoi(stringVector[14]);
            ashLineVector.back().achievementID = stoi(stringVector[15]);
            ashLineVector.back().achievementSequentialID = stoi(stringVector[16]);
            ashLineVector.back().rarity = stoi(stringVector[33]);
            ashLineVector.back().showDialogCondType = stoi(stringVector[46]);
            ashLineVector.back().defaultWeaponAffinity = stoi(stringVector[48]);

            ashLineVector.back().spEffectMsgId0 = stoi(stringVector[85]);
            ashLineVector.back().spEffectMsgId1 = stoi(stringVector[86]);
            ashLineVector.back().spEffectID_ForAttack0 = stoi(stringVector[87]);
            ashLineVector.back().spEffectID_ForAttack1 = stoi(stringVector[88]);
            ashLineVector.back().spEffectID_ForAttack2 = stoi(stringVector[89]);

            ashLineVector.back().MountWepTextID = stoi(stringVector[90]);
        }
    }

    void EnableAllWeapons()
    {
        for (int i = 0; i < ashLineVector.size(); i++)
        {
            ashLineVector[i].EnableAllMainhandWeapons();
            ashLineVector[i].EnableAllOffhandWeapons();
        }
    }
    
    //Returns an encoded csv line as a string
    std::string EncodedLine(int entry)
    {
        std::string fullLine = "";

        fullLine.append(std::to_string(ashLineVector.at(entry).rowID));
        fullLine.append(";");
        fullLine.append(ashLineVector.at(entry).rowName);
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).storedAffinityBytes));
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).storedInventoryOptions)));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).storedMainHandWeapons));
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).storedOffhandWeapons)));
        fullLine.append(";");

        fullLine.append(std::to_string(ashLineVector.at(entry).iconID));
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).rank)));
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).sortGroupID)));
        fullLine.append(";");

        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID0));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID1));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID2));
        fullLine.append(";");

        fullLine.append(std::to_string(ashLineVector.at(entry).itemGetTutorialFlagID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).swortArtParamID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).mountID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).sellValue));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).saleValue));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).sortID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).achievementID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).achievementSequentialID));
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).rarity)));
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).showDialogCondType)));
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).defaultWeaponAffinity)));
        fullLine.append(";");

        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectMsgId0));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectMsgId1));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID_ForAttack0));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID_ForAttack1));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID_ForAttack2));
        fullLine.append(";");

        fullLine.append(std::to_string(ashLineVector.at(entry).MountWepTextID));
        fullLine.append(";");

        return fullLine;
    }

    //Returns a decoded csv line as a string
    std::string DecodedLine(int entry)
    {
        std::string fullLine = "";

        fullLine.append(std::to_string(ashLineVector.at(entry).rowID));//0
        fullLine.append(";");
        fullLine.append(ashLineVector.at(entry).rowName);//1
        fullLine.append(";");

        if (ashLineVector.at(entry).storedInventoryOptions & DISABLE_NETWORK_TEST_BIT)
        {
            fullLine.append("1;");
        } 
        else
        {
            fullLine.append("0;");
        }

        fullLine.append(std::to_string(ashLineVector.at(entry).iconID)); //3
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).rank))); 
        fullLine.append(";");
        fullLine.append(std::to_string(int(ashLineVector.at(entry).sortGroupID))); 
        fullLine.append(";");

        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID0)); 
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID1)); 
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID2)); 
        fullLine.append(";");

        fullLine.append(std::to_string(ashLineVector.at(entry).itemGetTutorialFlagID)); 
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).swortArtParamID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).mountID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).sellValue));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).saleValue));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).sortID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).achievementID));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).achievementSequentialID)); //16
        fullLine.append(";");

        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_STANDARD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_HEAVY_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_KEEN_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_QUALITY_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_FIRE_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_FLAMEART_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_LIGHTNING_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_SACRED_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_MAGIC_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_COLD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_POISON_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_BLOOD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_OCCULT_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_13_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_14_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_15_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }

        fullLine.append(std::to_string(int(ashLineVector.at(entry).rarity))); //33
        fullLine.append(";");

        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_16_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_17_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_18_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_19_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_20_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_21_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_22_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedAffinityBytes & AFFINITY_23_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }


        if (ashLineVector.at(entry).storedInventoryOptions & IS_DISCARD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedInventoryOptions & IS_DROP_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedInventoryOptions & IS_DEPOSIT_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedInventoryOptions & IS_DROP_MULTIPLAYER_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }

        fullLine.append(std::to_string(int(ashLineVector.at(entry).showDialogCondType))); //46
        fullLine.append(";");


        if (ashLineVector.at(entry).storedInventoryOptions & SHOW_CONDITION_TYPE_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }

        fullLine.append(std::to_string(int(ashLineVector.at(entry).defaultWeaponAffinity))); //48
        fullLine.append(";");


        if (ashLineVector.at(entry).storedMainHandWeapons & DAGGER_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & SHORTSWORD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & GREATSWORD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & ULTRAGREATSWORD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & CURVEDSWORD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & CURVEDGREATSWORD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & KATANA_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & TWINBLADE_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & RAPIER_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & GREATRAPIER_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & AXE_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & GREATAXE_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & HAMMER_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & GREATHAMMER_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & FLAIL_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & SPEAR_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & LARGESPEAR_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & HEAVYSPEAR_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & HALBERD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & REAPER_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & FIST_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & CLAW_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & WHIP_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & COLLOSALWEAPON_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & SHORTBOW_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & LONGBOW_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & GREATBOW_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & CROSSBOW_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedMainHandWeapons & BALLISTA_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }


        if (ashLineVector.at(entry).storedOffhandWeapons & STAFF_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedOffhandWeapons & UNUSEDCATALIST_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedOffhandWeapons & TALISMAN_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedOffhandWeapons & SMALLSHIELD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedOffhandWeapons & MEDSHIELD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedOffhandWeapons & GREATSHIELD_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }
        if (ashLineVector.at(entry).storedOffhandWeapons & TORCH_BIT)
        {
            fullLine.append("1;");
        }
        else
        {
            fullLine.append("0;");
        }

        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectMsgId0)); //85
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectMsgId1));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID_ForAttack0));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID_ForAttack1));
        fullLine.append(";");
        fullLine.append(std::to_string(ashLineVector.at(entry).spEffectID_ForAttack2));
        fullLine.append(";");

        fullLine.append(std::to_string(ashLineVector.at(entry).MountWepTextID)); //90
        fullLine.append(";");

        return fullLine;
    }
};

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

    //Writing the saved csv to a file
    std::ofstream fileToWrite;
    fileToWrite.open("Log.txt");

    //if there is an info line then print that first
    if (loadFile.infoLine != "")
    {
        fileToWrite << loadFile.infoLine << std::endl;
        fileToWrite.flush();
        entryAmount -= 1;
    }

    //Print all lines to file, encoded bytes
    for (int i = 0; i < entryAmount; i++)
    {
        /*
        fileToWrite << loadFile.ashLineVector.at(i).rowID << ';';
        fileToWrite << loadFile.ashLineVector.at(i).rowName << ';';
        fileToWrite << loadFile.ashLineVector.at(i).storedAffinityBytes << ';';
        fileToWrite << int(loadFile.ashLineVector.at(i).storedInventoryOptions) << ';';
        fileToWrite << loadFile.ashLineVector.at(i).storedMainHandWeapons << ';';
        fileToWrite << int(loadFile.ashLineVector.at(i).storedOffhandWeapons) << ';';

        fileToWrite << loadFile.ashLineVector.at(i).iconID << ';';
        fileToWrite << int(loadFile.ashLineVector.at(i).rank) << ';';
        fileToWrite << int(loadFile.ashLineVector.at(i).sortGroupID) << ';';

        fileToWrite << loadFile.ashLineVector.at(i).spEffectID0 << ';';
        fileToWrite << loadFile.ashLineVector.at(i).spEffectID1 << ';';
        fileToWrite << loadFile.ashLineVector.at(i).spEffectID2 << ';';

        fileToWrite << loadFile.ashLineVector.at(i).itemGetTutorialFlagID << ';';
        fileToWrite << loadFile.ashLineVector.at(i).swortArtParamID << ';';
        fileToWrite << loadFile.ashLineVector.at(i).mountID << ';';
        fileToWrite << loadFile.ashLineVector.at(i).sellValue << ';';
        fileToWrite << loadFile.ashLineVector.at(i).saleValue << ';';
        fileToWrite << loadFile.ashLineVector.at(i).sortID << ';';
        fileToWrite << loadFile.ashLineVector.at(i).achievementID << ';';
        fileToWrite << loadFile.ashLineVector.at(i).achievementSequentialID << ';';
        fileToWrite << int(loadFile.ashLineVector.at(i).rarity) << ';';
        fileToWrite << int(loadFile.ashLineVector.at(i).showDialogCondType) << ';';
        fileToWrite << int(loadFile.ashLineVector.at(i).defaultWeaponAffinity) << ';';

        fileToWrite << loadFile.ashLineVector.at(i).spEffectMsgId0 << ';';
        fileToWrite << loadFile.ashLineVector.at(i).spEffectMsgId1 << ';';
        fileToWrite << loadFile.ashLineVector.at(i).spEffectID_ForAttack0 << ';';
        fileToWrite << loadFile.ashLineVector.at(i).spEffectID_ForAttack1 << ';';
        fileToWrite << loadFile.ashLineVector.at(i).spEffectID_ForAttack2 << ';';

        fileToWrite << loadFile.ashLineVector.at(i).MountWepTextID << ';';
        */

        fileToWrite << loadFile.DecodedLine(i);
        fileToWrite << std::endl;
        fileToWrite.flush();
    }
    fileToWrite.close();

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

int main()
{
    weaponAshFile ashFile;
    ashFile = LoadAshOfWarFile();
    ashFile.EnableAllWeapons();
    WriteAshOfWarFile(ashFile, 0);
}

