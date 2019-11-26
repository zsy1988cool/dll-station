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
 * 宽字节字符串转为 ANSI 多字节字符串
 *
 * std::wstring 类型为 unicode 编码，std::string 类型可以是多种编码，默认为 ANSI 编码。
 * ppapi 默认使用 UTF8 多字节编码
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
