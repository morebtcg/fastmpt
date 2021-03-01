#pragma once
#include <cstddef>
#include <memory.h>
#include <string>

namespace sdb {
class Slice {
public:
  Slice(const std::byte *buffer, size_t length) noexcept
      : m_buffer(const_cast<std::byte *>(buffer)), m_length(length) {}

  Slice(std::byte *buffer, size_t length) noexcept
      : m_buffer(buffer), m_length(length) {}

  Slice(const std::string &value) noexcept {
    m_buffer = (std::byte *)value.data();
    m_length = value.size();
  }

  Slice(const Slice &slice) noexcept {
    m_buffer = slice.m_buffer;
    m_length = slice.m_length;
  }

  Slice(Slice &&slice) noexcept {
    m_buffer = slice.m_buffer;
    m_length = slice.m_length;

    slice.m_buffer = nullptr;
    slice.m_length = 0;
  }

  const std::byte *buffer() const {
    return const_cast<const std::byte *>(m_buffer);
  }
  size_t length() const { return m_length; }

  std::byte *buffer() { return m_buffer; }

private:
  std::byte *m_buffer = nullptr;
  size_t m_length = 0;
};
} // namespace sdb