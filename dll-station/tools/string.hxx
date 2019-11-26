#ifndef SIEAF_COMM_INCLUDE_TOOLS_STRING_LINE_HXX_
#define SIEAF_COMM_INCLUDE_TOOLS_STRING_LINE_HXX_

#include <string>
#include <vector>
#include <codecvt>
#include <stdarg.h>
#include <windows.h>
#include <atlstr.h>
#include <algorithm>
#include <xfunctional>
#include <sstream>


namespace comm { namespace tools { namespace str {

inline std::string WidecharToANSI( const std::wstring& value )
{
    std::string aRet;
    int nLen = WideCharToMultiByte(CP_ACP, 0, value.c_str(), -1, NULL, 0, NULL, NULL);
    if (nLen <= 0)
        return aRet;

    char* pszDesc = new char[nLen + 1];
    memset((void*)pszDesc, 0, sizeof(char) * (nLen + 1));
    WideCharToMultiByte(CP_ACP, 0, value.c_str(), -1, pszDesc, nLen, NULL, NULL);
    aRet = pszDesc;
    delete[] pszDesc;

    return aRet;
}

inline std::string WidecharToUTF8( const std::wstring& value )
{
    std::wstring_convert< std::codecvt_utf8< wchar_t > > conv;
    return conv.to_bytes( value );
}

inline std::wstring ANSIToWidechar( const std::string& value )
{
    std::wstring aRet;
    int nLen = ::MultiByteToWideChar(CP_ACP, 0, value.c_str(), -1, NULL, 0); 
    wchar_t * pszDesc = new wchar_t[nLen+1]; 
    memset(pszDesc , 0, (nLen+1) * sizeof(wchar_t)); 

    ::MultiByteToWideChar(CP_ACP, 0, value.c_str(), -1, pszDesc, nLen); 
    aRet = pszDesc;
    delete[] pszDesc;

    return  aRet;
}

inline std::wstring UTF8ToWidechar( const std::string& value )
{
    std::wstring_convert< std::codecvt_utf8< wchar_t > > conv;
    return conv.from_bytes( value );
}

inline std::string ANSIToUTF8( const std::string& value )
{
    return WidecharToUTF8( ANSIToWidechar( value ) );
}

inline std::string UTF8ToANSI( const std::string& value )
{
    return WidecharToANSI( UTF8ToWidechar( value.c_str() ) );
}

inline std::wstring FormatString( const wchar_t* format, ... )
{
    va_list args; 
    va_start(args, format);

    CStringW s;
    s.FormatV(format, args);

    va_end(args);

    return s.GetString();
}

inline std::string FormatString( const char* format, ... )
{
    va_list args; 
    va_start(args, format);

    CStringA s;
    s.FormatV(format, args);

    va_end(args);

    return s.GetString();
}


inline std::vector<std::wstring> SeparateString( const std::wstring& str, const std::wstring& separator )
{
    std::vector< std::wstring > aRet;
    wchar_t* pszPaths = (wchar_t*)str.c_str();

    wchar_t* sep = (wchar_t*)separator.c_str();
    wchar_t* token(NULL);
    wchar_t* next_token(NULL);
    token = wcstok_s(pszPaths, sep, &next_token);
    while(token)
    {
        aRet.push_back( std::wstring( token ) );
        token = wcstok_s(NULL, sep, &next_token);
    }

    return aRet;
}

inline std::vector<std::string> SeparateString( const std::string& str, const std::string& separator )
{
    std::vector< std::string > aRet;
    char* pszPaths = (char*)str.c_str();

    char* sep = (char*)separator.c_str();
    char* token(NULL);
    char* next_token(NULL);
    token = strtok_s(pszPaths, sep, &next_token);
    while(token)
    {
        aRet.push_back( std::string( token ) );
        token = strtok_s(NULL, sep, &next_token);
    }

    return aRet;
}

inline std::wstring JoinString( std::vector< std::wstring > strs, const std::wstring& separator )
{
    std::wstring aRet;

    for( size_t i = 0; i < strs.size(); i++ )
    {
        aRet += strs[i];
        if( i < strs.size() - 1 )
            aRet += separator;
    }

    return aRet;
}

inline std::string JoinString( std::vector< std::string > strs, const std::string& separator )
{
    std::string aRet;

    for( size_t i = 0; i < strs.size(); i++ )
    {
        aRet += strs[i];
        if( i < strs.size() - 1 )
            aRet += separator;
    }

    return aRet;
}

template<class T>
inline bool IsSubset(const T& str1, const T& str2)
{
    if(str1 == str2) return true;

    if(str1.length() > str2.length())
    {
        T::size_type pos = str1.find(str2);
        return pos != T::npos;
    }
    else
    {
        T::size_type pos = str2.find(str1);
        return pos != T::npos;
    }
}

inline std::string& ltrim(std::string& str)
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(),
        std::not1(std::ptr_fun(::isspace))));
    return str;
}

inline std::string& rtrim(std::string& str)
{
    str.erase(std::find_if(str.rbegin(), str.rend(),
        std::not1(std::ptr_fun(::isspace))).base(),
        str.end());
    return str;
}

inline std::string& trim(std::string& str)
{
    return ltrim(rtrim(str));
}

inline std::wstring& ltrim(std::wstring& str)
{
    str.erase(str.begin(), std::find_if(str.begin(), str.end(),
        std::not1(std::ptr_fun(::isspace))));
    return str;
}

inline std::wstring& rtrim(std::wstring& str)
{
    str.erase(std::find_if(str.rbegin(), str.rend(),
        std::not1(std::ptr_fun(::isspace))).base(),
        str.end());
    return str;
}

inline std::wstring& trim(std::wstring& str)
{
    return ltrim(rtrim(str));
}

inline std::string int2Str(int n)
{
	std::ostringstream stream;
	stream << n;
	return stream.str();
}

inline int str2Int(const char* str)
{
	int val = atoi(str);
	return val;
}

inline std::string Int2BinaryStr(int mode)
{
	int and = 0x01;
	char pszValue[9];
	for(int i = 0; i < 8; i ++)
	{
		int bit = and & mode;

		if(bit != 0)
		{
			pszValue[7-i] = '1';
		}
		else
		{
			pszValue[7-i] = '0';
		}

		and <<= 1;
	}

	pszValue[8] = 0;
	return pszValue;
}

int BinaryStr2Int(const std::string& sMode)
{
	int nMode = 0;

	int bitLen = sMode.length();
	for(int pos = 0; pos < bitLen; pos++)
	{
		char bitNum = sMode[7-pos];
		if(bitNum == '1')
		{
			int bit = (1 << pos);
			nMode |= bit;
		}
	}

	return nMode;
}

inline void replace(std::string & strBig, const std::string & strsrc, const std::string &strdst)
{
    std::string::size_type pos = 0;
    std::string::size_type srclen = strsrc.size();
    std::string::size_type dstlen = strdst.size();
    while ((pos = strBig.find(strsrc, pos)) != std::string::npos)
    {    
        strBig.replace(pos, srclen, strdst);   
        pos += dstlen;   
    }
}

}}}

#endif //!SIEAF_COMM_INCLUDE_TOOLS_STRING_LINE_HXX_
