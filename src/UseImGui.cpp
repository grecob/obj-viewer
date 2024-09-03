#include "UseImGui.h"

#include <iostream>

void UseImGui::Init(GLFWwindow* window, const char* glsl_version){
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	// render and platform specific bindings
	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init(glsl_version);
	ImGui::StyleColorsDark();
	
}

void UseImGui::NewFrame()
{
	// feed inputs to imgui, start a new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void UseImGui::Update(Camera* camera, Shader* shader){
	
	// render GUI
	ImGui::SetNextWindowPos({ 0,0 });
	float viewportSizeX = ImGui::GetMainViewport()->Size.x;
	float viewportSizeY = ImGui::GetMainViewport()->Size.y;

	ImGui::SetNextWindowSize({ viewportSizeX / 4, viewportSizeY });

	//static glm::vec3 camera(0.0, 0.0, 5.0);
	//static float fov = 60.0f;

	ImGui::Begin("Hello world!");
	
	ImGui::Text("camera position");
	float& fov = camera->fov;
	glm::vec3 cameraPos = camera->getCameraPosition();

	ImGui::SliderFloat("fov", &fov, 50.0, 120.0f);
	ImGui::SliderFloat3("Camera Position", &cameraPos[0], -20.0f, 20.0f);

	camera->fov = fov;
	camera->setCameraPosition(cameraPos);

	ImGui::Separator();

	// lighting
	static glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
	static glm::vec3 lightColor(1.0f, 1.0f, 1.0f);

	shader->setVec3("objectColor", 1.0f, 0.5f, 0.31f);
	shader->setVec3("lightColor", 1.0f, 1.0f, 1.0f);

	ImGui::SliderFloat3("color",  , 0.0f, 1.0f);


	
	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	

	ImGui::End();


}

void UseImGui::Render(){
	// Render imgui onto the screen
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void UseImGui::Shutdown(){
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

