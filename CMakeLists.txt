cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
include(CMakePrintHelpers)
project( FILE_COMPRESS )

set( LIBRARY_NAME FILE_COMPRESS )

file(GLOB SRC_FILES
    "${CMAKE_CURRENT_LIST_DIR}/src/*"
)

add_executable(
    ${LIBRARY_NAME}
    ${SRC_FILES}
)

set_target_properties(
    ${LIBRARY_NAME}
    PROPERTIES
    CXX_STANDARD 17
    VS_CONFIGURATION_TYPE "Application"
    CMAKE_CONFIGURATION_TYPES "RelWithDebInfo"
    )

add_compile_definitions(NOMINMAX)