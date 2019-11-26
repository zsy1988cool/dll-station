#ifndef SIEAF_COMM_SOURCE_JSON_JSON_VALUE_TRANSFER_H_
#define SIEAF_COMM_SOURCE_JSON_JSON_VALUE_TRANSFER_H_

#include "json_value_transfer.hxx"

#define JSON_TO_STRING(x) \
    ::comm::JsonValueTransfer::ToString(x)
#define JSON_TO_WSTRING(x) \
    ::comm::JsonValueTransfer::ToWString(x)
#define JSON_TO_INT(x) \
    ::comm::JsonValueTransfer::ToInt(x)
#define JSON_TO_UNIT(x) \
    ::comm::JsonValueTransfer::ToUInt(x)
#define JSON_TO_DOUBLE(x) \
    ::comm::JsonValueTransfer::ToDouble(x)
#define JSON_TO_BOOL(x) \
    ::comm::JsonValueTransfer::ToBool(x)

namespace comm { namespace JsonValueTransfer {

inline std::string ToString(const Json::Value& value);
inline std::wstring ToWString(const Json::Value& value);
inline int ToInt(const Json::Value& value);
inline unsigned int ToUInt(const Json::Value& value);
inline double ToDouble(const Json::Value& value);
inline bool ToBool(const Json::Value& value);

}}


#endif // !SIEAF_COMM_SOURCE_JSON_JSON_VALUE_TRANSFER_H_
