#include <windows.h>
#include <iostream>

#include "filter.h"  // header file inside SLL project

using namespace std;

const WCHAR* INPUT_FILE = L"SignalData.txt";
const WCHAR* OUTPUT_FILE = L"SignalDataOut.txt";
const WCHAR* DLL_NAME = L"DLL";         
const WCHAR* FILTER_RULE = L"3 6";

int MeasurementsData[MAX_DATA];
int DataProcessedCount = 0;

int main() {

	cout << "\n 1/6 Assigment program started.";

	int status = UnknownError;

	// call 1st function in SLL
	DataProcessedCount = LoadMeasurements(INPUT_FILE, MeasurementsData, MAX_DATA);

	if (DataProcessedCount > 0)
	{
		// call 2nd function in SLL
		status = UseFilter(DLL_NAME, MeasurementsData, DataProcessedCount, FILTER_RULE);

		if (status == Success)
		{
			// call 3rd function in SLL
			status = SaveMeasurements(OUTPUT_FILE, MeasurementsData, DataProcessedCount);
		}
		else
		{
			cout << "\n Error code: " << status;
		}
	}
	else
	{
		cout << "\n Error code: " << DataProcessedCount;
	}

	cout << "\n\n 6/6 Assigment program finished.";

	getchar(); // pause

	return 0;
}