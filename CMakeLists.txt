cmake_minimum_required(VERSION 3.0.0)
project(matrixRenderer)

set(CMAKE_CXX_STANDARD 17)  # Set the C++ standard explicitly
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER g++)  # Use g++ to ensure correct C++ linking

set(SourceFiles
    main.cpp)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# Directly use `sdl2-config` for SDL2 linking flags
add_executable(${PROJECT_NAME} ${SourceFiles})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} stdc++)

# Alternatively, explicitly add SDL2 flags:
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} -lSDL2)
