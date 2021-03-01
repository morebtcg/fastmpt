#pragma once

#include <cstddef>

namespace sdb {
    class Appender {
        public:
        size_t append(const std::byte *buffer, size_t length) {
            return 0;
        }
    };
}