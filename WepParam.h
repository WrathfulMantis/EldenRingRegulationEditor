#pragma once
#include <iostream>
#include <string>

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
	uint16_t defenceSeMaterial = 0; //74

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

	uint16_t defenceSFXMaterial0 = 0; //132

	uint8_t weaponCollidableType0 = 0; //133
	uint8_t weaponCollidableType1 = 0; //134

	uint8_t postureControlIDRight = 0; //135
	uint8_t postureControlIDLeft = 0; //136

	//Trace sfx ID entries 136->157
	//7*sfxID, dummyPolyHead, dummyPolyTail
	int32_t traceSFXIDs[21] =
	{ -1, -1, -1,  -1, -1, -1,  -1, -1, -1,  -1, -1, -1,  -1, -1, -1,  -1, -1, -1,  -1, -1, -1, };

	uint16_t defenceSFXMaterial1 = 0; //158
	uint16_t defenceSEMaterial = 0; //159

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
	uint8_t sheathedSFXandVFXParam = 0;

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
};