cmake_minimum_required(VERSION 2.4)
project (winter-rogue)
file(GLOB SOURCES "./*.cpp")
add_executable(winter-rogue ${SOURCES})
#install(TARGETS winter-rogue bin)

