# CMakeList.txt : CMake project for imGuiExample, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (main "main.cpp"  "UseImGui.cpp" "UseImGui.h" "BasicMesh.cpp" "BasicMesh.h" "shader.h" "shader.cpp" "Model.h" "Model.cpp")

find_package(glad CONFIG REQUIRED)
target_link_libraries(main PRIVATE glad::glad)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(main PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(main PRIVATE glm::glm)

find_package(imgui CONFIG REQUIRED)
target_link_libraries(main PRIVATE imgui::imgui)

find_package(assimp CONFIG REQUIRED)
target_link_libraries(main PRIVATE assimp::assimp)

# TODO: Add tests and install targets if needed.

