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

//Tests for Programming mode
#include "EcuHacks.h"
#include "Tests.h"

#if PROG_MODE
void TestProgModeMain(int c)
{
	int i;
	for(i = 0;i<c;i++)
	{
		ProgModeMain();
	}
}

void TestProgModeListener(int c)
{
	int i;
	for(i = 0;i<c;i++)
	{
		ProgModeListener();
	}
}

//TODO NEW TESTS!

void ProgModeUnitTests()
{
	ProgModeEntryTest();	
}

void ProgModeEntryTest()
{
	PopulateRamVariables();
}

#endif