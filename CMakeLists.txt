cmake_minimum_required(VERSION 3.27)

project(AdventOfCode2023)
set(CMAKE_CXX_STANDARD 17)

# Yes, I know, not pretty... but useful!
function(add_day DAY_FOLDER)
    add_executable(${DAY_FOLDER}_part01 ${DAY_FOLDER}/part01.cpp)
    add_executable(${DAY_FOLDER}_part02 ${DAY_FOLDER}/part02.cpp)

    configure_file(${DAY_FOLDER}/${DAY_FOLDER}.txt ${CMAKE_BINARY_DIR}/${DAY_FOLDER}.txt COPYONLY)
endfunction()

add_day(day01)
add_day(day02)
add_day(day03)
