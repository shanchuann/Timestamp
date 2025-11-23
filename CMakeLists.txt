cmake_minimum_required(VERSION 3.10)
project(Timestamp)

# 添加以下代码解决 C4819 警告
if(MSVC)
    add_compile_options(/utf-8)
endif()

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include_directories(${PROJECT_SOURCE_DIR}/logsys/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/logsys/src SRC_LOG)

add_executable(Timestamp Timestamp.cpp ${SRC_LOG})