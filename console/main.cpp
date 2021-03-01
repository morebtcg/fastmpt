#include "db/btree.h"
#include <iostream>
#include <memory>

class TestObj {
public:
  TestObj() { std::cout << "Build me!" << std::endl; }

  TestObj(const TestObj &self) { std::cout << "Copy me!" << std::endl; }

  TestObj(TestObj &&self) { std::cout << "Move me!" << std::endl; }

  void hello() { std::cout << "Hello!" << std::endl; }
};

class Holder {
public:
  Holder(TestObj obj) : m_obj(std::move(obj)) {}

private:
  TestObj m_obj;
};

void pass(TestObj obj) { TestObj dest = std::move(obj); }

int main(int argc, char **argv) {
  TestObj obj;

  std::cout << std::endl << "------------------------------" << std::endl << std::endl;
  // Holder holder(std::move(obj));
  Holder holder(obj);
}