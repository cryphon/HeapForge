cmake_minimum_required(VERSION 3.10)
project(HeapForge VERSION 1.0.0 LANGUAGES C)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


set(MAIN_SOURCE_FILES
    ${SRC_DIR}/bump_alloc.c
)

add_library(allocators STATIC ${MAIN_SOURCE_FILES})

target_include_directories(allocators PUBLIC include)

add_executable(example example/main.c)
target_link_libraries(example PRIVATE allocators)

add_custom_target(run
    COMMAND example
    DEPENDS example
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    COMMENT "Build and run example"
)
