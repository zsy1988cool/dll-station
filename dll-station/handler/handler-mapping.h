#ifndef _DLL_STATION_HANDLER_DLL_HANDLER_H_
#define _DLL_STATION_HANDLER_DLL_HANDLER_H_
#include "server/http_server.h"
#include <map>
using Handler = std::function<void(const std::string&, std::string&)>;

class HandlerMapping
{
public:
	HandlerMapping();
	~HandlerMapping();

public:
	void handle(const std::string& url, std::string request, mg_connection *c, OnRspCallback rsp_callback);

protected:
	void registerHandler(const std::string& funcName, Handler handler);

	static void handleBusiness(const std::string& request, std::string& response);
	static void handleAuthorization(const std::string& request, std::string& response);
	static void handleUpdate(const std::string& request, std::string& response);
	static void handleReadCardNum(const std::string& request, std::string& response);
	static void handleReadCardNumAndName(const std::string& request, std::string& response);

private:
	std::string findFuncName(const std::string& url);
	Handler getHandler(const std::string& url);

private:
	std::map<std::string, Handler> m_handlers;
};
#endif