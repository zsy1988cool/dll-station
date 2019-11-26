#include "stdafx.h"
#include "Protocol.h"

Request::Request(const std::string& data)
{
	Json::Reader reader;
	reader.parse(data, root_);
}

string Request::ToJsonTxt()
{
	Json::FastWriter writer;
	string jsonData =  writer.write(root_);
	return jsonData;
}

Json::Value Request::GetData(const std::string& dataName)
{
	return root_[dataName];;

}

void Request::SetData(const std::string& dataName, const std::string& dataValue)
{
	root_[dataName] = dataValue;
}

Response::Response( const std::string& data )
{
	Json::Reader reader;
	reader.parse(data, root_);
}

void Response::SetFlag(int ret)
{
	if(ret == 0)
	{
		root_["flag"] = "1";
	}
	else
	{
		root_["flag"] = "0";
	}
}

Response::Response()
{
	std::string default = "{\"flag\": \"1\", \"cause\": \"\", \"data\": {}}";

	Json::Reader reader;
	reader.parse(default, root_);
}

bool Response::Success()
{
	string flag = root_["flag"].asString();
	return "1" == flag;
}

string Response::GetCause()
{
	return root_["cause"].asString();
}

void Response::SetErrMsg(const std::string& errMsg)
{
	root_["cause"] = errMsg;
}

void Response::SetDataStr(const std::string& data)
{
	Json::Value dataNode;
	Json::Reader reader;
	reader.parse(data, dataNode);

	root_["data"] = dataNode;
}

string Response::ToJsonTxt()
{
	Json::FastWriter writer;
	string jsonData =  writer.write(root_);
	return jsonData;
}

string Response::GetData(const std::string& dataName)
{
	Json::Value data =  root_["data"];
	if(data.empty() || !data.isObject())
	{
		return "";
	}

	Json::Value::Members mems = data.getMemberNames();

	Json::Value itemData =  data[dataName];
	if(itemData.isNull())
		return "";
	return itemData.asString();;
}

void Response::SetData(const std::string& dataName, const std::string& dataValue)
{
	Json::Value& data =  root_["data"];
	data[dataName] = dataValue;
}