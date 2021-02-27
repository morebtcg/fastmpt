#pragma once
#include <cstddef>
#include <memory.h>
#include <string>

namespace sdb {
    class Slice {
        public:
        Slice(const std::byte *buffer, size_t length): m_buffer(buffer), m_length(length) {
        }

        Slice(std::byte *buffer, size_t length): m_buffer(buffer), m_length(length), m_mutableBuffer(buffer) {
        }

        Slice(const std::string &value) {
            m_buffer = (const std::byte*)value.data();
            m_length = value.size();
        }

        const std::byte* buffer() const { return m_buffer; }
        size_t length() const { return m_length; }

        std::byte *buffer() { return m_mutableBuffer; }

        private:
        const std::byte *m_buffer = NULL;
        size_t m_length = 0;

        std::byte *m_mutableBuffer = NULL;
    };
}