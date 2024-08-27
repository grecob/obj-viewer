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

void UseImGui::Update(){
	
	// render GUI
	ImGui::SetNextWindowPos({ 0,0 });
	float viewportSizeX = ImGui::GetMainViewport()->Size.x;
	float viewportSizeY = ImGui::GetMainViewport()->Size.y;

	ImGui::SetNextWindowSize({ viewportSizeX / 4, viewportSizeY });

	static float x = 0.0f;
	static float y = 0.0f;
	static float z = 0.0f;
	static int counter = 0;

	ImGui::Begin("Hello world!");
	
	ImGui::Text("camera position");
	ImGui::SliderFloat("x", &x, 0.0f, 1.0f);
	ImGui::SliderFloat("y", &y, 0.0f, 1.0f);
	ImGui::SliderFloat("z", &z, 0.0f, 1.0f);

	ImGui::Separator();
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

