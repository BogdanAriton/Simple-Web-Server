#ifndef HTTP_HEADER
#define HTTP_HEADER

#include <string>

namespace http {
	namespace server {

		struct header
		{
			std::string name;
			std::string value;
		};

	} // namespace server
} // namespace http

#endif // HTTP_HEADER