#include "stdafx.h"

#include <iostream>
#include <memory>
#include "server/http_server.h"
#include "handler/handler-mapping.h"

#define DEFAULT_PORT "7999"

bool handle_sieaf(std::string url, std::string body, mg_connection *c, OnRspCallback rsp_callback)
{
	static HandlerMapping handlerMapping;
	handlerMapping.handle(url, body, c, rsp_callback);


	// do sth
	std::cout << "handle handle_sieaf" << std::endl;
	std::cout << "url: " << url << std::endl;
	std::cout << "body: " << body << std::endl;

	//c->m

	/*rsp_callback(c, "{        \r\n \
    \"funid\": \"yb04.07.04.03\",   \r\n\
	\"bke264\": \"ybcs\",   \r\n\
	\"bke265\": \"000000\",   \r\n\
    \"data\": {                                   \r\n\
		\"aac002\": \"350201189807392938\",     \r\n\
		\"aac001\": \"123\",                   \r\n\
		\"aac003\": \"÷‹…´“È\",                   \r\n\
		\"aaz500\": \"DD2402056\"                   \r\n\
	}                          \r\n\
}");*/

	return true;
}

int main(int argc, char *argv[])
{
	std::string port = DEFAULT_PORT;
	auto http_server = std::shared_ptr<HttpServer>(new HttpServer);
	http_server->Init(port);
	http_server->AddHandler("/sieaf", handle_sieaf);
	http_server->Start();

	return 0;
}