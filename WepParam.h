#pragma once
#include <iostream>
#include <string>
#include <vector>

//Bitmasks
#pragma region
const uint8_t WEILD_RIGHTHAND_BIT = 1 << 0; //99
const uint8_t WEILD_LEFTHAND_BIT = 1 << 1; //100
const uint8_t WEILD_BOTHHANDS_BIT = 1 << 2; //101
const uint8_t WEILD_ARROW_BIT = 1 << 3; //102
const uint8_t WEILD_BOLT_BIT = 1 << 4; //103
const uint8_t ALLOW_SHIELDBUFF_BIT = 1 << 5; //104
const uint8_t ALLOW_BUFF_BIT = 1 << 6; //114
const uint8_t ALLOW_REINFORCE_BIT = 1 << 7; //116

const uint8_t ENABLE_PARRY_BIT = 1 << 0; //105
const uint8_t ENABLE_SORCERY_BIT = 1 << 1; //106
const uint8_t ENABLE_PYROMANCY_BIT = 1 << 2; //107
const uint8_t ENABLE_INCANTATIONS_BIT = 1 << 3; //108
const uint8_t ENABLE_VOW_BIT = 1 << 4; //109
const uint8_t ENABLE_DARK_HAND_BIT = 1 << 5; //118
const uint8_t PREVENT_AFFINITY_BIT = 1 << 6; //131

const uint8_t TYPEDISPLAY_NORMAL_BIT = 1 << 0; //110
const uint8_t TYPEDISPLAY_STRIKE_BIT = 1 << 1; //111
const uint8_t TYPEDISPLAY_SLASH_BIT = 1 << 2; //112
const uint8_t TYPEDISPLAY_THRUST_BIT = 1 << 3; //113
const uint8_t IS_GREATBOW_BIT = 1 << 4; //123
const uint8_t IS_DUELWEAPON_BIT = 1 << 5; //163

const uint16_t HUMANITY_CORRECTION_BIT = 1 << 0; //114
const uint16_t BASE_CHANGE_RESET_BIT = 1 << 1; //116
const uint16_t REPAIR_DISABLE_BIT = 1 << 2; //117
const uint16_t SIMPLE_DLC_MODEL_BIT = 1 << 3; //119
const uint16_t IS_LIGHTSOURCE_BIT = 1 << 4; //120
const uint16_t CAN_HIT_GHOST_BIT = 1 << 5; //121
const uint16_t CAN_DEPOSIT_BIT = 1 << 6; //124
const uint16_t CANNOT_DROP_MULTIPLAYER_BIT = 1 << 7; //125
const uint16_t CAN_DISCARD_BIT = 1 << 8; //126
const uint16_t CAN_DROP_BIT = 1 << 9; //127
const uint16_t ACQUISITION_LOG_TYPE_BIT = 1 << 10; //128
const uint16_t ENABLE_THROW_BIT = 1 << 11; //129
const uint16_t TOUGHNESS_PERFORMED_IF_POISE_INITIAL_BIT = 1 << 12; //162
const uint16_t AUTO_EQUIP_BIT = 1 << 13; //164
const uint16_t EMERGENCY_AVOIDANCE_BIT = 1 << 14; //165
const uint16_t HIDDEN_IN_CUTSCENE_BIT = 1 << 15; //166

const uint8_t SHEATHED_RESIDEDNTSFX1_BIT = 1 << 0; //228
const uint8_t SHEATHED_RESIDEDNTSFX2_BIT = 1 << 1; //229
const uint8_t SHEATHED_RESIDEDNTSFX3_BIT = 1 << 2; //230
const uint8_t SHEATHED_RESIDEDNTSFX4_BIT = 1 << 3; //231
const uint8_t WEAPONVFX_PARAM1_BIT = 1 << 4; //232
const uint8_t WEAPONVFX_PARAM2_BIT = 1 << 5; //233
const uint8_t WEAPONVFX_PARAM3_BIT = 1 << 6; //234
const uint8_t WEAPONVFX_PARAM4_BIT = 1 << 7; //235
#pragma endregion

class wepParamLine
{
public:

	int rowID = 0; //0
	std::string rowName = ""; //1

	int32_t behaviourVariation = 0; //3
	int32_t sortID = 0; //4
	uint32_t wanderingEquipID = 0; //5
	float weight = 0.0f; //6
	float weightPercent = 0.0f; //7
	int32_t repairPrice = 0; //8
	int32_t reinforcementPrice = 0; //9
	int32_t sellPrice = 0; //10

	//Correction data entries 11->14 186
	//str, dex, int, fth, arc
	float statCorrections[5] = { 0.0f,0.0f,0.0f,0.0f,0.0f };

	//Guard absorbtion data entries 15->18, 173 259
	//physical, magic, fire lightning, holy, poise
	float mainAbsorbtions[6] = { 0.0f,0.0f,0.0f,0.0f,0.0f,0.0f };

	//Behaviour special effect data entries 19->24
	//speffect1,2,3 passive1,2,3
	int32_t behaviourSpEffects[6] = { -1, -1, -1, -1, -1, -1 };

	int32_t reinforcementMaterialID = -1; //25

	//Origin + data entries 26->41 247->256
	int32_t originWeapon[26] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 , -1 };

	//Damage multiplier data entries 42->45, 171->172
	//[put types here]
	float damageMultiplierPercent[6] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f};

	//maxCorrectionData entries 46->47 191->201
	//0-Sleep, 1-Madness, 2-physical, 3-magic, 4-fire, 5-lightning, 6-holy, 7-poison, 8-rot, 9-bleed, 10-blight, 11-frost, 12-stability
	float maxCorrection[13] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f };

	float poiseDamage = 0.0f; // 48

	uint16_t equipModelID = 0; //49
	uint16_t iconID = 0; //50

	uint16_t durability = 0; //51
	uint16_t maxDurability = 0; //51

	uint16_t throwEscapeDamage = 0; //52
	int16_t parryOccurenceDuration = -1; //53

	//raw damage value entries 54->59, 174
	//0-physical, 1-magic, 2-fire, 3-lightning, 4-stamina, 5-Holy
	uint16_t damageValues[6] = { 0,0,0,0,0,0 };

	int16_t guardAngle = 0; //60

	float poiseDurability = 0.0f; //61

	int16_t guardStability = 0; //62

	int16_t reinforceTypeID = 0; //63

	int16_t achievementID1 = 0; //64
	int16_t achievementID2 = 0; //65

	int16_t criticalMultiplier = 0; //66

	int16_t bowDistancePercent = -1; //67

	uint8_t equipModelCategory = 0; //68
	uint8_t equipModelGender = 0; //69
	uint8_t weaponCatagory = 0; //70
	uint8_t weaponMotionCategory = 0; //71
	uint8_t guardMotionCategory = 0; //72
	uint8_t attackMaterial = 0; //73
	uint16_t defenceSEMaterial1 = 0; //74

	//Correction type data entries 75, 168->170, 175->176 181 239->240
	//0-physical, 1-Magic, 2-Fire, 3-Lightning, 4-Holy, 5-Poison, 6-Bleed, 7-Sleep, 8-Madness
	uint8_t correctionTypes[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0};

	uint8_t specialAttribute = 0; //76
	uint16_t specialMotionCategory = 0; //77

	uint8_t weaponMotionPosition1h = 0; //78
	uint8_t weaponMotionPosition2h = 0; //79

	//weapon stat requirement entries 80->83, 182
	//0-str, 1-dex, 2-int, 3-fth, 4-arc
	uint8_t requirements[5] = { 0, 0, 0, 0, 0};

	uint8_t strengthOverStartValue = 0; //84

	uint8_t baseParryAttack = 0; //85
	uint8_t baseParryDefense = 0; //86
	uint8_t baseGuardRepel = 0; //87
	uint8_t baseAttackRepel = 0; //88

	int8_t guardBypassPercent = 0; //89
	int8_t guardLevel = 0; //90

	//Absorption for subphysical entries 91->93
	//0-Slash, 1-Strike, 2-Thrust
	int8_t subAbsorption[3] = { 0,0,0 };

	//Guard resist data entries 94->97 179->180 183
	//0-Poison, 1-Rot, 2-Bleed, 3-Blight, 4-Sleep, 5-Madness, 6-Frost
	int8_t guardResist[7] = { 0,0,0,0,0,0,0 };

	uint8_t attackAttribute = 0; //98

	//WEILD_RIGHTHAND
	//WEILD_LEFTHAND
	//WEILD_BOTHHANDS
	//WEILD_ARROW
	//WEILD_BOLT
	//ALLOW_SHIELDBUFF
	//ALLOW_BUFF
	//ALLOW_REINFORCE
	uint8_t slotAndBuffByte = 0;

	//ENABLE_PARRY
	//ENABLE_SORCERY
	//ENABLE_PYROMANCY
	//ENABLE_INCANTATIONS
	//ENABLE_VOW
	//ENABLE_DARK_HAND
	//PREVENT_AFFINITY
	uint8_t spellAndParryByte = 0;

	//TYPEDISPLAY_NORMAL
	//TYPEDISPLAY_STRIKE
	//TYPEDISPLAY_SLASH
	//TYPEDISPLAY_THRUST
	//IS_GREATBOW
	//IS_DUELWEAPON
	uint8_t typeDisplayByte = 0;

	//HUMANITY_CORRECTION
	//BASE_CHANGE_RESET
	//REPAIR_DISABLE
	//SIMPLE_DLC_MODEL
	//IS_LIGHTSOURCE
	//CAN_HIT_GHOST
	//CAN_DEPOSIT
	//CANNOT_DROP_MULTIPLAYER
	//CAN_DISCARD
	//CAN_DROP
	//ACQUISITION_LOG_TYPE
	//ENABLE_THROW
	//TOUGHNESS_PERFORMED_IF_POISE_INITIAL
	//AUTO_EQUIP
	//EMERGENCY_AVOIDANCE
	//HIDDEN_IN_CUTSCENE
	uint16_t miscOptionsBytes = 0;

	uint8_t baseChangeCategory = 0; //122

	uint8_t acquisitionDialogueType = 0; //130

	uint16_t defenceSFXMaterial1 = 0; //132

	uint8_t weaponCollidableType0 = 0; //133
	uint8_t weaponCollidableType1 = 0; //134

	uint8_t postureControlIDRight = 0; //135
	uint8_t postureControlIDLeft = 0; //136

	//Trace sfx ID entries 136->157
	//7*sfxID, dummyPolyHead, dummyPolyTail
	int32_t traceSFXIDs[21] =
	{ -1, -1, -1,  -1, -1, -1,  -1, -1, -1,  -1, -1, -1,  -1, -1, -1,  -1, -1, -1,  -1, -1, -1, };

	uint16_t defenceSFXMaterial2 = 0; //158
	uint16_t defenceSEMaterial2 = 0; //159

	int32_t weaponSheathPosition = -1; //160

	float toughnessCorrection = 1.0f; //161

	uint8_t padDummy1 = 0; //167

	uint8_t sortGroupID = 0; //177

	uint8_t attackAttribute2 = 0; //178

	uint8_t autoReplenishType = 0; //184

	int32_t swordArtParamID = 0; //185

	int32_t quiverID = 0; //187

	uint8_t derivationType = 0; //188

	uint8_t enchantmentSFXSize = 0; //189

	int16_t weaponType = 0; //190

	//resident sfx entries 202->209
	//sfx1-4, dummypoly1-4
	int32_t residentSFX[8] = { -1, -1, -1, -1, -1, -1, -1, -1 };

	float staminaConsumptionPercent = 1.0f; //210

	//Damage against player entries 211->218 257->258 263->264
	//0-physical, 1-magic, 2-fire, 3-lightning, 4-holy, 5-poison, 6-blood, 7-frost, 8-Sleep, 9-Madness, 10-Rot, 11-Blight
	float vsPlayerDamagePercent[12] = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f , 1.0f , 1.0f , 1.0f , 1.0f };

	//R2 requirement entries 219->223
	//0-str, 1-dex, 2-int, 3-fth, 4-arc
	int32_t uniqueR2AttackRequirement[5] = { -1, -1, -1, -1, -1 };

	int32_t attackElementCorrectID = 0; //224

	int32_t saleValue = -1; //225

	int8_t reinforcementMenuType = 0; //226

	int8_t maxAmmoHeld = 0; //227

	//SHEATHED_RESIDEDNTSFX1
	//SHEATHED_RESIDEDNTSFX2
	//SHEATHED_RESIDEDNTSFX3
	//SHEATHED_RESIDEDNTSFX4
	//WEAPONVFX_PARAM1
	//WEAPONVFX_PARAM2
	//WEAPONVFX_PARAM3
	//WEAPONVFX_PARAM4
	uint8_t sheathedSFXandVFXParamByte = 0;

	int8_t weaponSeIdOffset = 0; //236

	int32_t affinityPrice = 0; //237

	int16_t levelSyncCorrectionID = -1; //238

	uint8_t rarity = 0; //241

	uint8_t allowAshOfWarChange = 0; //242

	uint16_t weaponHPRegain = 0; //243

	//SpEffect message Id entries 244->246
	int32_t spEffectMessageID[3] = { -1,-1,-1 };

	uint8_t defenceMaterialVariation = 0; //260
	uint8_t specialAttributeVariation = 0; //261

	int16_t stealthAttackMult = 0; //262

	uint8_t padDummy2 = 0; //265

	//Bit functions
	#pragma region
	void EnableSlotOrBuffBit(uint8_t bit)
	{
		slotAndBuffByte = slotAndBuffByte | bit;
	}

	bool QuerySlotOrBuffBit(uint8_t bit)
	{
		if (slotAndBuffByte & bit)
			return true;
		else
			return false;
	}

	void DisableSlotOrBuffBit(uint8_t bit)
	{
		if (QuerySlotOrBuffBit(bit))
			slotAndBuffByte -= bit;
		//else
		//     it isn't there? Do nothing
	}

	void EnableSpellOrParryBit(uint8_t bit)
	{
		spellAndParryByte = spellAndParryByte | bit;
	}

	bool QuerySpellOrParryBit(uint8_t bit)
	{
		if (spellAndParryByte & bit)
			return true;
		else
			return false;
	}

	void DisableSpellOrParryBit(uint8_t bit)
	{
		if (QuerySpellOrParryBit(bit))
			spellAndParryByte -= bit;
		//else
		//     it isn't there? Do nothing
	}

	void EnableTypeBit(uint8_t bit)
	{
		typeDisplayByte = typeDisplayByte | bit;
	}

	bool QueryTypeBit(uint8_t bit)
	{
		if (typeDisplayByte & bit)
			return true;
		else
			return false;
	}

	void DisableTypeBit(uint8_t bit)
	{
		if (QueryTypeBit(bit))
			typeDisplayByte -= bit;
		//else
		//     it isn't there? Do nothing
	}

	void EnableMiscOptionBit(uint16_t bit)
	{
		miscOptionsBytes = miscOptionsBytes | bit;
	}

	bool QueryMiscOptionBit(uint16_t bit)
	{
		if (miscOptionsBytes & bit)
			return true;
		else
			return false;
	}

	void DisableMiscOptionBit(uint16_t bit)
	{
		if (QueryMiscOptionBit(bit))
			miscOptionsBytes -= bit;
		//else
		//     it isn't there? Do nothing
	}

	void EnableFXBit(uint8_t bit)
	{
		sheathedSFXandVFXParamByte = sheathedSFXandVFXParamByte | bit;
	}

	bool QueryFXBit(uint8_t bit)
	{
		if (sheathedSFXandVFXParamByte & bit)
			return true;
		else
			return false;
	}

	void DisableFXBit(uint8_t bit)
	{
		if (QueryFXBit(bit))
			sheathedSFXandVFXParamByte -= bit;
		//else
		//     it isn't there? Do nothing
	}
	#pragma endregion


};

class WepParamFile
{
public:
	std::vector<wepParamLine> wepParamLineVector;

	void CreateFilespace()
	{
		wepParamLineVector.reserve(5572);
	}
	void CreateFilespace(int reserveSpace)
	{
		wepParamLineVector.reserve(reserveSpace);
	}


	std::string infoLine = "";
	void LoadFileLineFromCSV(std::vector<std::string> stringVector)
	{
		if (stringVector[0] == "Row ID")
		{
			for (int i = 0; i < 264; i++)
			{
				infoLine.append(stringVector[i]);
				if (i != 263)
				{
					infoLine.append(";");
				}
			}
		}
		else
		{
			wepParamLineVector.push_back(wepParamLine());

			wepParamLineVector.back().rowID = stoi(stringVector[0]);
			wepParamLineVector.back().rowName = stringVector[1];

			//whoops I forgot to add a bit for network test

			wepParamLineVector.back().behaviourVariation = stoi(stringVector[3]);
			wepParamLineVector.back().sortID = stoi(stringVector[4]);
			wepParamLineVector.back().wanderingEquipID = stoi(stringVector[5]);
			wepParamLineVector.back().weight = stof(stringVector[6]);
			wepParamLineVector.back().weightPercent = stof(stringVector[7]);
			wepParamLineVector.back().repairPrice = stoi(stringVector[8]);
			wepParamLineVector.back().reinforcementPrice = stoi(stringVector[9]);
			wepParamLineVector.back().sellPrice = stoi(stringVector[10]);

			wepParamLineVector.back().statCorrections[0] = stof(stringVector[11]);
			wepParamLineVector.back().statCorrections[1] = stof(stringVector[12]);
			wepParamLineVector.back().statCorrections[2] = stof(stringVector[13]);
			wepParamLineVector.back().statCorrections[3] = stof(stringVector[14]);

			wepParamLineVector.back().mainAbsorbtions[0] = stof(stringVector[15]);
			wepParamLineVector.back().mainAbsorbtions[1] = stof(stringVector[16]);
			wepParamLineVector.back().mainAbsorbtions[2] = stof(stringVector[17]);
			wepParamLineVector.back().mainAbsorbtions[3] = stof(stringVector[18]);

			wepParamLineVector.back().behaviourSpEffects[0] = stoi(stringVector[19]);
			wepParamLineVector.back().behaviourSpEffects[1] = stoi(stringVector[20]);
			wepParamLineVector.back().behaviourSpEffects[2] = stoi(stringVector[21]);
			wepParamLineVector.back().behaviourSpEffects[3] = stoi(stringVector[22]);
			wepParamLineVector.back().behaviourSpEffects[4] = stoi(stringVector[23]);
			wepParamLineVector.back().behaviourSpEffects[5] = stoi(stringVector[24]);

			wepParamLineVector.back().reinforcementMaterialID = stoi(stringVector[25]);

			wepParamLineVector.back().originWeapon[0] = stoi(stringVector[26]);
			wepParamLineVector.back().originWeapon[1] = stoi(stringVector[27]);
			wepParamLineVector.back().originWeapon[2] = stoi(stringVector[28]);
			wepParamLineVector.back().originWeapon[3] = stoi(stringVector[29]);
			wepParamLineVector.back().originWeapon[4] = stoi(stringVector[30]);
			wepParamLineVector.back().originWeapon[5] = stoi(stringVector[31]);
			wepParamLineVector.back().originWeapon[6] = stoi(stringVector[32]);
			wepParamLineVector.back().originWeapon[7] = stoi(stringVector[33]);
			wepParamLineVector.back().originWeapon[8] = stoi(stringVector[34]);
			wepParamLineVector.back().originWeapon[9] = stoi(stringVector[35]);
			wepParamLineVector.back().originWeapon[10] = stoi(stringVector[36]);
			wepParamLineVector.back().originWeapon[11] = stoi(stringVector[37]);
			wepParamLineVector.back().originWeapon[12] = stoi(stringVector[38]);
			wepParamLineVector.back().originWeapon[13] = stoi(stringVector[39]);
			wepParamLineVector.back().originWeapon[14] = stoi(stringVector[40]);
			wepParamLineVector.back().originWeapon[15] = stoi(stringVector[41]);

			wepParamLineVector.back().damageMultiplierPercent[0] = stof(stringVector[42]);
			wepParamLineVector.back().damageMultiplierPercent[1] = stof(stringVector[43]);
			wepParamLineVector.back().damageMultiplierPercent[2] = stof(stringVector[44]);
			wepParamLineVector.back().damageMultiplierPercent[3] = stof(stringVector[45]);

			wepParamLineVector.back().maxCorrection[0] = stof(stringVector[46]);
			wepParamLineVector.back().maxCorrection[1] = stof(stringVector[47]);

			wepParamLineVector.back().poiseDamage = stof(stringVector[48]);

			wepParamLineVector.back().equipModelID = stoi(stringVector[49]);
			wepParamLineVector.back().iconID = stoi(stringVector[50]);

			wepParamLineVector.back().durability = stoi(stringVector[51]);
			wepParamLineVector.back().maxDurability = stoi(stringVector[52]);

			wepParamLineVector.back().throwEscapeDamage = stoi(stringVector[53]);
			wepParamLineVector.back().parryOccurenceDuration = stoi(stringVector[54]);

			wepParamLineVector.back().maxCorrection[0] = stof(stringVector[55]);
			wepParamLineVector.back().maxCorrection[1] = stof(stringVector[56]);
			wepParamLineVector.back().maxCorrection[2] = stof(stringVector[57]);
			wepParamLineVector.back().maxCorrection[3] = stof(stringVector[58]);
			wepParamLineVector.back().maxCorrection[4] = stof(stringVector[59]);

			wepParamLineVector.back().guardAngle = stoi(stringVector[60]);
			wepParamLineVector.back().poiseDurability = stof(stringVector[61]);

			wepParamLineVector.back().guardStability = stoi(stringVector[62]);
			wepParamLineVector.back().reinforceTypeID = stoi(stringVector[63]);

			wepParamLineVector.back().achievementID1 = stoi(stringVector[64]);
			wepParamLineVector.back().achievementID2 = stoi(stringVector[65]);

			wepParamLineVector.back().criticalMultiplier = stoi(stringVector[66]);

			wepParamLineVector.back().bowDistancePercent = stoi(stringVector[67]);

			wepParamLineVector.back().equipModelCategory = stoi(stringVector[68]);
			wepParamLineVector.back().equipModelGender = stoi(stringVector[69]);
			wepParamLineVector.back().weaponCatagory = stoi(stringVector[70]);
			wepParamLineVector.back().weaponMotionCategory = stoi(stringVector[71]);
			wepParamLineVector.back().guardMotionCategory = stoi(stringVector[72]);
			wepParamLineVector.back().attackMaterial = stoi(stringVector[73]);
			wepParamLineVector.back().defenceSEMaterial1 = stoi(stringVector[74]);

			wepParamLineVector.back().correctionTypes[0] = stoi(stringVector[75]);

			wepParamLineVector.back().specialAttribute = stoi(stringVector[76]);
			wepParamLineVector.back().specialMotionCategory = stoi(stringVector[77]);

			wepParamLineVector.back().weaponMotionPosition1h = stoi(stringVector[78]);
			wepParamLineVector.back().weaponMotionPosition2h = stoi(stringVector[79]);

			wepParamLineVector.back().requirements[0] = stoi(stringVector[80]);
			wepParamLineVector.back().requirements[1] = stoi(stringVector[81]);
			wepParamLineVector.back().requirements[2] = stoi(stringVector[82]);
			wepParamLineVector.back().requirements[3] = stoi(stringVector[83]);

			wepParamLineVector.back().strengthOverStartValue = stoi(stringVector[84]);

			wepParamLineVector.back().baseParryAttack = stoi(stringVector[85]);
			wepParamLineVector.back().baseParryDefense = stoi(stringVector[86]);
			wepParamLineVector.back().baseGuardRepel = stoi(stringVector[87]);
			wepParamLineVector.back().baseAttackRepel = stoi(stringVector[88]);

			wepParamLineVector.back().guardBypassPercent = stoi(stringVector[89]);
			wepParamLineVector.back().guardLevel = stoi(stringVector[90]);

			wepParamLineVector.back().subAbsorption[0] = stoi(stringVector[91]);
			wepParamLineVector.back().subAbsorption[1] = stoi(stringVector[92]);
			wepParamLineVector.back().subAbsorption[2] = stoi(stringVector[93]);

			wepParamLineVector.back().guardResist[0] = stoi(stringVector[94]);
			wepParamLineVector.back().guardResist[1] = stoi(stringVector[95]);
			wepParamLineVector.back().guardResist[2] = stoi(stringVector[96]);
			wepParamLineVector.back().guardResist[3] = stoi(stringVector[97]);

			wepParamLineVector.back().attackAttribute = stoi(stringVector[98]);

			if (stoi(stringVector[99])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | WEILD_RIGHTHAND_BIT;
			if (stoi(stringVector[100])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | WEILD_LEFTHAND_BIT;
			if (stoi(stringVector[101])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | WEILD_BOTHHANDS_BIT;
			if (stoi(stringVector[102])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | WEILD_ARROW_BIT;
			if (stoi(stringVector[103])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | WEILD_BOLT_BIT;
			if (stoi(stringVector[104])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | ALLOW_SHIELDBUFF_BIT;

			if (stoi(stringVector[105])) wepParamLineVector.back().spellAndParryByte = wepParamLineVector.back().spellAndParryByte | ENABLE_PARRY_BIT;
			if (stoi(stringVector[106])) wepParamLineVector.back().spellAndParryByte = wepParamLineVector.back().spellAndParryByte | ENABLE_SORCERY_BIT;
			if (stoi(stringVector[107])) wepParamLineVector.back().spellAndParryByte = wepParamLineVector.back().spellAndParryByte | ENABLE_PYROMANCY_BIT;
			if (stoi(stringVector[108])) wepParamLineVector.back().spellAndParryByte = wepParamLineVector.back().spellAndParryByte | ENABLE_INCANTATIONS_BIT;
			if (stoi(stringVector[109])) wepParamLineVector.back().spellAndParryByte = wepParamLineVector.back().spellAndParryByte | ENABLE_VOW_BIT;

			if (stoi(stringVector[110])) wepParamLineVector.back().typeDisplayByte = wepParamLineVector.back().typeDisplayByte | TYPEDISPLAY_NORMAL_BIT;
			if (stoi(stringVector[111])) wepParamLineVector.back().typeDisplayByte = wepParamLineVector.back().typeDisplayByte | TYPEDISPLAY_STRIKE_BIT;
			if (stoi(stringVector[112])) wepParamLineVector.back().typeDisplayByte = wepParamLineVector.back().typeDisplayByte | TYPEDISPLAY_SLASH_BIT;
			if (stoi(stringVector[113])) wepParamLineVector.back().typeDisplayByte = wepParamLineVector.back().typeDisplayByte | TYPEDISPLAY_THRUST_BIT;

			if (stoi(stringVector[114])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | ALLOW_BUFF_BIT;

			if (stoi(stringVector[115])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | HUMANITY_CORRECTION_BIT;

			if (stoi(stringVector[115])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | ALLOW_REINFORCE_BIT;

			if (stoi(stringVector[116])) wepParamLineVector.back().slotAndBuffByte = wepParamLineVector.back().slotAndBuffByte | ALLOW_BUFF_BIT;

			if (stoi(stringVector[117])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | BASE_CHANGE_RESET_BIT;
			if (stoi(stringVector[118])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | REPAIR_DISABLE_BIT;
			if (stoi(stringVector[119])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | ENABLE_DARK_HAND_BIT;
			if (stoi(stringVector[120])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | SIMPLE_DLC_MODEL_BIT;
			if (stoi(stringVector[121])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | IS_LIGHTSOURCE_BIT;
			if (stoi(stringVector[122])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | CAN_HIT_GHOST_BIT;

			wepParamLineVector.back().baseChangeCategory = stoi(stringVector[123]);

			if (stoi(stringVector[124])) wepParamLineVector.back().typeDisplayByte = wepParamLineVector.back().typeDisplayByte | IS_GREATBOW_BIT;

			if (stoi(stringVector[125])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | CAN_DEPOSIT_BIT;
			if (stoi(stringVector[126])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | CANNOT_DROP_MULTIPLAYER_BIT;
			if (stoi(stringVector[127])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | CAN_DISCARD_BIT;
			if (stoi(stringVector[128])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | CAN_DROP_BIT;
			if (stoi(stringVector[129])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | ACQUISITION_LOG_TYPE_BIT;
			if (stoi(stringVector[130])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | ENABLE_THROW_BIT;
			
			wepParamLineVector.back().acquisitionDialogueType = stoi(stringVector[131]);

			if (stoi(stringVector[132])) wepParamLineVector.back().spellAndParryByte = wepParamLineVector.back().spellAndParryByte | PREVENT_AFFINITY_BIT;

			wepParamLineVector.back().defenceSFXMaterial1 = stoi(stringVector[133]);
			wepParamLineVector.back().weaponCollidableType0 = stoi(stringVector[134]);
			wepParamLineVector.back().weaponCollidableType1 = stoi(stringVector[135]);

			wepParamLineVector.back().postureControlIDRight = stoi(stringVector[136]);
			wepParamLineVector.back().postureControlIDLeft = stoi(stringVector[137]);

			wepParamLineVector.back().traceSFXIDs[0] = stoi(stringVector[138]);
			wepParamLineVector.back().traceSFXIDs[1] = stoi(stringVector[138]);
			wepParamLineVector.back().traceSFXIDs[2] = stoi(stringVector[140]);
			wepParamLineVector.back().traceSFXIDs[3] = stoi(stringVector[141]);
			wepParamLineVector.back().traceSFXIDs[4] = stoi(stringVector[142]);
			wepParamLineVector.back().traceSFXIDs[5] = stoi(stringVector[143]);
			wepParamLineVector.back().traceSFXIDs[6] = stoi(stringVector[144]);
			wepParamLineVector.back().traceSFXIDs[7] = stoi(stringVector[145]);
			wepParamLineVector.back().traceSFXIDs[8] = stoi(stringVector[146]);
			wepParamLineVector.back().traceSFXIDs[9] = stoi(stringVector[147]);
			wepParamLineVector.back().traceSFXIDs[10] = stoi(stringVector[148]);
			wepParamLineVector.back().traceSFXIDs[11] = stoi(stringVector[149]);
			wepParamLineVector.back().traceSFXIDs[12] = stoi(stringVector[150]);
			wepParamLineVector.back().traceSFXIDs[13] = stoi(stringVector[151]);
			wepParamLineVector.back().traceSFXIDs[14] = stoi(stringVector[152]);
			wepParamLineVector.back().traceSFXIDs[15] = stoi(stringVector[153]);
			wepParamLineVector.back().traceSFXIDs[16] = stoi(stringVector[154]);
			wepParamLineVector.back().traceSFXIDs[17] = stoi(stringVector[155]);
			wepParamLineVector.back().traceSFXIDs[18] = stoi(stringVector[156]);
			wepParamLineVector.back().traceSFXIDs[19] = stoi(stringVector[157]);
			wepParamLineVector.back().traceSFXIDs[20] = stoi(stringVector[158]);

			wepParamLineVector.back().defenceSFXMaterial2 = stoi(stringVector[159]);
			wepParamLineVector.back().defenceSEMaterial2 = stoi(stringVector[160]);

			wepParamLineVector.back().weaponSheathPosition = stoi(stringVector[161]);
			wepParamLineVector.back().toughnessCorrection = stof(stringVector[162]);

			if (stoi(stringVector[163])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | TOUGHNESS_PERFORMED_IF_POISE_INITIAL_BIT;

			if (stoi(stringVector[164])) wepParamLineVector.back().typeDisplayByte = wepParamLineVector.back().typeDisplayByte | IS_DUELWEAPON_BIT;

			if (stoi(stringVector[165])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | AUTO_EQUIP_BIT;
			if (stoi(stringVector[166])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | EMERGENCY_AVOIDANCE_BIT;
			if (stoi(stringVector[167])) wepParamLineVector.back().miscOptionsBytes = wepParamLineVector.back().miscOptionsBytes | HIDDEN_IN_CUTSCENE_BIT;

			wepParamLineVector.back().padDummy1 = stoi(stringVector[168]);

			wepParamLineVector.back().correctionTypes[1] = stoi(stringVector[169]);
			wepParamLineVector.back().correctionTypes[2] = stoi(stringVector[170]);
			wepParamLineVector.back().correctionTypes[3] = stoi(stringVector[171]);

			wepParamLineVector.back().damageMultiplierPercent[4] = stof(stringVector[172]);
			wepParamLineVector.back().damageMultiplierPercent[5] = stof(stringVector[173]);

			wepParamLineVector.back().mainAbsorbtions[4] = stof(stringVector[174]);
			wepParamLineVector.back().damageValues[4] = stoi(stringVector[175]);
			wepParamLineVector.back().correctionTypes[4] = stoi(stringVector[176]);
			wepParamLineVector.back().correctionTypes[5] = stoi(stringVector[177]);

			wepParamLineVector.back().sortGroupID = stoi(stringVector[178]);

			wepParamLineVector.back().attackAttribute2 = stoi(stringVector[179]);

			wepParamLineVector.back().guardResist[4] = stoi(stringVector[180]);
			wepParamLineVector.back().guardResist[5] = stoi(stringVector[181]);

			wepParamLineVector.back().correctionTypes[6] = stoi(stringVector[182]);

			wepParamLineVector.back().requirements[4] = stoi(stringVector[183]);

			wepParamLineVector.back().guardResist[6] = stoi(stringVector[184]);

			wepParamLineVector.back().autoReplenishType = stoi(stringVector[185]);

			wepParamLineVector.back().swordArtParamID = stoi(stringVector[186]);

			wepParamLineVector.back().statCorrections[4] = stof(stringVector[187]);

			wepParamLineVector.back().quiverID = stoi(stringVector[188]);

			wepParamLineVector.back().derivationType = stoi(stringVector[189]);

			wepParamLineVector.back().enchantmentSFXSize = stoi(stringVector[190]);

			wepParamLineVector.back().weaponType = stoi(stringVector[191]);

			wepParamLineVector.back().maxCorrection[2] = stof(stringVector[192]);
			wepParamLineVector.back().maxCorrection[3] = stof(stringVector[193]);
			wepParamLineVector.back().maxCorrection[4] = stof(stringVector[194]);
			wepParamLineVector.back().maxCorrection[5] = stof(stringVector[195]);
			wepParamLineVector.back().maxCorrection[6] = stof(stringVector[196]);
			wepParamLineVector.back().maxCorrection[7] = stof(stringVector[197]);
			wepParamLineVector.back().maxCorrection[8] = stof(stringVector[198]);
			wepParamLineVector.back().maxCorrection[9] = stof(stringVector[199]);
			wepParamLineVector.back().maxCorrection[10] = stof(stringVector[200]);
			wepParamLineVector.back().maxCorrection[11] = stof(stringVector[201]);
			wepParamLineVector.back().maxCorrection[12] = stof(stringVector[202]);

			wepParamLineVector.back().residentSFX[0] = stoi(stringVector[203]);
			wepParamLineVector.back().residentSFX[1] = stoi(stringVector[204]);
			wepParamLineVector.back().residentSFX[2] = stoi(stringVector[205]);
			wepParamLineVector.back().residentSFX[3] = stoi(stringVector[206]);
			wepParamLineVector.back().residentSFX[4] = stoi(stringVector[207]);
			wepParamLineVector.back().residentSFX[5] = stoi(stringVector[208]);
			wepParamLineVector.back().residentSFX[6] = stoi(stringVector[209]);
			wepParamLineVector.back().residentSFX[7] = stoi(stringVector[210]);

			wepParamLineVector.back().staminaConsumptionPercent = stof(stringVector[211]);

			wepParamLineVector.back().vsPlayerDamagePercent[0] = stof(stringVector[212]);
			wepParamLineVector.back().vsPlayerDamagePercent[1] = stof(stringVector[213]);
			wepParamLineVector.back().vsPlayerDamagePercent[2] = stof(stringVector[214]);
			wepParamLineVector.back().vsPlayerDamagePercent[3] = stof(stringVector[215]);
			wepParamLineVector.back().vsPlayerDamagePercent[4] = stof(stringVector[216]);
			wepParamLineVector.back().vsPlayerDamagePercent[5] = stof(stringVector[217]);
			wepParamLineVector.back().vsPlayerDamagePercent[6] = stof(stringVector[218]);
			wepParamLineVector.back().vsPlayerDamagePercent[7] = stof(stringVector[219]);

			wepParamLineVector.back().uniqueR2AttackRequirement[0] = stoi(stringVector[220]);
			wepParamLineVector.back().uniqueR2AttackRequirement[1] = stoi(stringVector[221]);
			wepParamLineVector.back().uniqueR2AttackRequirement[2] = stoi(stringVector[222]);
			wepParamLineVector.back().uniqueR2AttackRequirement[3] = stoi(stringVector[223]);
			wepParamLineVector.back().uniqueR2AttackRequirement[4] = stoi(stringVector[224]);

			wepParamLineVector.back().attackElementCorrectID = stoi(stringVector[225]);

			wepParamLineVector.back().saleValue = stoi(stringVector[226]);

			wepParamLineVector.back().reinforcementMenuType = stoi(stringVector[227]);

			wepParamLineVector.back().maxAmmoHeld = stoi(stringVector[228]);

			if (stoi(stringVector[228])) wepParamLineVector.back().sheathedSFXandVFXParamByte = wepParamLineVector.back().sheathedSFXandVFXParamByte | SHEATHED_RESIDEDNTSFX1_BIT;
			if (stoi(stringVector[229])) wepParamLineVector.back().sheathedSFXandVFXParamByte = wepParamLineVector.back().sheathedSFXandVFXParamByte | SHEATHED_RESIDEDNTSFX2_BIT;
			if (stoi(stringVector[230])) wepParamLineVector.back().sheathedSFXandVFXParamByte = wepParamLineVector.back().sheathedSFXandVFXParamByte | SHEATHED_RESIDEDNTSFX3_BIT;
			if (stoi(stringVector[231])) wepParamLineVector.back().sheathedSFXandVFXParamByte = wepParamLineVector.back().sheathedSFXandVFXParamByte | SHEATHED_RESIDEDNTSFX4_BIT;
			if (stoi(stringVector[232])) wepParamLineVector.back().sheathedSFXandVFXParamByte = wepParamLineVector.back().sheathedSFXandVFXParamByte | WEAPONVFX_PARAM1_BIT;
			if (stoi(stringVector[233])) wepParamLineVector.back().sheathedSFXandVFXParamByte = wepParamLineVector.back().sheathedSFXandVFXParamByte | WEAPONVFX_PARAM2_BIT;
			if (stoi(stringVector[234])) wepParamLineVector.back().sheathedSFXandVFXParamByte = wepParamLineVector.back().sheathedSFXandVFXParamByte | WEAPONVFX_PARAM3_BIT;
			if (stoi(stringVector[235])) wepParamLineVector.back().sheathedSFXandVFXParamByte = wepParamLineVector.back().sheathedSFXandVFXParamByte | WEAPONVFX_PARAM4_BIT;

			wepParamLineVector.back().weaponSeIdOffset = stoi(stringVector[236]);

			wepParamLineVector.back().affinityPrice = stoi(stringVector[237]);

			wepParamLineVector.back().levelSyncCorrectionID = stoi(stringVector[238]);

			wepParamLineVector.back().correctionTypes[7] = stoi(stringVector[239]);
			wepParamLineVector.back().correctionTypes[8] = stoi(stringVector[240]);

			wepParamLineVector.back().rarity = stoi(stringVector[241]);

			wepParamLineVector.back().allowAshOfWarChange = stoi(stringVector[242]);

			wepParamLineVector.back().weaponHPRegain = stoi(stringVector[241]);

			wepParamLineVector.back().spEffectMessageID[0] = stoi(stringVector[242]);
			wepParamLineVector.back().spEffectMessageID[1] = stoi(stringVector[243]);
			wepParamLineVector.back().spEffectMessageID[2] = stoi(stringVector[244]);

			wepParamLineVector.back().originWeapon[16] = stoi(stringVector[245]);
			wepParamLineVector.back().originWeapon[17] = stoi(stringVector[246]);
			wepParamLineVector.back().originWeapon[18] = stoi(stringVector[247]);
			wepParamLineVector.back().originWeapon[19] = stoi(stringVector[248]);
			wepParamLineVector.back().originWeapon[20] = stoi(stringVector[249]);
			wepParamLineVector.back().originWeapon[21] = stoi(stringVector[250]);
			wepParamLineVector.back().originWeapon[22] = stoi(stringVector[251]);
			wepParamLineVector.back().originWeapon[23] = stoi(stringVector[252]);
			wepParamLineVector.back().originWeapon[24] = stoi(stringVector[253]);
			wepParamLineVector.back().originWeapon[25] = stoi(stringVector[254]);

			wepParamLineVector.back().vsPlayerDamagePercent[8] = stof(stringVector[255]);
			wepParamLineVector.back().vsPlayerDamagePercent[9] = stof(stringVector[256]);

			wepParamLineVector.back().mainAbsorbtions[5] = stoi(stringVector[257]);

			wepParamLineVector.back().defenceMaterialVariation = stoi(stringVector[258]);
			wepParamLineVector.back().specialAttribute = stoi(stringVector[259]);

			wepParamLineVector.back().stealthAttackMult = stoi(stringVector[260]);

			wepParamLineVector.back().vsPlayerDamagePercent[10] = stof(stringVector[261]);
			wepParamLineVector.back().vsPlayerDamagePercent[11] = stof(stringVector[262]);

			wepParamLineVector.back().padDummy2 = stoi(stringVector[263]);
		}
	}
};

WepParamFile LoadWepParamFile();
WepParamFile ApplyDefaultwepParamNames(WepParamFile file);