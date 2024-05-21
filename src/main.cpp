#include <iostream>
#include "babylon/anyflow/builder.h"
#include "gperftools/tcmalloc.h"
#include "leveldb/db.h"

int main() {
    std::cout << "hello, vcpkg." << std::endl;
    auto r = tc_malloc(100);
    tc_free(r);
    return 0;
}