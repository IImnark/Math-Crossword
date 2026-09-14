cmake_minimum_required(VERSION 3.20)
project(SDL2_template)

set(CMAKE_CXX_STANDARD 20)

# Path to your SDL2 root folder
set(SDL2_PATH "C:/SDL2")

add_executable(SDL2_template main.cpp)

# Point the compiler at the SDL headers
target_include_directories(SDL2_template PRIVATE
        "${SDL2_PATH}/include/SDL2"
)

# Point the linker at the SDL libraries
target_link_directories(SDL2_template PRIVATE
        "${SDL2_PATH}/lib"
)

# Link order matters on MinGW — keep this order
target_link_libraries(SDL2_template PRIVATE
        mingw32
        SDL2main
        SDL2
        SDL2_image
        SDL2_ttf
)

# Copy DLLs next to the executable so it can run
if (WIN32)
    add_custom_command(TARGET SDL2_template POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${SDL2_PATH}/bin/SDL2.dll"
            "${SDL2_PATH}/bin/SDL2_image.dll"
            "${SDL2_PATH}/bin/SDL2_ttf.dll"
            $<TARGET_FILE_DIR:SDL2_template>
    )
endif()