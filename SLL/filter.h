#ifndef H_FILTER
#define H_FILTER

const int Success = 0;
const int Failure = -1;
const int DllNotFound = -2;		   // Can't find dll to import
const int DllInvalidFormat = -3;   // Unable to find import function in the dll
const int UnknownError = -4;
const int InvalidParameters = -5;

const int MAX_DATA = 1000;         // Maximum size of the array for loading data 

int LoadMeasurements(const WCHAR* inputFile, int data[], int maxSize);
int UseFilter(const WCHAR* dllName, int data[], int count, const WCHAR* parameterString);
int SaveMeasurements(const WCHAR* outputFile, int data[], int maxSize);

typedef int(*FpFilter)(int[], int, const WCHAR*);  // Function pointer to filter inside DLL

#ifndef ASEXPORT
#define DLLIMPORTOREXPORT dllimport
#else
#define DLLIMPORTOREXPORT dllexport
#endif

#ifdef __cplusplus  // If used by C++ code, 
extern "C" {        // Export C interface (avoid name mangling)
#endif

	_declspec(DLLIMPORTOREXPORT) int Filter(int data[], int count, const WCHAR* parameterString);

#ifdef __cplusplus  // If used by C++ code
}                   // End extern "C"
#endif

#endif