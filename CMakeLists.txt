cmake_minimum_required(VERSION 3.20)

project(MyGame LANGUAGES CXX)

add_executable(MyGame
    main.cpp
)

target_compile_features(MyGame PRIVATE cxx_std_20)

target_include_directories(MyGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL_image/include
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/SDL_ttf/include
)

target_link_libraries(MyGame PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/Build/vendor/SDL/Debug/SDL3.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/Build/vendor/SDL_image/Debug/SDL3_image.lib
    ${CMAKE_CURRENT_SOURCE_DIR}/Build/vendor/SDL_ttf/Debug/SDL3_ttf.lib
)