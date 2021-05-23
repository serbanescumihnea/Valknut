cmake_minimum_required(VERSION 3.15)
project(RansomCLION)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -DCURL_STATICLIB")

set(libcurl_INCLUDE_DIR "C:/Users/serba/Downloads/curl-7.76.1_2-win32-mingw/curl-7.76.1-win32-mingw/include")
include_directories(${libcurl_INCLUDE_DIR})


set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(RansomCLION test.cpp aes_decrypt.cpp aes_encrypt.cpp utils.cpp)
target_link_libraries(RansomCLION C:/Users/serba/Downloads/curl-7.76.1_2-win32-mingw/curl-7.76.1-win32-mingw/lib/libcurl.dll.a)
