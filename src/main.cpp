#include <iostream>
#include "babylon/anyflow/builder.h"
#include "gperftools/tcmalloc.h"
#include "leveldb/db.h"
#include "ppconsul/ppconsul.h"
#include "hello.pb.h"

int main() {
    std::cout << "hello, vcpkg." << std::endl;
    auto r = tc_malloc(100);
    tc_free(r);

    ppconsul::kv::kw::keys;

    // protobuf
    hello::Request request;
    request.set_value(1);
    return 0;
}