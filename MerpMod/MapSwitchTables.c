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

#if SWITCH_HACKS

unsigned char DefaultMapSwitch SWITCHDATA = MapSwitch1;
float DefaultMapBlendRatio SWITCHDATA = 0.0f;

float MapSwitchThresholdLo SWITCHDATA = 1.5f;
float MapSwitchThresholdHi SWITCHDATA = 3.5f;

float BlendInputMinimumVolts SWITCHDATA = 0.50f;
float BlendInputMaximumVolts SWITCHDATA = 4.50f;

unsigned char MapBlendFailSafe SWITCHDATA = FailToDefaultBlendRatio;
unsigned short MapBlendCount SWITCHDATA = 45;

float MapBlendSmoothingFactor SWITCHDATA = 0.05f;
float MapSwitchSmoothingFactor SWITCHDATA = 1.0f;
float MapBlendBoostContentLock SWITCHDATA = 760;
unsigned char DefaultMapBlendingInputMode SWITCHDATA = MapBlendingInputModeUndefined;
unsigned char DefaultMapSwitchingInputMode  SWITCHDATA = MapSwitchingInputModeUndefined;

unsigned char OpenLoopFuelingBlendCurveSwitch SWITCHDATA = BlendCurve1;
unsigned char ClosedLoopFuelingBlendCurveSwitch SWITCHDATA = BlendCurve1;
unsigned char TimingBlendCurveSwitch SWITCHDATA = BlendCurve2;
unsigned char KnockControlBlendCurveSwitch SWITCHDATA = BlendCurve2;
unsigned char WastegateDutyBlendCurveSwitch SWITCHDATA = BlendCurve3;
unsigned char BoostBlendCurveSwitch SWITCHDATA = BlendCurve3;
unsigned char MassAirFlowScalingBlendCurveSwitch SWITCHDATA = BlendCurve4;
unsigned char SpeedDensityBlendCurveSwitch SWITCHDATA = BlendCurve4;
//TODO TEST pull2d function here!

float MAP_BLEND_SCALING_ROWS[11] SWITCHDATA =
{0,0.5,1,1.5,2,2.5,3,3.5,4,4.5,5};

short MAP_BLEND_SCALING_DATA[11] SWITCHDATA =
{0,6554,13107,19661,26214,32768,39321,45875,52428,58982,65535};

TwoDTable MapBlendScaling  SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = MAP_BLEND_SCALING_ROWS,
	.tableCells = MAP_BLEND_SCALING_DATA,
	.multiplier = 0.00001525902f,	//todo unit test these
	.offset = 0.0 };
//! 1/65535  (0-1.00 range, 16bit precision)


float MAP_BLEND_CURVE_1_ROWS[11] SWITCHDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

short MAP_BLEND_CURVE_1_DATA[11] SWITCHDATA =
{0,6554,13107,19661,26214,32768,39321,45875,52428,58982,65535};

TwoDTable MapBlendCurve1  SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = MAP_BLEND_CURVE_1_ROWS,
	.tableCells = MAP_BLEND_CURVE_1_DATA,
	.multiplier = 0.00001525902f,	//todo unit test these
	.offset = 0.0 };
//! 1/65535  (0-1.00 range, 16bit precision)

float MAP_BLEND_CURVE_2_ROWS[11] SWITCHDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

short MAP_BLEND_CURVE_2_DATA[11] SWITCHDATA =
{0,6554,13107,19661,26214,32768,39321,45875,52428,58982,65535};

TwoDTable MapBlendCurve2  SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = MAP_BLEND_CURVE_2_ROWS,
	.tableCells = MAP_BLEND_CURVE_2_DATA,
	.multiplier = 0.00001525902f,	//todo unit test these
	.offset = 0.0 };
//! 1/65535  (0-1.00 range, 16bit precision)

float MAP_BLEND_CURVE_3_ROWS[11] SWITCHDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

short MAP_BLEND_CURVE_3_DATA[11] SWITCHDATA =
{0,6554,13107,19661,26214,32768,39321,45875,52428,58982,65535};

TwoDTable MapBlendCurve3 SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = MAP_BLEND_CURVE_3_ROWS,
	.tableCells = MAP_BLEND_CURVE_3_DATA,
	.multiplier = 0.00001525902f,	//todo unit test these
	.offset = 0.0 };
//! 1/65535  (0-1.00 range, 16bit precision)

float MAP_BLEND_CURVE_4_ROWS[11] SWITCHDATA =
{0,0.1,0.2,0.3,0.4,0.5,0.6,0.7,0.8,0.9,1};

short MAP_BLEND_CURVE_4_DATA[11] SWITCHDATA =
{0,6554,13107,19661,26214,32768,39321,45875,52428,58982,65535};

TwoDTable MapBlendCurve4  SWITCHDATA = {
	.columnCount = 11,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = MAP_BLEND_CURVE_4_ROWS,
	.tableCells = MAP_BLEND_CURVE_4_DATA,
	.multiplier = 0.00001525902f,	//todo unit test these
	.offset = 0.0 };
//! 1/65535  (0-1.00 range, 16bit precision)

float TipInEnrichMultiplierAxis[18] SWITCHDATA =
{0,0.9799999594688416,1.949999928474426,3.909999847412109,5.859999656677246,
7.809999942779541,9.769999504089355,11.69999980926514,13.69999980926514,
15.59999942779541,17.59999847412109,19.5,21.5,23.39999961853027,
25.39999961853027,27.29999923706055,29.29999923706055,31.29999923706055};

short TipInEnrichMultiplierData[18] SWITCHDATA =
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

TwoDTable TipInEnrichMultiplier SWITCHDATA = {
	.columnCount = 18,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = TipInEnrichMultiplierAxis,
	.tableCells = TipInEnrichMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

float CrankingFuelMultiplierAxis[16] SWITCHDATA = 
{-40,-22,-4,14,32,50,68,86,104,122,140,158,176,194,212,230};

short CrankingFuelMultiplierData[16] SWITCHDATA = 
{16360,16252,15010,14020,12689,11639,6632,6554,6554,6554,6554,6554,6554,6554,6554,6554,};

TwoDTable CrankingFuelMultiplier SWITCHDATA = {
	.columnCount = 16,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = CrankingFuelMultiplierAxis,
	.tableCells = CrankingFuelMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

float StartupEnrichMultiplierECTAxis[16] SWITCHDATA = 
{-40,-22,-4,14,32,50,68,86,104,122,140,158,176,194,212,230};

short StartupEnrichMultiplierData[16] SWITCHDATA = 
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

TwoDTable StartupEnrichMultiplier SWITCHDATA = {
	.columnCount = 16,
	.tableType = UInt16Table2D,//TODO: CHECK that these are consistent between 2d/3d tables!
	.columnHeaderArray = StartupEnrichMultiplierECTAxis,
	.tableCells = StartupEnrichMultiplierData,
	.multiplier = 0.0001525902f,	//todo unit test these
	.offset = 0.0 };
//! 10/65535  (0-10 range, 16bit precision)

#endif