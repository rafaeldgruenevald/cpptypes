cmake_minimum_required(VERSION 3.20)

project(cpptypes
    VERSION 0.1.0
    LANGUAGES CXX
)

# --------------------------------------------------
# Cross-compilation (MinGW para Windows)
# --------------------------------------------------

if(MINGW)
    # Linka o runtime estaticamente: gera um .exe sem depender de DLLs
    set(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} -static -static-libgcc -static-libstdc++")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# --------------------------------------------------
# Compiler flags
# --------------------------------------------------

if (MSVC)
    add_compile_options(/W4 /permissive-)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

# --------------------------------------------------
# Dependencies
# --------------------------------------------------

# Catch2 so e necessario para os testes (build nativo).
# Em cross-compilation, pulamos os testes e evitamos a dependencia.
if(NOT CMAKE_CROSSCOMPILING)
    find_package(Catch2 3 REQUIRED)
endif()

# --------------------------------------------------
# Game library
# --------------------------------------------------

file(GLOB_RECURSE CPPTYPES_SOURCES
    CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Lists/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Graphs/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Trees/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Hashes/*.cpp
)

add_library(cpptypes_lib
    ${CPPTYPES_SOURCES}
)

target_include_directories(cpptypes_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# --------------------------------------------------
# Tests (apenas em build nativo)
# --------------------------------------------------

# Em cross-compilacao, encerramos aqui: nada de Catch2, CTest ou test_*.cpp.
if(CMAKE_CROSSCOMPILING)
    message(STATUS "Cross-compilando para ${CMAKE_SYSTEM_NAME}: pulando testes")
    return()
endif()

include(CTest)
enable_testing()

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_*.cpp
)

add_executable(cpptypes_tests
    ${TEST_SOURCES}
)

target_link_libraries(cpptypes_tests
    PRIVATE
        cpptypes_lib
        Catch2::Catch2WithMain
)

target_include_directories(cpptypes_tests
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)

include(Catch)
catch_discover_tests(cpptypes_tests
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
