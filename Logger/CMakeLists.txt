cmake_minimum_required (VERSION 3.5)
project (LOGGER)
set(CMAKE_CXX_STANDARD 17)
include_directories($(CMAKE_CURRENT_SOURCE_DIR)/include)

add_executable(AppLogger main.cpp)
target_link_libraries(AppLogger
    -pthread
)