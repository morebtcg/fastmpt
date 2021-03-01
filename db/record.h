#pragma once

#include "exception.h"
#include "slice.h"
#include <arpa/inet.h>
#include <cstddef>
#include <cstdint>
#include <memory.h>

namespace sdb {

/*
非叶子节点的记录格式：
|----------value数据----------|--左节点id--|--右节点id--|
|---------valueLength---------|---4字节----|---4字节---|

叶子节点的记录格式：
|----------value数据----------|--------数据偏移--------|
|---------valueLength---------|---------8字节---------|

id和数据偏移皆为网络序
*/
class Record {
public:
  Record(Slice slice, uint32_t valueLength): m_slice(std::move(slice)) {
    if (slice.length() != valueLength + HEADER_LENGTH) {
      throw Exception(-1, "Length not match");
    }
  }

  uint32_t length() { return m_slice.length() + 8; }

  const Slice value() const {
    Slice slice(m_slice.buffer(), m_slice.length() - 8);
    return slice;
  }

  void setValue(const Slice &value) {
    memcpy(m_slice.buffer(), value.buffer(), value.length());
  }

  uint32_t left() { return ntohl(*((uint32_t *)&m_slice.buffer()[m_slice.length() - 8])); }

  void setLeft(uint32_t value) {
    *((uint32_t *)&m_slice.buffer()[m_slice.length() - 8]) = htonl(value);
  }

  uint32_t right() {
    return ntohl(*((uint32_t *)&m_slice.buffer()[m_slice.length() - 8 + sizeof(uint32_t)]));
  }

  void setRight(uint32_t value) {
    *((uint32_t *)&m_slice.buffer()[m_slice.length() - 8 + sizeof(uint32_t)]) = htonl(value);
  }

  uint64_t dataOffset() {
    return ntohll(*((uint64_t *)&m_slice.buffer()[m_slice.length() - 8]));
  }

  void setDataOffset(uint64_t value) {
    *((uint64_t *)&m_slice.buffer()[m_slice.length() - 8]) = htonll(value);
  }

private:
  Slice m_slice;

  static const size_t HEADER_LENGTH = 8;

  uint64_t htonll(uint64_t val) {
    return (((uint64_t)htonl(val)) << 32) + htonl(val >> 32);
  }

  uint64_t ntohll(uint64_t val) {
    return (((uint64_t)ntohl(val)) << 32) + ntohl(val >> 32);
  }
};

} // namespace sdb