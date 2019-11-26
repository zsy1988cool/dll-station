#include "stdafx.h"
#include "tchar.h"
#include "sieaf-m.h"
#include "windows.h"

//#define SIEAF_DLL_NAME L"sieaf-guider.dll"
#define SIEAF_DLL_NAME L"sieafstandard.dll"

typedef int (_stdcall *business_handle_ptr) (const char*, int, char*, char*);
typedef int (_stdcall *doUpdate_ptr) (char*);
typedef int (_stdcall *authorization_ptr) (const char*, const char*, char*);
typedef int (_stdcall *read_cardnum_ptr) (char*, char*);
typedef int (_stdcall *read_cardnum_and_name_ptr) (char*, char*, char*);

int business_handle(const char* inputValue, int outputLen, char* outputData, char* err)
{
	HINSTANCE hIccardInst = LoadLibrary(SIEAF_DLL_NAME);
	if (hIccardInst)
	{
		business_handle_ptr fPtr = (business_handle_ptr)GetProcAddress(hIccardInst, "business_handle");
		if(fPtr == NULL)
		{
			FreeLibrary(hIccardInst);
			return -1;
		}

		int ret = fPtr(inputValue, outputLen, outputData, err);
		return ret;
	}

	return -1;
}

int authorization(const char* orgName, const char* orgPwd, char* errMsg)
{
	HINSTANCE hIccardInst = LoadLibrary(SIEAF_DLL_NAME);
	if (hIccardInst)
	{
		authorization_ptr fPtr = (authorization_ptr)GetProcAddress(hIccardInst, "authorization");
		if(fPtr == NULL)
		{
			FreeLibrary(hIccardInst);
			strcpy_s(errMsg, 256, "load authorization err");
			return -1;
		}

		int ret = fPtr(orgName, orgPwd, errMsg);
		return ret;
	}

	strcpy_s(errMsg, 256, "load sieafstandard.dll err");
	return -1;
}

int read_cardnum(char* cardNum, char* errMsg)
{
	HINSTANCE hIccardInst = LoadLibrary(SIEAF_DLL_NAME);
	if (hIccardInst)
	{
		read_cardnum_ptr fPtr = (read_cardnum_ptr)GetProcAddress(hIccardInst, "read_cardnum");
		if(fPtr == NULL)
		{
			FreeLibrary(hIccardInst);
			strcpy_s(errMsg, 256, "load read_cardnum err");
			return -1;
		}

		int ret = fPtr(cardNum, errMsg);
		return ret;
	}

	strcpy_s(errMsg, 256, "load sieafstandard.dll err");
	return -1;
}

int read_cardnum_and_name(char* cardNum, char* name, char* errMsg)
{
	HINSTANCE hIccardInst = LoadLibrary(SIEAF_DLL_NAME);
	if (hIccardInst)
	{
		read_cardnum_and_name_ptr fPtr = (read_cardnum_and_name_ptr)GetProcAddress(hIccardInst, "read_cardnum_and_name");
		if(fPtr == NULL)
		{
			FreeLibrary(hIccardInst);
			strcpy_s(errMsg, 256, "load read_cardnum_and_name err");
			return -1;
		}

		int ret = fPtr(cardNum, name, errMsg);
		return ret;
	}

	strcpy_s(errMsg, 256, "load sieafstandard.dll err");
	return -1;
}

int do_update(char* errmsg)
{
	HINSTANCE hIccardInst = LoadLibrary(L"sieaf-update.dll");
	if (hIccardInst)
	{
		doUpdate_ptr fPtr = (doUpdate_ptr)GetProcAddress(hIccardInst, "do_update");
		if(fPtr == NULL)
		{
			FreeLibrary(hIccardInst);
			strcpy_s(errmsg, 256, "load do_update err");
			return -1;
		}

		int ret = fPtr(errmsg);
		return ret;
	}

	strcpy_s(errmsg, 256, "load sieaf-update.dll err");

	return -1;
}