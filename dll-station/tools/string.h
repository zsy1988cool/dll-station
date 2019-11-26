#ifndef SIEAF_COMM_INCLUDE_TOOLS_STRING_LINE_H_
#define SIEAF_COMM_INCLUDE_TOOLS_STRING_LINE_H_

#include "string.hxx"

#define UTF8STR(x) \
    ::comm::tools::str::WidecharToUTF8(L ## x)

#define STR_W2A(x) \
    comm::tools::str::WidecharToANSI(x)

#define STR_W2U(x) \
    comm::tools::str::WidecharToUTF8(x)

#define STR_A2W(x) \
    comm::tools::str::ANSIToWidechar(x)

#define STR_U2W(x) \
    comm::tools::str::UTF8ToWidechar(x)

#define STR_A2U(x) \
    comm::tools::str::ANSIToUTF8(x)

#define STR_U2A(x) \
    comm::tools::str::UTF8ToANSI(x)

namespace comm { namespace tools { namespace str {

/**
 * ���ֽ��ַ���תΪ ANSI ���ֽ��ַ���
 *
 * std::wstring ����Ϊ unicode ���룬std::string ���Ϳ����Ƕ��ֱ��룬Ĭ��Ϊ ANSI ���롣
 * ppapi Ĭ��ʹ�� UTF8 ���ֽڱ���
 */
inline std::string WidecharToANSI( const std::wstring& value );
inline std::string WidecharToUTF8( const std::wstring& value );

inline std::wstring ANSIToWidechar( const std::string& value );
inline std::wstring UTF8ToWidechar( const std::string& value );

inline std::string ANSIToUTF8( const std::string& value );
inline std::string UTF8ToANSI( const std::string& value );

inline std::wstring FormatString( const wchar_t* format, ... );
inline std::string FormatString( const char* format, ... );

inline std::vector<std::wstring> SeparateString( const std::wstring& str, const std::wstring& separator );
inline std::vector<std::string> SeparateString( const std::string& str, const std::string& separator );
inline std::wstring JoinString( std::vector< std::wstring > strs, const std::wstring& separator );
inline std::string JoinString( std::vector< std::string > strs, const std::string& separator );

inline std::string& ltrim(std::string& str);
inline std::wstring& ltrim(std::wstring& str);
inline std::string& rtrim(std::string& str);
inline std::wstring& rtrim(std::wstring& str);
inline std::string& trim(std::string& str);
inline std::wstring& trim(std::wstring& str);

inline std::string int2Str(int n);
inline int str2Int(const char* str);
inline std::string Int2BinaryStr(int mode);
inline int BinaryStr2Int(const std::string& mode);

inline void replace(std::string & strBig, const std::string & strsrc, const std::string &strdst);

}}}

#endif //!SIEAF_COMM_INCLUDE_TOOLS_STRING_LINE_H_
