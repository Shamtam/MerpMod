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

void InputUpdate()//TODO: put on SD branch
{
	float grad1 = 0.0000762939453125;
//	float grad2 = 0.0049999999;
	float offs = 0.0f;

	pRamVariables.TGVLeftVolts = ShortToFloatHooked(*pTGVLeftVoltage,grad1,offs);
	pRamVariables.TGVRightVolts = ShortToFloatHooked(*pTGVRightVoltage,grad1,offs);
	pRamVariables.RearO2Volts = *pRearO2Voltage;
	pRamVariables.MAFSensorVolts = ShortToFloatHooked(*pMafSensorVoltage,grad1,offs);

///***************
/// MAP Blending
///***************

	switch(pRamVariables.MapBlendingInputMode)
	{
		case MapBlendingInputModeUndefined:
		break;

		case MapBlendingInputModeTGVLeft:
			UpdateMapBlendRatio(pRamVariables.TGVLeftVolts);
		break;

		case MapBlendingInputModeTGVRight:
			UpdateMapBlendRatio(pRamVariables.TGVRightVolts);
		break;

		case MapBlendingInputModeRearO2:
			UpdateMapBlendRatio(pRamVariables.RearO2Volts);
		break;

		case MapBlendingInputModeMAF:
			UpdateMapBlendRatio(pRamVariables.MAFSensorVolts);
		break;

		default:
			pRamVariables.MapBlendRatio = DefaultMapBlendRatio;
		break;
	}

///***************
/// MAP Switching
///***************

	switch(pRamVariables.MapSwitchingInputMode)
	{
		case MapSwitchingInputModeUndefined:
		break;

		#ifdef pSiDrive
		case MapSwitchingInputModeSiDrive:
			MapSwitchSiDriveCheck();
			break;
		#endif

		case MapSwitchingInputModeTGVLeft:
			MapSwitchThresholdCheck(pRamVariables.TGVLeftVolts);
			break;

		case MapSwitchingInputModeTGVRight:
			MapSwitchThresholdCheck(pRamVariables.TGVRightVolts);
			break;

		case MapSwitchingInputModeRearO2:
			MapSwitchThresholdCheck(pRamVariables.RearO2Volts);
			break;

		case MapSwitchingInputModeMAF:
			MapSwitchThresholdCheck(pRamVariables.MAFSensorVolts);
			break;

		default:
		pRamVariables.MapSwitch = DefaultMapSwitch;
		break;
	}

}

#endif