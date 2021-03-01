#pragma once

#include <cstddef>
#include "slice.h"
#include "record.h"
#include "exception.h"

namespace sdb {

/*
B-Tree节点数据格式：
|--记录数量--|--节点类型--|--下一节点id--|------记录列表------|
|---2字节----|---2字节---|----4字节-----|---nodeLength-8----|

记录数量、节点类型、id为网络序
*/
class Node {
  public:
    Node(Slice slice, uint32_t valueLength):m_slice(std::move(slice)) {
      if(slice.length() != valueLength + HEADER_LENGTH) {
        throw Exception(-1, "Length not match");
      }
    }

    uint16_t recordSize() {
      return *((uint16_t*)m_slice.buffer());
    }

    void setRecordSize(uint16_t size) {
      *((uint16_t*)m_slice.buffer()) = size;
    }

    uint16_t nodeType() {
      return *((uint16_t*)m_slice.buffer()[2]);
    }

    void setNodeType(uint16_t type) {
      *((uint16_t*)m_slice.buffer()[2]) = type;
    }

    uint32_t nextID() {
      return *((uint32_t*)m_slice.buffer()[4]);
    }

    void setNextID(uint32_t id) {
      *((uint32_t*)m_slice.buffer()[4]) = id;
    }

  private:
    Slice m_slice;

    static const size_t HEADER_LENGTH = 8;
  };

}