
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>

#include "filter.h"

using namespace std;

int LoadMeasurements(const WCHAR* inputFile, int data[], int maxSize)
{
	cout << "\n\n 2/6 SLL function 'LoadMeasurements' has been called.";

	int dataSize = maxSize;

	//
	// Load data from file.
	//

	return dataSize;
}

int UseFilter(const WCHAR* dllName, int data[], int count, const WCHAR* parameterString)
{
	cout << "\n\n 3/6 SLL function 'UseFilter' has been called.";
	
	int statusCode = UnknownError;

	HINSTANCE dllHandle = LoadLibrary(dllName);

	if (dllHandle != NULL)
	{	
		FpFilter dllFilterFunc = (FpFilter)GetProcAddress(dllHandle, "Filter");

		if (dllFilterFunc != NULL)
		{
			// Call function inside DLL
			statusCode = (dllFilterFunc)(data, count, parameterString);
		}
		else
		{
			return DllInvalidFormat;
		}

		// Free the DLL module
		BOOL dllFreeResult = FreeLibrary(dllHandle);

		if (!dllFreeResult)
		{
			return UnknownError;
		}
	}
	else  
	{
		return DllNotFound;
	}

	return statusCode;
}

int SaveMeasurements(const WCHAR* outputFile, int data[], int maxSize)
{
	cout << "\n\n 5/6 SLL function 'SaveMeasurements' has been called.";

	//
	// Write filtered data to a new file.
	//

	return Success;
}