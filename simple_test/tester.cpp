#include <iostream>

#ifdef _WIN32
#define _WIN32_WINNT 0X0A00
#endif

#define ASIO_STANDALONE
#include <asio.hpp>
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

std::vector<char> vBuffer(20 * 1024);


int main()
{
	asio::error_code ec;
	asio::io_context ioC;

	// this is just an address to somewhere - in this case this is: www.google.com - 172.217.16.196
	// ip98-184-216-34.oc.oc.cox.net - 98.184.216.34
	// 51.38.81.49
	asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), 8080);

	// we need a socket that would build the connection over TCP
	asio::ip::tcp::socket socket(ioC);

	socket.connect(endpoint, ec);

	if (!ec)
		std::cout << "Connected!" << std::endl;
	else
	{
		std::cout << "Failed to connect: " << std::endl << ec.message() << std::endl;
		return 0;
	}

	if (socket.is_open())
	{
		std::string sRequest =
			"GET http://localhost:8080/index.html HTTP/1.1\r\n"
			"Host: localhost:8080\r\n"
			"Connection: close\r\n";

		socket.write_some(asio::buffer(sRequest.data(), sRequest.size()), ec);
		socket.wait(socket.wait_read);
		using namespace std::chrono_literals;
		std::this_thread::sleep_for(2000ms);

		size_t bytes = socket.available();
		std::cout << "Bytes available: " << bytes << std::endl;
		if (bytes > 0)
		{
			socket.read_some(asio::buffer(vBuffer.data(), vBuffer.size()), ec);

			for (auto c : vBuffer)
			{
				std::cout << c;
			}
		}

	}

	system("pause");

	return 0;
}