cmake_minimum_required(VERSION 3.15)
project(RansomCLION)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(RansomCLION test.cpp aes_decrypt.cpp aes_encrypt.cpp utils.cpp)
