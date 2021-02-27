#pragma once

#include <cstddef>
#include "slice.h"
#include "record.h"

namespace sdb {

class Node {
  public:
    
  private:
    std::byte *m_space;
    size_t m_length;
  };

}