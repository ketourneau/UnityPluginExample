cmake_minimum_required(VERSION 3.15)

project(
    UnityPluginExample
    VERSION 0.0.1
    DESCRIPTION "Unity plugin wrapper example"
)

include(CMakeDependentOption)

if(APPLE)
    # Signing
    set(XCODE_CODE_SIGN_IDENTITY "Development" CACHE STRING "Xcode code sign ID")
    set(XCODE_DEVELOPMENT_TEAM "" CACHE STRING "Xcode development team ID")
    # Deployment
    set(CMAKE_OSX_DEPLOYMENT_TARGET "10.11" CACHE STRING "macOS Deployment Target")
    if(IOS)
        set(CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "11.0" CACHE STRING "iOS Deployment Target")
    endif()
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(PLUGIN_FEATURE_STATIC_LIBRARY ON)

set(UNITY_TYPE MODULE)
if(IOS OR EMSCRIPTEN)
    set(UNITY_TYPE STATIC)
endif()

add_library(plugin_unity ${UNITY_TYPE}
    src/example_c_binding.cpp
    )

target_link_libraries(plugin_unity)

if(APPLE)
    set_target_properties(plugin_unity PROPERTIES BUNDLE true)
    if(PLUGIN_EMBED_BITCODE)
        target_compile_options(plugin_unity PRIVATE "-fembed-bitcode")
    endif()
elseif(WIN32)
    target_compile_definitions(
        plugin_unity
    PRIVATE 
        "EXAMPLE_UNITY_API=__declspec(dllexport)"
    )
endif()
