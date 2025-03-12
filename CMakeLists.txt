cmake_minimum_required(VERSION 3.0.0)
project(game-of-life VERSION 0.0.0)

# include(CTest)
# enable_testing()

set(CMAKE_CXX_STANDARD 23)

include_directories(./include)

file(GLOB_RECURSE SRC_FILES ./src/*.cpp)

add_executable(${PROJECT_NAME} ${SRC_FILES})

# set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "E:/software/vcpkg/installed/x64-windows/share")

find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw OpenGL::GL)

if(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE glfw "-framework OpenGL")
endif()

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
