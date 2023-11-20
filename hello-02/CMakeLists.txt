# 设置所需的最低CMake版本为3.5。
cmake_minimum_required(VERSION 3.5)

# 设置项目名称为"helloqt_multi"，版本号为0.1，使用的编程语言为C++。
project(helloqt_multi VERSION 0.1 LANGUAGES CXX)

# 启用自动UI编译
set(CMAKE_AUTOUIC ON)
# 自动元对象编译
set(CMAKE_AUTOMOC ON)
# 自动资源编译
set(CMAKE_AUTORCC ON)

# 设置C++标准为C++17，并要求编译器支持此标准。
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# CMake尝试查找并加载Qt6，同时CMake将要求加载Widgets模块
find_package(QT NAMES Qt6 REQUIRED COMPONENTS Widgets)
# 根据第一个find_package函数中找到的QT版本来引用具体的模块
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

# 图标资源文件
set(RESOURCE_FILES ${PROJECT_SOURCE_DIR}/resources.rc)

# 其他资源文件
set(QRC_FILES ${PROJECT_SOURCE_DIR}/res.qrc)

set(person_lib_name person)

add_subdirectory(src)
