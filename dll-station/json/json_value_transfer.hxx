#ifndef SIEAF_COMM_SOURCE_JSON_JSON_VALUE_TRANSFER_HXX_
#define SIEAF_COMM_SOURCE_JSON_JSON_VALUE_TRANSFER_HXX_

#include <json/json.h>
#include <tools/string.h>

namespace comm { namespace JsonValueTransfer {

inline std::string ToString(const Json::Value& value)
{
    switch (value.type())
    {
    case Json::ValueType::nullValue:
        {
            return "";
        }
        break;
    case Json::ValueType::intValue:
        {
            return ::comm::tools::str::FormatString("%d", value.asInt());
        }
        break;
    case Json::ValueType::uintValue:
        {
            return ::comm::tools::str::FormatString("%d", value.asUInt());
        }
        break;
    case Json::ValueType::realValue:
        {
            return ::comm::tools::str::FormatString("%d", value.asDouble());
        }
        break;
    case Json::ValueType::stringValue:
        {
            return value.asString();
        }
        break;
    case Json::ValueType::booleanValue:
        {
            return value.asBool() ? "true" : "false";
        }
        break;
    case Json::ValueType::arrayValue:
        {
            return "array object";
        }
        break;
    case Json::ValueType::objectValue:
        {
            return "object";
        }
        break;
    default:
        break;
    }

    return "";
}

inline std::wstring ToWString(const Json::Value& value)
{
    return STR_U2W(ToString(value));
}

inline int ToInt(const Json::Value& value)
{
    switch (value.type())
    {
    case Json::ValueType::nullValue:
        {
            return 0;
        }
        break;
    case Json::ValueType::intValue:
        {
            return value.asInt();
        }
        break;
    case Json::ValueType::uintValue:
        {
            return (int)value.asUInt();
        }
        break;
    case Json::ValueType::realValue:
        {
            return (int)value.asDouble();
        }
        break;
    case Json::ValueType::stringValue:
        {
            return atoi(value.asString().c_str());
        }
        break;
    case Json::ValueType::booleanValue:
        {
            return value.asBool() ? 1 : 0;
        }
        break;
    case Json::ValueType::arrayValue:
    case Json::ValueType::objectValue:
        {
            return 0;
        }
        break;
    default:
        break;
    }

    return 0;
}

inline unsigned int ToUInt(const Json::Value& value)
{
    switch (value.type())
    {
    case Json::ValueType::nullValue:
        {
            return 0;
        }
        break;
    case Json::ValueType::intValue:
        {
            return (unsigned int)value.asInt();
        }
        break;
    case Json::ValueType::uintValue:
        {
            return value.asUInt();
        }
        break;
    case Json::ValueType::realValue:
        {
            return (unsigned int)value.asDouble();
        }
        break;
    case Json::ValueType::stringValue:
        {
            return (unsigned int)atoi(value.asString().c_str());
        }
        break;
    case Json::ValueType::booleanValue:
        {
            return value.asBool() ? 1 : 0;
        }
        break;
    case Json::ValueType::arrayValue:
    case Json::ValueType::objectValue:
        {
            return 0;
        }
        break;
    default:
        break;
    }

    return 0;
}

inline double ToDouble(const Json::Value& value)
{
    switch (value.type())
    {
    case Json::ValueType::nullValue:
        {
            return 0.0;
        }
        break;
    case Json::ValueType::intValue:
        {
            return (double)value.asInt();
        }
        break;
    case Json::ValueType::uintValue:
        {
            return (double)value.asUInt();
        }
        break;
    case Json::ValueType::realValue:
        {
            return value.asDouble();
        }
        break;
    case Json::ValueType::stringValue:
        {
            return atof(value.asString().c_str());
        }
        break;
    case Json::ValueType::booleanValue:
        {
            return value.asBool() ? 1.0 : 0.0;
        }
        break;
    case Json::ValueType::arrayValue:
    case Json::ValueType::objectValue:
        {
            return 0.0;
        }
        break;
    default:
        break;
    }

    return 0.0;
}

inline bool ToBool(const Json::Value& value)
{
    switch (value.type())
    {
    case Json::ValueType::nullValue:
        {
            return false;
        }
        break;
    case Json::ValueType::intValue:
        {
            return value.asInt() != 0;
        }
        break;
    case Json::ValueType::uintValue:
        {
            return value.asUInt() != 0;
        }
        break;
    case Json::ValueType::realValue:
        {
            return value.asDouble() != 0;
        }
        break;
    case Json::ValueType::stringValue:
        {
            return !value.asString().empty();
        }
        break;
    case Json::ValueType::booleanValue:
        {
            return value.asBool();
        }
        break;
    case Json::ValueType::arrayValue:
    case Json::ValueType::objectValue:
        {
            return false;
        }
        break;
    default:
        break;
    }

    return false;
}

}}


#endif // !SIEAF_COMM_SOURCE_JSON_JSON_VALUE_TRANSFER_HXX_
