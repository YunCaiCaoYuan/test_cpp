cmake_minimum_required(VERSION 3.23)
project(test_cpp)

set(CMAKE_CXX_STANDARD 14)


#AUX_SOURCE_DIRECTORY(facade SRC_LIST2)
#ADD_EXECUTABLE(facade ${SRC_LIST2})


AUX_SOURCE_DIRECTORY(virtual_func SRC_LIST2)
ADD_EXECUTABLE(virtual_func ${SRC_LIST2})
