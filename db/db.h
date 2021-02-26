#pragma once

#include <stddef.h>
#include <string>
#include "options.h"

namespace sdb {
class DB {
public:
  virtual void open(const char *path, Options options) {}

  virtual void find(const char *key, size_t keyLength, char *out, size_t outLength) {}

  virtual std::string find(const std::string &key) { return ""; }

  virtual void insert(const char *key, size_t keyLength, const char *value,
           size_t valueLength) {}

  virtual void insert(const std::string &key, const std::string &value) {}

  virtual void remove(const char *key, size_t keyLength) {}

  virtual void remove(const std::string &key) {}
};
} // namespace sdb
