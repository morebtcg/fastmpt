#include <iostream>
#include "libfastmpt/fastmpt.h"

int main(int argc, char** argv) {
    fastmpt::Trie trie;

    int a = 0;
    trie.get(a);
    std::cout << "Hello world!" << std::endl;

    return 0;
}