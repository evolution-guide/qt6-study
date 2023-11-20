
aux_source_directory(. PERSON_SOURCES)
list(APPEND PERSON_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/person.h)

qt_add_library(${person_lib_name} SHARED
    ${PERSON_SOURCES}
)

target_link_libraries(${person_lib_name} PRIVATE Qt6::Core)
target_include_directories(${person_lib_name} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
