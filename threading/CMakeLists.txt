cmake_minimum_required(VERSION 3.0)
project(threading)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99 -fopenmp -lpthread")

set(SOURCE_FILES_MC moncarlo.cpp)
add_executable(monte_carlo_pi ${SOURCE_FILES_MC})

set(SOURCE_FILES_LP loop.cpp)
add_executable(loop ${SOURCE_FILES_LP})

set(SOURCE_FILES_LP pthread_test.cpp)
add_executable(pthread_test ${SOURCE_FILES_LP})

set(SOURCE_FILES_RC race.cpp)
add_executable(race ${SOURCE_FILES_RC})

set(SOURCE_FILES_RW rw.cpp)
add_executable(rw ${SOURCE_FILES_RW})

