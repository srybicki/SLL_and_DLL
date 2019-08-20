// DLL.cpp : Defines the exported functions for the DLL application.

#include "windows.h"
#include <iostream>

#define ASEXPORT
#include "filter.h"  // header file inside SLL project

using namespace std;

int Filter(int data[], int count, const WCHAR* parameterString)
{
	cout << "\n\n 4/6 DLL function 'Filter' has been called.";

	//
	// Filter the data.
	//

	return Success;
}