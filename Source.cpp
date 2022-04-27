#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <intrin.h>

int main()
{
	//First part gets the HDD informations
	std::cout << "HWID information" << std::endl;
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)))
	{
		DWORD acceptedSerial = 123456789;
		if (serialNumber == acceptedSerial)
		{
			std::cout << "Welcome to my application!" << std::endl;
		}
		else
		{
			std::cout << "You are not in the system!" << std::endl;
			Sleep(4000);
			return 0;
		}
	}
	//application code goes below.
}