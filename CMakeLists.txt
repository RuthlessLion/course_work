cmake_minimum_required(VERSION 3.6)
project(course_work)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(course_work ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} -lsfml-graphics -lsfml-window -lsfml-system)