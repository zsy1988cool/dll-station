#ifndef _YLZ_CERTIFICATE_ENTITY_PROTOCOL_H_
#define _YLZ_CERTIFICATE_ENTITY_PROTOCOL_H_

#include <string>
#include <json/json.h>
using namespace std;

class Request
{
public:
    Request(const std::string& data);

	Json::Value GetData(const std::string& dataName);
	void SetData(const std::string& dataName, const std::string& dataValue);
	string ToJsonTxt();

protected:
    Json::Value root_;
};

/*
{
    flag:"1",
	cause: "",
    data:{
    }
}
*/
class Response
{
public:
    Response(const std::string& data);
	Response();

	void SetFlag(int ret);

	bool Success();
	string GetCause();
	void SetErrMsg(const std::string& errMsg);
	void SetDataStr(const std::string& data);

	string GetData(const std::string& dataName);
	void SetData(const std::string& dataName, const std::string& dataValue);
	string ToJsonTxt();

protected:
    Json::Value root_;
};
#endif