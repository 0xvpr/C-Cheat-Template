cmake_minimum_required(VERSION 3.8.0)

# Enable languages
enable_language(C)
enable_language(ASM_MASM)

# Project name
project("Payload")
set(TARGET Payload)

# Set language standards
set(CMAKE_C_STANDARD 99)

# Output path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

# Setup Directx
include_directories(${TARGET} "C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Include")

# Include directories
include_directories(${TARGET} include)
set(INCLUDE_DIR include)

# Source directories
set(SOURCE_DIR source)
set(ASM_DIR ${SOURCE_DIR}/assembly)

# Add sources
set(SOURCES 
    # CXX Sources
    ${SOURCE_DIR}/d3d9hook.c
    ${SOURCE_DIR}/drawing.c
    ${SOURCE_DIR}/events.c
    ${SOURCE_DIR}/hacks.c
    ${SOURCE_DIR}/main.c
    ${SOURCE_DIR}/mem.c
    ${SOURCE_DIR}/render.c
    # Includes
    ${INCLUDE_DIR}/d3d9hook.h
    ${INCLUDE_DIR}/drawing.h
    ${INCLUDE_DIR}/entity.h
    ${INCLUDE_DIR}/events.h
    ${INCLUDE_DIR}/hacks.h
    ${INCLUDE_DIR}/mem.h
    ${INCLUDE_DIR}/offsets.h
    ${INCLUDE_DIR}/render.h
    # Assembly Sources
    #${INCLUDE_DIR}/assembly.h
    #${ASM_DIR}/foo.asm
)

# Build dynamic load library
add_library(${TARGET} SHARED ${SOURCES})
set_target_properties(
    ${TARGET}
    PROPERTIES
    OUTPUT_NAME ${TARGET}
    PREFIX ""
    SUFFIX ".dll"
)

# Setup Directx Libs
target_link_directories(${TARGET} PUBLIC "C:\\Program Files (x86)\\Microsoft DirectX SDK (June 2010)\\Lib\\x86")
target_link_libraries(${TARGET} d3d9 d3dx9)
