#ifndef HTTP_REQUEST_HANDLER
#define HTTP_REQUEST_HANDLER

#include <string>

namespace http
{
	namespace server
	{
		struct reply;
		struct request;

		class request_handler
		{
		public:
			request_handler(const request_handler&) = delete;
			request_handler operator=(const request_handler) = delete;

			/// Construct with a directory containg files to be served
			explicit request_handler(const std::string& doc_root);

			/// Handle a request and produce a reply
			void handle_request(const request& req, reply& rep);

		private:
			///  The directory containing the files to be served
			std::string doc_root_;

			/// Perform URL_decoding on a string (returns false if the decode was invalid)
			static bool url_decode(const std::string& in, std::string& out);
		};
	}
}

#endif // !HTTP_REQUEST_HANDLER