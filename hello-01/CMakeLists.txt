# 设置所需的最低CMake版本为3.5。
cmake_minimum_required(VERSION 3.5)

# 设置项目名称为"hello-01"，版本号为0.1，使用的编程语言为C++。
project(hello-01 VERSION 0.1 LANGUAGES CXX)

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

# 源文件列表
aux_source_directory(. PROJECT_SOURCES)

# 使用"qt_add_executable"来创建可执行文件。
qt_add_executable(${PROJECT_NAME}
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)
# 构建Qt应用程序时进行最后的可执行文件处理
qt_finalize_executable(${PROJECT_NAME})

# 头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR})

# 将Qt模块链接到目标可执行文件或动态库。
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# 设置目标可执行文件的属性，如MacOSX的Bundle标识符、版本号和短版本字符串，
# 以及在Windows下作为可执行文件运行。
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE )
