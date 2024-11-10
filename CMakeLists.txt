cmake_minimum_required(VERSION 3.0.0)
project(main)

set(SourceFiles
    main.cpp
    heightmap.cpp
    )

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(GDAL REQUIRED)
include_directories(${GDAL_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SourceFiles})

target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES} ${GDAL_LIBRARIES})

