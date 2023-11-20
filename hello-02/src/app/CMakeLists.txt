# include_directories(${PROJECT_SOURCE_DIR}/include)

# 源文件列表
aux_source_directory(. APP_SOURCES)

list(APPEND APP_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/mainwindow.h)

# 使用"qt_add_executable"来创建可执行文件。
qt_add_executable(${PROJECT_NAME}
    MANUAL_FINALIZATION
    ${APP_SOURCES}
    ${RESOURCE_FILES}
    ${QRC_FILES}
)
# 构建Qt应用程序时进行最后的可执行文件处理
qt_finalize_executable(${PROJECT_NAME})

# 头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# 将Qt模块链接到目标可执行文件或动态库。
target_link_libraries(${PROJECT_NAME} PRIVATE
    # ${person_lib_name}
    Qt${QT_VERSION_MAJOR}::Widgets
)

# 设置目标可执行文件的属性，如MacOSX的Bundle标识符、版本号和短版本字符串，
# 以及在Windows下作为可执行文件运行。
set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE TRUE )
