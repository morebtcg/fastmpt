#pragma once
#include <exception>
#include <string>

namespace sdb {
class Exception : public std::exception {
public:
  virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
      return m_what.c_str();
  }

private:
  std::string m_what;
};
} // namespace sdb