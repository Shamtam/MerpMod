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

#ifndef __IDA_TRANSLATION__
#define __IDA_TRANSLATION__

//#define pRamVariables             ((RamVariables*)pRamHoleStart)
#define SUB_KCA_HOOK_OLDVAL pKcaIam

#if WGDC_HOOK_DEFINED
#define TableInitialWGDC	((ThreeDTable*)dWgdcInitial)
#define TableMaxWGDC		((ThreeDTable*)dWgdcMax)
#endif

//FBKC AND IAM DEFINES
#ifdef pFbkc4
#define pFBKC					((float*) pFbkc4)
#else
#define pFBKC 			(float)( ( (char*)pFbkc1 ) - 128 )
#endif

#ifdef pIam4
#define pIAM (pIam4)
#define IAM (*(float*)pIam4)					
#else
#define pIAM (pIam1)
#define IAM (float)( (*(char*)pIam1) / 16 )
#endif

#ifdef pCruiseFlags
#ifndef pResumeFlags
#define pResumeFlags	((char*)pCruiseFlags)
#endif
#ifndef	pCoastFlags
#define pCoastFlags	((char*)pCruiseFlags)
#endif
#ifndef	pBrakeFlags
#define pBrakeFlags	((char*)pCruiseFlags)
#endif
#endif

#ifdef pSiDrive
#define SI_DRIVE
#endif

#ifdef dInjectorScaling
#define InjectorScalingOem ((float*)dInjectorScaling)
#endif

#ifdef dFBKCRetardValue
#define FBKCRetardValueOem ((float*)dFBKCRetardValue)
#endif

#ifdef dFBKCRetardValueAlternate
#define FBKCRetardValueAlternateOem ((float*)dFBKCRetardValueAlternate)
#endif

#ifdef tPolf
#define PrimaryOEMPolfTable tPolf
#elif defined(tPolfKcaAlt) //TODO FIX THIS FOR NEWER CARS!!!!!
#define PrimaryOEMPolfTable tPolfKcaAlt
#endif

#ifdef tBaseTiming
#define PrimaryOEMTimingTable tBaseTiming
#elif defined(tBaseTimingPNonCruise) //TODO FIX THIS FOR NEWER CARS!!!!!
#define PrimaryOEMTimingTable tBaseTimingPNonCruise
#endif

#ifdef tTargetBoost
#define OEMTargetBoostTable tTargetBoost
#endif

#ifdef tWgdcInitial
#define OEMWGDCInitialTable tWgdcInitial
#endif

#ifdef tWgdcMax
#define OEMWGDCMaxTable tWgdcMax
#endif

#endif
