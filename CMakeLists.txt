cmake_minimum_required(VERSION 3.15)
project(FileBlockList LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# source files
set(SOURCES
    FileBlockList.cpp
    Hasher.cpp
    Blocklist.cpp
    Logger.cpp
    Scanner.cpp
    Monitor.cpp
)

add_executable(FileBlockList ${SOURCES})

# Link libraries if needed (none required for this simple project)

# Set warning level and multithreaded runtime if desired
if (MSVC)
    target_compile_options(FileBlockList PRIVATE /W4 /permissive-)
endif()
