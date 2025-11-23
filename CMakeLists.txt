cmake_minimum_required(VERSION 3.0)
project(Timestamp)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
include_directories(${PROJECT_SOURCE_DIR}/logsys/include)
aux_source_directory(${PROJECT_SOURCE_DIR}/logsys/src SRC_LOG)

add_executable(Timestamp Timestamp.cpp ${SRC_LOG})