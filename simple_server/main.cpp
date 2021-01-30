#pragma once

#ifdef _WIN32
#define _WIN32_WINNT 0X0A00
#endif

#include <iostream>
#include <string>
#include <asio.hpp>
#include "server.h"

int main(int argc, char* argv[])
{
	try
	{
		// we check arguments
		if (argc != 4)
		{
			std::cerr << "Usage: http_server <address> <port> <doc_root>" << std::endl;
			std::cerr << " For IPv4 try: " << std::endl;
			std::cerr << "     receiver 127.0.0.1 port 80" << std::endl;
			std::cerr << " For IPv6 try:" << std::endl;
			std::cerr << "     receiver ::1/128 port 80" << std::endl;
			return 1;
		}

		// Init server
		http::server::server s(argv[1], argv[2], argv[3]);

		// Run the server until stopped
		s.run();

	}
	catch (std::exception& e)
	{
		std::cerr << "exception found: " << e.what() << std::endl;
	}

	return 0;
}