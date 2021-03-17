/*
    Copyright (C) 2021 Shamit Som shamitsom@gmail.com

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/

//Generic tests

#ifdef sMemoryReset
extern void CallMemoryReset() __attribute__ ((section ("Misc")));
#endif

extern void GenericTests() __attribute__ ((section ("Misc")));
extern void BrickBuster() __attribute__ ((section ("Misc")));
extern void SetValues() __attribute__ ((section ("Misc")));

//Test utilities
extern void TestFailed(char *message) __attribute__ ((section ("Misc")));
extern void Assert(int condition, char *message) __attribute__ ((section("Misc")));
extern void DemonstrateAssertionFailure() __attribute__ ((section ("Misc")));
extern void ClearRam() __attribute__ ((section ("Misc")));
extern int AreCloseEnough(float actual, float expected) __attribute__ ((section ("Misc")));

#if CEL_HACKS
extern void TestCelFlash(int c) __attribute__ ((section ("Misc")));
extern void CelFlashUnitTests() __attribute__ ((section ("Misc")));
#endif

#if CAN_HACKS
extern void TestCustomCan(int c) __attribute__ ((section ("Misc")));
extern unsigned long getMailBoxId(unsigned short mailbox, unsigned short bus) __attribute__ ((section ("Misc")));
extern void CustomCanUnitTests() __attribute__ ((section ("Misc")));
#endif

#if DYN_RAMTUNING
extern void Pull2DFloatTests() __attribute__ ((section ("Misc")));
extern void Pull3DFloatTests() __attribute__ ((section ("Misc")));
#endif

#if PROG_MODE
extern void ProgModeEntryTest() __attribute__ ((section ("Misc")));
extern void ProgModeUnitTests() __attribute__ ((section ("Misc")));
extern void TestProgModeListener(int c) __attribute__ ((section ("Misc")));
extern void TestProgModeMain(int c) __attribute__ ((section ("Misc")));
#endif

#if !AUTO_TRANS
extern void SetClutch(int value);
#endif

#ifdef pBrakeFlags
extern void SetBrake(int value);
#endif

#if REVLIM_HACKS
extern unsigned char GetFuelCutFlag() __attribute__ ((section ("Misc")));
extern void RevLimUnitTest(unsigned char flag, int brake, int clutch, float throttle, float mph, float rpm) __attribute__ ((section ("Misc")));
extern void RevLimUnitTests() __attribute__ ((section ("Misc")));
#endif

#if SD_HACKS
extern float CallSpeedDensityHook() __attribute__ ((section ("Misc")));
extern void SpeedDensityUnitTests() __attribute__ ((section ("Misc")));
#endif

#if TIMING_HACKS
extern void TimingHackUnitTests() __attribute__ ((section ("Misc")));
#endif

#if POLF_HACKS
extern void PolfHackUnitTests() __attribute__ ((section ("Misc")));
#endif