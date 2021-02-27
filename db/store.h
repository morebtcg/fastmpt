#pragma once

#include <cstddef>
#include "slice.h"

namespace sdb {
    class Store {
        public:
        virtual Slice get(const Slice &key);
        virtual Slice set(const Slice &key, const Slice &value);
    };
}