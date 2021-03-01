#pragma once

#include <cstdint>

namespace sdb {
class Options {
public:
    int verify = 0;
    uint32_t valueLength = 32;
};
} // namespace sdb