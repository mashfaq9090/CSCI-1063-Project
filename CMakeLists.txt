# cmake_minimum_required(VERSION 3.10)
# project(CSCI_1063_Project)
# find_package(ftxui REQUIRED)
# add_executable(main src/main.cpp)
# target_link_libraries(main
#   PRIVATE ftxui::screen
#   PRIVATE ftxui::dom
#   PRIVATE ftxui::component
# )


cmake_minimum_required(VERSION 3.16)

project(
    ftxui_app
    VERSION 0.1.0
    LANGUAGES CXX
)

# ──────────────────────────────────────────────────────────────
# C++ Standard
# ──────────────────────────────────────────────────────────────
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ──────────────────────────────────────────────────────────────
# Dependencies
# ──────────────────────────────────────────────────────────────
find_package(ftxui REQUIRED)

# ──────────────────────────────────────────────────────────────
# Executable
# ──────────────────────────────────────────────────────────────
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/core.cpp
    src/ui.cpp
    src/utils.cpp
)

# ──────────────────────────────────────────────────────────────
# Include paths
# ──────────────────────────────────────────────────────────────
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
)

# ──────────────────────────────────────────────────────────────
# Link libraries
# ──────────────────────────────────────────────────────────────
target_link_libraries(${PROJECT_NAME}
    PRIVATE
        ftxui::screen
        ftxui::dom
        ftxui::component
)



# ──────────────────────────────────────────────────────────────
# Compiler warnings (safe defaults)
# ──────────────────────────────────────────────────────────────
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -Wall
        -Wextra
        -Wpedantic
)