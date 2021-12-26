cmake_minimum_required(VERSION 3.0.0)
project(problem1)
find_package( OpenCV REQUIRED )

include_directories(include)

add_executable(problem1 main.cpp src/DataLoader.cpp src/FeatureExtractor.cpp src/Stabilizer.cpp)

target_link_libraries( problem1 ${OpenCV_LIBS}
        ${CMAKE_THREAD_LIBS_INIT})