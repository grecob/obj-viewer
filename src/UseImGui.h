#pragma once

#include <ImGui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <glm/glm.hpp>
#include "Camera.h"

class UseImGui
{
public:
	void Init(GLFWwindow* window, const char* glsl_version);
	void NewFrame();
	virtual void Update(Camera* camera);
	void Render();
	void Shutdown();


private:
	static glm::vec3 cameraPosition;// Camera position
	static glm::vec3 cameraTarget;	// Camera target (center of the scene)
	static glm::vec3 cameraUp;		// camera up vector
};