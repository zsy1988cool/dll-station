#ifndef SIEAF_COMM_INCLUDE_TOOLS_UTILITY_HXX_
#define SIEAF_COMM_INCLUDE_TOOLS_UTILITY_HXX_
#include <windows.h>
#include <string>

inline HMODULE GetSelfModuleHandle()
{
	MEMORY_BASIC_INFORMATION mbi;
	return ((::VirtualQuery(GetSelfModuleHandle, &mbi, sizeof(mbi)) != 0) ? (HMODULE)mbi.AllocationBase : NULL);
}

inline std::string GetModuleDirA()
{
	char szPath[MAX_PATH];
	::GetModuleFileNameA(GetSelfModuleHandle(), szPath, MAX_PATH);

	std::string aRet = szPath;
	size_t pos = aRet.find_last_of("\\");
	aRet = aRet.substr(0, pos + 1);

	return aRet;
}

#endif