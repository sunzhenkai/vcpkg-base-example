CMAKE_MINIMUM_REQUIRED(VERSION 3.24)
PROJECT(vcpkg-base-example)

INCLUDE(${PROJECT_SOURCE_DIR}/3rd/vcpkg-base/cmakes/tools.cmake)
INCLUDE(${PROJECT_SOURCE_DIR}/3rd/vcpkg-base/cmakes/protobuf.cmake)
INCLUDE(${PROJECT_SOURCE_DIR}/3rd/vcpkg-base/cmakes/flatbuffers.cmake)

set(TARGET_LIBRARIES)
find_package(libuv CONFIG REQUIRED)
list(APPEND TARGET_LIBRARIES $<IF:$<TARGET_EXISTS:libuv::uv_a>,libuv::uv_a,libuv::uv>)

# datastax-cpp-driver
find_package(datastax-cpp-driver CONFIG REQUIRED CONFIGS cassandra_staticConfig.cmake)
list(APPEND TARGET_LIBRARIES cassandra::cassandra_static)
#FIND_PACKAGE(PkgConfig REQUIRED)
#pkg_check_modules(cassandra_static REQUIRED IMPORTED_TARGET cassandra_static)
#list(APPEND TARGET_LIBRARIES PkgConfig::cassandra_static)

# cpp-common
#pkg_check_modules(cpp-common REQUIRED IMPORTED_TARGET cpp-common)
find_package(cpp-common CONFIG REQUIRED)
list(APPEND TARGET_LIBRARIES cpp-common::cpp-common)

find_package(babylon CONFIG REQUIRED)
list(APPEND TARGET_LIBRARIES babylon::babylon)

# gperftools
find_package(tcmalloc_static CONFIG REQUIRED)
list(APPEND TARGET_LIBRARIES tcmalloc::tcmalloc_static)
find_package(tcmalloc_minimal_static CONFIG REQUIRED)
list(APPEND TARGET_LIBRARIES tcmalloc_minimal::tcmalloc_minimal_static)
find_package(profiler_static CONFIG REQUIRED)
list(APPEND TARGET_LIBRARIES profiler::profiler_static)
find_package(tcmalloc_and_profiler_static CONFIG REQUIRED)
list(APPEND TARGET_LIBRARIES tcmalloc_and_profiler::tcmalloc_and_profiler_static)

# leveldb
find_package(leveldb CONFIG REQUIRED)
list(APPEND TARGET_LIBRARIES leveldb::leveldb)

list(APPEND TARGET_LIBRARIES pthread)
message(STATUS "TARGET_LIBRARIES=${TARGET_LIBRARIES}")

# target
ADD_EXECUTABLE(main src/main.cpp)
TARGET_LINK_LIBRARIES(main PRIVATE ${TARGET_LIBRARIES})
