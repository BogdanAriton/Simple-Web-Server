#ifndef  HTTP_SERVER_ASIO
#define HTTP_SERVER_ASIO

#include <asio.hpp>
#include <string>
#include "connection.h"
#include "connection_manager.h"
#include "request_handler.h"

namespace http
{
	namespace server
	{
		class server
		{
		public:
			/// we don't allow copy constructor and copy assigment operator
			server(const server&) = delete;
			server operator=(const server&) = delete;

			/// The server listens on a specific TCP address and Port and servs files from a specific location
			explicit server(const std::string& address, const std::string& port, const std::string& doc_root);

			/// Start the server
			void run();

		private:
			/// Perform and async accept opperation
			void do_accept();

			/// Wait for someone to stop the server
			void do_await_stop();

			/// The io_context used to perform async operations
			asio::io_context io_context_; // we may want to create this only once

			/// Signal set is used to register for process termination notif
			asio::signal_set signals_;

			/// Acceptor used to listen for incoming connections
			asio::ip::tcp::acceptor acceptor_;

			/// The connection manager which owns all live connections
			connection_manager connection_manager_;

			/// The handler for all incomming requests
			request_handler request_handler_;
		};

	} // namespace server
} // namespace http

#endif // ! HTTP_SERVER_ASIO