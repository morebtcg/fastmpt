#pragma once
#include <exception>
#include <string>

namespace sdb {
class Exception : public std::exception {
public:
  Exception(int errorCode, const std::string &what): m_errorCode(errorCode), m_what(what) {
  }

  virtual int errorCode() {
    return m_errorCode;
  }

  virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW {
      return m_what.c_str();
  }

private:
  int m_errorCode = 0;
  const std::string &m_what;
};
} // namespace sdb