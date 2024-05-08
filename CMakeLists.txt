cmake_minimum_required(VERSION 3.29.0)
project(KonwledgePoints)

#设置C++标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#允许测试
#enable_testing()

#设置变量
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin) #可执行文件输出目录
set(LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin) #动静态库输出目录

#包含子目录 子目录中的CMakeLists.txt也是会用到父目录中的变量的
add_subdirectory(src)
#add_subdirectory(src/ClassesAndObjects) 可以直接这样 包含src只是为了更方便而已
#add_subdirectory(test/PointTest)
#add_subdirectory(test/ClassTest)
