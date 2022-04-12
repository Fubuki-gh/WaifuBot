# Minimum Cmake version required
cmake_minimum_required(VERSION 3.15)
# Project name, version and description
project(WaifuBot VERSION 1.0 DESCRIPTION "WaifuBot")

# Add DPP as dependency
add_subdirectory(libs/DPP)
add_subdirectory(libs/spdlog)
# in the `libs/` directory
 
# Create an executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/waifubot.cpp
)
 
# Linking libraries
target_link_libraries(${PROJECT_NAME}
    dpp
    spdlog
)
 
# Specify includes
target_include_directories(${PROJECT_NAME} PRIVATE
    libs/DPP/include
    libs/spdlog/include
    header/
    
)

# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)