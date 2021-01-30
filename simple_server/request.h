#ifndef HTTP_REQUEST
#define HTTP_REQUEST

#include <string>
#include <vector>
#include "header.h"

namespace http {
	namespace server {

		/// A request received from a client.
		struct request
		{
			std::string method;
			std::string uri;
			int http_version_major;
			int http_version_minor;
			std::vector<header> headers;
		};

	} // namespace server
} // namespace http

#endif // HTTP_REQUEST