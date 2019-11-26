#include "stdafx.h"

#include <iostream>
#include <memory>
#include "server/http_server.h"
#include "handler/handler-mapping.h"

#ifndef _DEBUG
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

#define DEFAULT_PORT "7999"

bool handle_sieaf(std::string url, std::string body, mg_connection *c, OnRspCallback rsp_callback)
{
	static HandlerMapping handlerMapping;
	handlerMapping.handle(url, body, c, rsp_callback);


#ifdef _DEBUG
	std::cout << "handle handle_sieaf" << std::endl;
	std::cout << "url: " << url << std::endl;
	std::cout << "body: " << body << std::endl;
#endif
	return true;
}

int main(int argc, char *argv[])
{
	HANDLE hMutex = CreateMutexA(NULL, true, "dll-station_0D0DDD11-5E3F-4287-BB74-7E3D2C7720EF");
	if (hMutex)
	{
		if (GetLastError() == ERROR_ALREADY_EXISTS)
		{
			std::cerr << "Program already run...\n"
				<< "Press any key to exit..." << std::endl;
			std::cin.get();
			return 1;
		}
	}
	else
	{
		return 1;
	}

	std::string port = DEFAULT_PORT;
	auto http_server = std::shared_ptr<HttpServer>(new HttpServer);
	http_server->Init(port);
	http_server->AddHandler("/sieaf", handle_sieaf);

	std::cout << "dll station web dir:" << HttpServer::s_web_dir << std::endl;
	http_server->Start();

	return 0;
}