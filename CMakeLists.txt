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


# --- NEW: Profiling Option ---
option(ENABLE_GPROF "Enable gprof profiling" OFF)

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

# --- NEW: Apply gprof flags if enabled ---
if(ENABLE_GPROF)
    message(STATUS "Gprof profiling enabled for ${PROJECT_NAME}")
    target_compile_options(${PROJECT_NAME} PRIVATE -pg)
    target_link_options(${PROJECT_NAME} PRIVATE -pg)
endif()


