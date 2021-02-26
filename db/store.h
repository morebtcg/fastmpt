#pragma once

#include <stddef.h>

namespace sdb {
    class Page {
        public:
    };

    class Store {
        public:
        virtual Page getPage(const char *pageName, size_t length);
        virtual Page setPage(Page page);
    };
}