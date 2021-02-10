#pragma once

#include <stddef.h>
#include <string>

namespace sbd {
	class DB {
	public:
		void get(const char *key, size_t length, char *out, size_t outLength) {
			
		}

		std::string get(const std::string &key) {
			return "";
		}
	};
}
