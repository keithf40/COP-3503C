cmake_minimum_required(VERSION 3.16)
project(keith-l-project3 LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_PROGRESS    TRUE
    GIT_SHALLOW     TRUE
    GIT_TAG 2.6.x)

FetchContent_MakeAvailable(SFML)

# 28NOV23 MB
# For Debian, SFML also needs:
# 1. libudev-dev
# 2. libopenal-dev
# 3. libvorbis-dev
# 4. libflac-dev
# 30NOV23 MB
# Further dependencies for Debian are mentioned here:
# https://www.sfml-dev.org/tutorials/2.6/start-cmake.php

file(COPY config.cfg DESTINATION ${PROJECT_BINARY_DIR}/bin)
file(COPY images DESTINATION ${PROJECT_BINARY_DIR}/bin)
file(COPY boards DESTINATION ${PROJECT_BINARY_DIR}/bin)

# 30NOV23 MB - Just incase we want these we want these files elsewhere.  Experimental
#file(CREATE_LINK ${PROJECT_BINARY_DIR}/bin/config.cfg ${PROJECT_BINARY_DIR}/config.cfg SYMBOLIC)

add_executable(${PROJECT_NAME}
    Board.cpp
    main.cpp
    Random.cpp
    TextureManager.cpp
    Tile.cpp)

# 30NOV23 MB
# sfml_add_library would indicate SFML::Graphics is available (which I prefer)
# but no such luck
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS ${PROJECT_NAME})
