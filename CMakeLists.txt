cmake_minimum_required(VERSION 3.27)
project(PROJ_wrapper_multiplatform)

set(CMAKE_CXX_STANDARD 17)

if(APPLE)
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11" CACHE STRING "macOS Deployment Target")
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(PLUGIN_FEATURE_STATIC_LIBRARY ON)

set(LINK_TYPE MODULE)
if(IOS)
    set(LINK_TYPE STATIC)
endif()
add_library(PROJ_wrapper_multiplatform ${LINK_TYPE}
        proj_wrapper.cpp
)

if(APPLE)
    set_target_properties(PROJ_wrapper_multiplatform PROPERTIES BUNDLE true)
    if(PLUGIN_EMBED_BITCODE)
        target_compile_options(PROJ_wrapper_multiplatform PRIVATE "-fembed-bitcode")
    endif()
elseif(WIN32)
    target_compile_definitions(
            PROJ_wrapper_multiplatform
            PRIVATE
            "DLL_EXPORT_MACRO=__declspec(dllexport)"
    )
endif()

find_package(PROJ CONFIG REQUIRED)
target_link_libraries(PROJ_wrapper_multiplatform PRIVATE PROJ::proj)