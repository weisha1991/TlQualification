cmake_minimum_required(VERSION 3.0.0)

SET(FT_PATH "${CMAKE_SOURCE_DIR}")
SET(CODE_PATH "${CMAKE_SOURCE_DIR}/../code/")
SET(TOOLS_PATH "${CMAKE_SOURCE_DIR/tools/}")
SET(SUPPORT_FT_PATH "${CMAKE_SOURCE_DIR}/surpport-ft/")

MESSAGE("ft path: ${FT_PATH}")
MESSAGE("code path: ${CODE_PATH}")

project(FT)

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -o2 -std=c++0x" )

INCLUDE_DIRECTORIES(
    "${PROJECT_ROOT_PATH}/include/"
    "${CODE_PATH}/include/"
    "${TOOLS_PATH}/gtest/include/"
    "${SUPPORT_FT_PATH}/include/"
)   

file(GLOB SOURCES 
        "${CODE_PATH}/code/src/*.cpp"
        "${FT_PATH}/test-case/*.cpp"
        "${FT_PATH}/surpport-ft/*.cpp"
)

LINK_DIRECTORIES("${TOOLS_PATH}/gtest/lib/")

add_executable(FT ${SOURCES})

TARGET_LINK_LIBRARIES(FT gtest pthread)


