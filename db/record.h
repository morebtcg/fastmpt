#pragma once

#include <cstddef>
#include <cstdint>
#include "slice.h"

namespace sdb {

class Record {
public:
  Record(Slice &slice)  {
      m_value = slice.buffer();
      m_valueLength = slice.length();
  }
  uint32_t length() { return m_valueLength + 8; }

private:
  std::byte *m_value;
  size_t m_valueLength;
};

}