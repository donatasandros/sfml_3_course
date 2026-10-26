cmake_minimum_required(VERSION 3.28)

project(SFMLGame LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.1.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM
)

FetchContent_MakeAvailable(SFML)

add_executable(SFMLGame
    src/main.cpp
 "src/Square.hpp" "src/Square.cpp" "src/Game..cpp" "src/Engine.cpp")

target_compile_features(SFMLGame PRIVATE cxx_std_17)

target_link_libraries(SFMLGame
    PRIVATE SFML::Graphics
)