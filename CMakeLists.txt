cmake_minimum_required(VERSION 3.6)

project(temp_cam)

set(WORD_SZ x86)
set(SUFFIX )

add_library(i3system SHARED IMPORTED)
set_target_properties(i3system PROPERTIES
    IMPORTED_IMPLIB ${PROJECT_SOURCE_DIR}/sdk/lib/${WORD_SZ}/i3system_TE${SUFFIX}.lib
    IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/sdk/bin/${WORD_SZ}/i3system_TE${SUFFIX}.dll)
target_include_directories(i3system INTERFACE sdk/include)

add_executable(temp_cam src/main.cc src/temp_cam.cc)
target_link_libraries(temp_cam PUBLIC i3system)

add_custom_command(TARGET temp_cam POST_BUILD        
    COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        "${PROJECT_SOURCE_DIR}/sdk/bin/${WORD_SZ}/i3system_TE${SUFFIX}.dll"
        "${PROJECT_SOURCE_DIR}/sdk/bin/${WORD_SZ}/i3system_imgproc_impl${SUFFIX}.dll"
        "${PROJECT_SOURCE_DIR}/sdk/bin/${WORD_SZ}/i3system_USB_DLL_V2_2${SUFFIX}.dll"
        "C:/Windows/SysWOW64/mfc100u.dll"
        "C:/Windows/SysWOW64/msvcp100.dll"
        "C:/Windows/SysWOW64/msvcr100.dll"
        $<TARGET_FILE_DIR:temp_cam>)