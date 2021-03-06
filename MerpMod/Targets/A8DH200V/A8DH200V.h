#define MOD_IDENTIFIER STRI(A8DH200V.MeRpMoD.Switch.Testing.v01.40.d17.1.20.2246)
#define MOD_ECUID 0F05014023
#define MOD_DATE 17.1.20.2246
#include "Switch.h"
#define MOD_CONFIG Switch
#define MOD_BUILD Testing
#define MOD_RELEASE 0
#define ECU_CALIBRATION_ID A8DH200V
#define ECU_IDENTIFIER 4352594006
/////////////////////
// NonSpecific Rom Info and Routines
/////////////////////

#define dCalId (0x00002000)
#define dEcuId (0x000CDD54)
#define dRomHoleStart (0x000E1000)
#define pRamHoleStart (0xFFFF8FE0)
#define sPull2DFloat (0x0000209C)
#define sPull3DFloat (0x00002110)

/////////////////////
// Switch Hacks
/////////////////////

#define pTGVLeftVoltage ((unsigned short*)0xFFFF5C0A)
#define pTGVRightVoltage ((unsigned short*)0xFFFF5C0C)
#define pRearO2Voltage ((float*)0xFFFF5CBC)
#define sShortToFloat (0x2554)
#define hPull2DTipInEnrich (0x30224)
#define tTipInEnrich (0x80B4C)
#define tTipInEnrich2 (0x80B4C)
#define hPull2DCrankingFuel (0x28624)
#define tCrankingFuelA (0x00080790)
#define tCrankingFuelB (0x000807A4)
#define tCrankingFuelC (0x000807B8)
#define tCrankingFuelD (0x000807CC)
#define tCrankingFuelE (0x000807E0)
#define tCrankingFuelF (0x000807F4)
#define hPull3DStartupEnrich1 (0x2919C)
#define tStartupEnrich1Cruise (0x80E60)
#define tStartupEnrich1NonCruise (0x80E44)
#define hPull2DStartupEnrich2 (0x29070)
#define tStartupEnrich2_1A (0x80858)
#define tStartupEnrich2_1B (0x80880)
#define tStartupEnrich2_2A (0x8086C)
#define tStartupEnrich2_2B (0x80894)
#define hPull2DStartupEnrich3 (0x28E94)
#define tStartupEnrich3_1A (0x80808)
#define tStartupEnrich3_1B (0x8081C)
#define tStartupEnrich3_2A (0x80830)
#define tStartupEnrich3_2B (0x80844)
#define hPull2DFrontO2Scaling (0xBE80)
#define tFrontO2Scaling (0x81FD4)

/////////////////////
// Rev Limit Hack
/////////////////////

#define hRevLimDelete (0x0001483C)
#define sRevLimStart (0x00030D10)
#define sRevLimEnd (0x00030D46)
#define pFlagsRevLim ((unsigned char*)0xFFFF71BC)
#define RevLimBitMask (0x80)

/////////////////////
// Speed Density Hack
/////////////////////

#define hMafCalc (0x000081BC)
#define sMafCalc (0x00008160)

/////////////////////
// Injector Hack
/////////////////////

#define dInjectorScaling ((float*)0x000C6A0C)
#define hInjectorScaling (0x00028C70)

/////////////////////
// Cel Hacks
/////////////////////

#define sCelTrigger (0x0007806C)
#define hCelSignal (0x00078184)
#define pCelSignalOem ((unsigned char*)0xFFFF8BA2)

/////////////////////
// Boost Hacks
/////////////////////

#define hPullTargetBoost (0x000170C8)
#define hTableTargetBoost (0x000170DC)
#define tTargetBoost (0x0007F78C)

/////////////////////
// WGDC Hacks
/////////////////////

#define hPullWgdc (0x000174F0)
#define hWgdc (0x000143F4)
#define sWgdc (0x00016BD8)
#define hTableWgdcInitial (0x000174F8)
#define tWgdcInitial (0x0007F6E4)
#define hTableWgdcMax (0x00017534)
#define tWgdcMax (0x0007F71C)

/////////////////////
// Primary Open Loop Fueling Hacks
/////////////////////

#define pPolf4Byte (0xFFFF7028)
#define hPull3DPolf (0x0002DBA8)
#define tPolf (0x80EB4)
#define hPolf (0x00014858)
#define sPolf (0x0002D974)
#define pPolfEnrich (0xFFFF7028)

/////////////////////
// Timing Hacks
/////////////////////

#define hBaseTiming (0x00014914)
#define hTableBaseTiming (0x343E8)
#define tBaseTiming (0x0008154C)
#define pBaseTiming (0xFFFF7354)
#define sBaseTiming (0x0003427A)
#define hPull3DTiming (0x000343E4)
#define pKcaIam (0xFFFF74D4)
#define hFBKCRetardValue (0x368B0)
#define dFBKCRetardValue ((float*)0xC9FBC)
#define hFBKCRetardValueAlternate (0x36890)
#define dFBKCRetardValueAlternate ((float*)0xC9FC0)

/////////////////////
// Spark Cut
/////////////////////


/////////////////////
// Flags-Signals - up to here
/////////////////////

#define pResumeFlags ((unsigned char*)0xFFFF643C)
#define ResumeBitMask ((unsigned char)0x04)
#define pCoastFlags ((unsigned char*)0xFFFF643C)
#define CoastBitMask ((unsigned char)0x02)
#define pBrakeFlags ((unsigned char*)0xFFFF643C)
#define BrakeBitMask ((unsigned char)0x08)
#define pClutchFlags ((unsigned char*)0xFFFF6975)
#define ClutchBitMask ((unsigned char)0x80)
#define pTestModeFlags ((unsigned char*)0xFFFF6970)
#define TestModeBitMask ((unsigned char)0x20)
#define pDefogFlags ((unsigned char*)0xFFFF6973)
#define DefogBitMask ((unsigned char)0x80)

/////////////////////
// NonSpecific Engine params
/////////////////////

#define pFbkc1 ((unsigned char*)0xFFFF6AF0)
#define pFbkc4 ((float*)0xFFFF7490)
#define pIam1 ((unsigned char*)0xFFFF6AF5)
#define pIam4 ((float*)0xFFFF2910)
#define pEngineSpeed ((float*)0xFFFF699C)
#define pVehicleSpeed ((float*)0xFFFF6994)
#define pCoolantTemp ((float*)0xFFFF5CAC)
#define pAtmoPress ((float*)0xFFFF5CD4)
#define pManifoldAbsolutePressure ((float*)0xFFFF6624)
#define pManifoldRelativePressure ((float*)0xFFFF6628)
#define pInjectorPulseWidth ((float*)0xFFFF7218)
#define pInjectorLatency ((float*)0xFFFF722C)
#define pIntakeAirTemp ((float*)0xFFFF5C9C)
#define pMassAirFlow ((float*)0xFFFF5CD0)
#define pMafSensorVoltage ((short*)0xFFFF5BFE)
#define pEngineLoad ((float*)0xFFFF67CC)
#define pReqTorque ((float*)0xFFFF7784)
#define pThrottlePlate ((float*)0xFFFF66C8)
#define pCurrentGear ((unsigned char*)0xFFFF6AA5)
#define pAf1Res ((float*)0xFFFF5F08)

/////////////////////
// OBD Experimental stuff
/////////////////////

#define pObdVinDirect ((unsigned char*)0xFFFF2004)

/////////////////////
// New Definitions
/////////////////////

#define dLoadSmoothingA (0x000C1AF4)
#define dLoadSmoothingB (0x000C1AF8)
#define dLoadSmoothingFinal (0x000C1B04)

/////////////////////
// Memory Reset
/////////////////////

#define sMemoryReset (0x0000FB54)
#define hMemoryReset (0x0000DA70)
#define pMemoryResetLimit (0xFFFFBFBB)
#define hMemoryResetLimit (0x00011EE0)

