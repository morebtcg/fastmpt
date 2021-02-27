#pragma once

#include "appender.h"
#include "options.h"
#include "slice.h"
#include "store.h"
#include <cstddef>
#include <string>

namespace sdb {
class BTree {
public:
  virtual Slice find(const Slice &key) { return Slice(""); }

  virtual void insert(const Slice &key, const Slice &value) {}

  virtual void remove(const Slice &key) {}

  virtual void setStore(Store *store) { m_store = store; }

  virtual void setAppender(Appender *appender) { m_appender = appender; }

private:
  Store *m_store = NULL;
  Appender *m_appender = NULL;
};
} // namespace sdb
