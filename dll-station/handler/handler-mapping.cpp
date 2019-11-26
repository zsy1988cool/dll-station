#include "handler-mapping.h"
#include <iostream>
#include "dlls/sieaf-m.h"
#include "protocol.h"
#include "common/macro.h"
#include "json/json_value_transfer.h"

HandlerMapping::HandlerMapping()
{
	registerHandler("business_handle", HandlerMapping::handleBusiness);
	registerHandler("authorization", HandlerMapping::handleAuthorization);
	registerHandler("do_update", HandlerMapping::handleUpdate);
	registerHandler("read_cardnum", HandlerMapping::handleReadCardNum);
	registerHandler("read_cardnum_and_name", HandlerMapping::handleReadCardNumAndName);
}

HandlerMapping::~HandlerMapping()
{}

std::string HandlerMapping::findFuncName(const std::string& url)
{
	std::string myurl = url;
	size_t pos = myurl.find_last_of("/");
	if (pos == myurl.length() - 1)
	{
		myurl = myurl.substr(0, myurl.length() - 1);
	}

	pos = myurl.find_last_of("/") + 1;
	std::string func = myurl.substr(pos, myurl.length() - pos);
	return func;
}

Handler HandlerMapping::getHandler(const std::string& url)
{
	std::string funcName = findFuncName(url);
	std::map<std::string, Handler>::iterator it = m_handlers.find(funcName);
	if (it != m_handlers.end())
	{
		return it->second;
	}

	return NULL;
}

void HandlerMapping::handle(const std::string& url, std::string request, mg_connection *c, OnRspCallback rsp_callback)
{
	Handler handlerFunc = getHandler(url);
	if (handlerFunc != NULL)
	{
		std::string response;
		handlerFunc(STR_U2A(request), response);

		rsp_callback(c, STR_A2U(response));
		return;
	}

	rsp_callback(c, "could not find the handle function, please checkout you url!");
}

void HandlerMapping::registerHandler(const std::string& funcName, Handler handler)
{
	m_handlers.insert(std::pair<std::string, Handler>(funcName, handler));
}

void HandlerMapping::handleBusiness(const std::string& requeststr, std::string& responsestr)
{
	Request request(requeststr);

	std::string inputValue = JSON_TO_STRING(request.GetData(Param_BusinessHandle_InputValue));
	std::string outputLenStr = JSON_TO_STRING(request.GetData(Param_BusinessHandle_OutputLen));
	int outputlen = atoi(outputLenStr.c_str());

	char outputData[30000];
	char errMsg[256];
	memset(errMsg, 0, 256);
	memset(outputData, 0, 30000);
	int ret = business_handle(inputValue.c_str(), outputlen, outputData, errMsg);

	if (ret == 0)
	{
		responsestr = outputData;
		return;
	}
	Response response;
	response.SetFlag(ret);
	response.SetErrMsg(errMsg);
	response.SetData(Param_BusinessHandle_OutputValue, outputData);

	responsestr = response.ToJsonTxt();
}

void HandlerMapping::handleAuthorization(const std::string& requeststr, std::string& responsestr)
{
	Request request(requeststr);

	std::string username = JSON_TO_STRING(request.GetData(Param_Authorization_User));
	std::string pwd = JSON_TO_STRING(request.GetData(Param_Authorization_Pwd));

	char errMsg[256];
	memset(errMsg, 0, 256);
	int ret = authorization(username.c_str(), pwd.c_str(), errMsg);

	Response response;
	response.SetFlag(ret);
	response.SetErrMsg(errMsg);

	responsestr = response.ToJsonTxt();
}

void HandlerMapping::handleUpdate(const std::string& requeststr, std::string& responsestr)
{
	char errMsg[256];
	memset(errMsg, 0, 256);

	int ret = do_update(errMsg);

	Response response;
	response.SetFlag(ret);
	response.SetErrMsg(errMsg);

	responsestr = response.ToJsonTxt();
}

void HandlerMapping::handleReadCardNum(const std::string& requeststr, std::string& responsestr)
{
	char errMsg[256];
	char cardNum[256];
	memset(errMsg, 0, 256);
	memset(cardNum, 0, 256);

	int ret = read_cardnum(cardNum, errMsg);

	Response response;
	response.SetFlag(ret);
	response.SetErrMsg(errMsg);
	response.SetData(Param_ReadCardNum_CardNum, cardNum);

	responsestr = response.ToJsonTxt();
}

void HandlerMapping::handleReadCardNumAndName(const std::string& requeststr, std::string& responsestr)
{
	char errMsg[256];
	char cardNum[256];
	char name[256];
	memset(errMsg, 0, 256);
	memset(cardNum, 0, 256);
	memset(name, 0, 256);

	int ret = read_cardnum_and_name(cardNum, name, errMsg);

	Response response;
	response.SetFlag(ret);
	response.SetErrMsg(errMsg);
	response.SetData(Param_ReadCardNum_CardNum, cardNum);
	response.SetData(Param_ReadCardNumAndName_Name, name);

	responsestr = response.ToJsonTxt();
}