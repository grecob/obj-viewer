# CMakeList.txt : CMake project for imGuiExample, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (imGuiExample "imGuiExample.cpp"  "UseImGui.cpp" "UseImGui.h" "BasicMesh.cpp")

find_package(glad CONFIG REQUIRED)
target_link_libraries(imGuiExample PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(imGuiExample PRIVATE glfw)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(imGuiExample PRIVATE imgui::imgui)

find_package(assimp CONFIG REQUIRED)
target_link_libraries(imGuiExample PRIVATE assimp::assimp)
# TODO: Add tests and install targets if needed.

