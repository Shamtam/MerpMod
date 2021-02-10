/*
	Copyright (C) 2012-2013 Merrill A. Myers III merrillamyersiii@gmail.com
	
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

#include "EcuHacks.h"

#if SWITCH_HACKS && INJECTOR_HACKS

/*
float INJECTOR_SCALING_ROWS[11] FUELDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};

short INJECTOR_SCALING_DATA[11] FUELDATA =
{20000,20100,20200,20300,20400,20500,20600,20700,20800,20900,21000};//TODO: document the native units here

TwoDTable InjectorScalingTable  FUELDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,
	.columnHeaderArray = INJECTOR_SCALING_ROWS,
	.tableCells = INJECTOR_SCALING_DATA,
	.multiplier = 0.824f,	//todo unit test these
	.offset = 0.0 };
//! 27000/32767  (0-27000.00 range, 16bit precision)
*/

float INJECTOR_SCALING_MULTIPLIER_ROWS[11] FUELDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1.0};

short INJECTOR_SCALING_MULTIPLIER_DATA[11] FUELDATA =
{6554,6357,6160,5964,5767,5570,5374,5177,4981,4784,4587};

TwoDTable InjectorScalingMultiplierTable  FUELDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,
	.columnHeaderArray = INJECTOR_SCALING_MULTIPLIER_ROWS,
	.tableCells = INJECTOR_SCALING_MULTIPLIER_DATA,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

#endif

#if POLF_HACKS

unsigned char DefaultPolfHackEnabled FUELDATA = HackDisabled;
unsigned char DefaultFuelingLookupMAPLoad FUELDATA = LoadLookup;
unsigned char DefaultLCFuelMode FUELDATA = LCFuelModeDisabled;
float DefaultLCFuelLock FUELDATA = 0.35f;
float DefaultLCFuelEnrichMultiplier FUELDATA = 1.0f;

#if SWITCH_HACKS
TableGroup FuelTableGroup FUELDATA = {
	{&FuelTable1i,
	&FuelTable1s,
	&FuelTable1ss},
	{&FuelTable2i,
	&FuelTable2s,
	&FuelTable2ss}
};
#else
TableGroup FuelTableGroup FUELDATA = {
	{&FuelTable1i,
	&FuelTable1i,
	&FuelTable1i},
	{&FuelTable2i,
	&FuelTable2i,
	&FuelTable2i}
};
#endif



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Dual Front O2 Scaling Tables
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#if DUAL_FRONTO2_HACKS

float FRONT_OXYGEN_SENSOR_COLS[13] FUELDATA = 
{-1.299999952316284,-0.8699999451637268,-0.4699999988079071,-0.1399999856948853,0,
0.09999999403953552,0.239999994635582,0.3899999856948853,0.5299999713897705,
0.6399999856948853,0.7399999499320984,0.7399999499320984,0.7399999499320984};


float FRONT_OXYGEN_SENSOR_1_DATA[13] FUELDATA = 
{0.7586,0.82758617,0.89655167,0.96551722,1.0,1.0344827,1.1034483,1.1724137,
1.2413793,1.3103448,1.3793103,1.3793103,1.3793103};


TwoDTable FrontOxygenSensorScaling1 FUELDATA = {
	.columnCount = 13,
	.tableType = FloatTable2D,
	.columnHeaderArray = FRONT_OXYGEN_SENSOR_COLS,
	.tableCells = FRONT_OXYGEN_SENSOR_1_DATA,
	.multiplier = 1.0f,
	.offset = 0.0f};


float FRONT_OXYGEN_SENSOR_2_DATA[13] FUELDATA = 
{0.7586,0.82758617,0.89655167,0.96551722,1.0,1.0344827,1.1034483,1.1724137,
1.2413793,1.3103448,1.3793103,1.3793103,1.3793103};


TwoDTable FrontOxygenSensorScaling2 FUELDATA = {
	.columnCount = 13,
	.tableType = FloatTable2D,
	.columnHeaderArray = FRONT_OXYGEN_SENSOR_COLS,
	.tableCells = FRONT_OXYGEN_SENSOR_2_DATA,
	.multiplier = 1,
	.offset = 0.0f};

#endif


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Tip-in Enrichment Multiplier Table
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

float TipInEnrichMultiplierAxis[18] SWITCHDATA =
{0,0.9799999594688416,1.949999928474426,3.909999847412109,5.859999656677246,
7.809999942779541,9.769999504089355,11.69999980926514,13.69999980926514,
15.59999942779541,17.59999847412109,19.5,21.5,23.39999961853027,
25.39999961853027,27.29999923706055,29.29999923706055,31.29999923706055};

float TipInEnrichMultiplierBlendAxis[11] SWITCHDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

short TipInEnrichMultiplierData[198] SWITCHDATA =
{6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554
};

ThreeDTable TipInEnrichMultiplier SWITCHDATA = {
	.columnCount = 11,
	.rowCount = 18,
	.tableType = UInt16Table3D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = TipInEnrichMultiplierBlendAxis,
	.rowHeaderArray = TipInEnrichMultiplierAxis,
	.tableCells = TipInEnrichMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Cranking Fuel Multiplier Table
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

float CrankingFuelMultiplierAxis[16] SWITCHDATA = 
{-40,-22,-4,14,32,50,68,86,104,122,140,158,176,194,212,230};

float CrankingFuelMultiplierBlendAxis[11] SWITCHDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

short CrankingFuelMultiplierData[176] SWITCHDATA = 
{6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554
};


ThreeDTable CrankingFuelMultiplier SWITCHDATA = {
	.columnCount = 11,
	.rowCount = 16,
	.tableType = UInt16Table3D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = CrankingFuelMultiplierBlendAxis,
	.rowHeaderArray = CrankingFuelMultiplierAxis,
	.tableCells = CrankingFuelMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Startup Enrichment Multiplier Table
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

float StartupEnrichMultiplierECTAxis[16] SWITCHDATA = 
{-40,-22,-4,14,32,50,68,86,104,122,140,158,176,194,212,230};

float StartupEnrichMultiplierBlendAxis[11] SWITCHDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

short StartupEnrichMultiplierData[176] SWITCHDATA = 
{6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,
6554,6554,6554,6554,6554,6554,6554,6554,6554,6554,6554
};


ThreeDTable StartupEnrichMultiplier SWITCHDATA = {
	.columnCount = 11,
	.rowCount = 16,
	.tableType = UInt16Table3D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = StartupEnrichMultiplierBlendAxis,
	.rowHeaderArray = StartupEnrichMultiplierECTAxis,
	.tableCells = StartupEnrichMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)



//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Launch Control Fuel Retard Table
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

float LCFR_COLS[5] FUELDATA = 
{0,2,4,6,8};

float LCFR_ROWS[12] FUELDATA = 
{2800,3240,3600,4000,4400,4800,5200,5600,6000,6400,6800,7200};

unsigned char LCFR_DATA[70] FUELDATA = 
{0,	0,	0,	0,	0,
2,	1,	1,	0,	0,
5,	4,	2,	1,	0,
8,	6,	4,	2,	0,
10,	7,	5,	2,	0,
13,	10,	6,	3,	0,
16,	12,	8,	4,	0,
19,	14,	9,	4,	0,
22,	16,	10,	5,	0,
26,	19,	12,	6,	0,
29,	21,	13,	6,	0,
33,	23,	15,	7,	0,

};

ThreeDTable LCFuelEnrichTable FUELDATA = {
	.columnCount = 5,
	.rowCount = 12,
	.columnHeaderArray = LCFR_COLS,
	.rowHeaderArray = LCFR_ROWS,
	.tableCells = LCFR_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.0078125,//0x3C000000, // 0.78125 = 2/255 (0-2 range, 8bit precision)
	.offset = 0.0f };

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Fuel Table 1 Intelligent
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
float F_COLS[24] FUELDATA =
{0.2,0.4,0.6,0.8,1.0,1.2,1.4,1.6,1.8,2.0,2.2,2.4,2.6,2.8,3.0,3.2,3.3,3.4,3.5,3.6,3.7,3.8,3.9,4.0};
float F_ROWS[24] FUELDATA =
{500,800,1200,1600,2000,2400,2800,3200,3600,4000,4200,4400,4600,4800,5000,5200,5400,5600,5800,6000,6400,6800,7200,7600};

unsigned char F1I_DATA[576] FUELDATA =
{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0};


ThreeDTable FuelTable1i FUELDATA = {
	.columnCount = 24,
	.rowCount = 24,
	.columnHeaderArray = F_COLS,
	.rowHeaderArray = F_ROWS,
	.tableCells = F1I_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.0078125,//0x3C000000, // 0.78125 = 2/255 (0-2 range, 8bit precision)
	.offset = 0.0f };

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Fuel Table 2 Intelligent
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

unsigned char F2I_DATA[576] FUELDATA =
{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0};


ThreeDTable FuelTable2i FUELDATA = {
	.columnCount = 24,
	.rowCount = 24,
	.columnHeaderArray = F_COLS,
	.rowHeaderArray = F_ROWS,
	.tableCells = F2I_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.0078125,// = 2/255 (0-2 range, 8bit precision)
	.offset = 0.0f };
	
#if SWITCH_HACKS	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Fuel Table 1 Sport
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
unsigned char F1S_DATA[576] FUELDATA =
{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0};
ThreeDTable FuelTable1s FUELDATA = {
	.columnCount = 24,
	.rowCount = 24,
	.columnHeaderArray = F_COLS,
	.rowHeaderArray = F_ROWS,
	.tableCells = F1S_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.0078125,//0x3C000000, // 0.78125 = 2/255 (0-2 range, 8bit precision)
	.offset = 0.0f };

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Fuel Table 2 Sport
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

unsigned char F2S_DATA[576] FUELDATA =
{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0};


ThreeDTable FuelTable2s FUELDATA = {
	.columnCount = 24,
	.rowCount = 24,
	.columnHeaderArray = F_COLS,
	.rowHeaderArray = F_ROWS,
	.tableCells = F2S_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.0078125,// = 2/255 (0-2 range, 8bit precision)
	.offset = 0.0f };
	
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Fuel Table 1 Sport Sharp
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

unsigned char F1SS_DATA[576] FUELDATA =
{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0};


ThreeDTable FuelTable1ss FUELDATA = {
	.columnCount = 24,
	.rowCount = 24,
	.columnHeaderArray = F_COLS,
	.rowHeaderArray = F_ROWS,
	.tableCells = F1SS_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.0078125,//0x3C000000, // 0.78125 = 2/255 (0-2 range, 8bit precision)
	.offset = 0.0f };

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//!! Fuel Table 2 Sport Sharp
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
unsigned char F2SS_DATA[576] FUELDATA =
{0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0,
0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	0,	0,	0};

ThreeDTable FuelTable2ss FUELDATA = {
	.columnCount = 24,
	.rowCount = 24,
	.columnHeaderArray = F_COLS,
	.rowHeaderArray = F_ROWS,
	.tableCells = F2SS_DATA,
	.tableType = UInt8Table3D,
	.multiplier = 0.0078125,// = 2/255 (0-2 range, 8bit precision)
	.offset = 0.0f };
	
	
unsigned char FailSafeFuelAdditive FUELDATA = 0;	
unsigned char EGTFailSafeFuelAdditiveEnable FUELDATA = 0;
unsigned char CoolantTempFailSafeFuelAdditiveEnable FUELDATA = 0;
unsigned char FBKCHiFailSafeFuelAdditiveEnable FUELDATA = 0;
unsigned char LeanBoostFailSafeFuelAdditiveEnable FUELDATA = 0;

	
#endif

#endif