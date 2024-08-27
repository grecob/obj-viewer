// imGuiExample.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "UseImGui.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"


using namespace std;

int main()
{


	if (!glfwInit())
	{
		return 1;
	}
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

	GLFWwindow* window = glfwCreateWindow(1280, 720, "test", NULL, NULL);
	if (window == NULL)
	{
		return 1;
	}
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // enable vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		throw("Unabble to context to OpenGL");
	}

	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);


	UseImGui myimgui;

	myimgui.Init(window, glsl_version);
	while (!glfwWindowShouldClose(window)) {
		// check for clicks and events for window.
		glfwPollEvents();
		glClearColor(0.45f, 0.55f, 0.60f, 1.00f);

		glClear(GL_COLOR_BUFFER_BIT);
		myimgui.NewFrame();
		myimgui.Update();
		myimgui.Render();
		glfwSwapBuffers(window);
	}
	myimgui.Shutdown();

	return 0;
}