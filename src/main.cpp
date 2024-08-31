// imGuiExample.cpp : Defines the entry point for the application.
//

#include <iostream>
#include "UseImGui.h"
#include "Model.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Camera.h"


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
		throw("Unable to context to OpenGL");
	}

	glEnable(GL_DEPTH_TEST);
	Shader myShader("N:/VSCode/side-projects/imGuiExample/1.model_loading.vs", "N:/VSCode/side-projects/imGuiExample/1.model_loading.fs");
	// flip textures on load
	Model myModel("N:/VSCode/side-projects/imGuiExample/cube.obj");


	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);


	UseImGui myimgui;
	Camera* camera;
	camera = new Camera();

	myimgui.Init(window, glsl_version);
	while (!glfwWindowShouldClose(window)) {
		// check for clicks and events for window.
		glClearColor(0.45f, 0.55f, 0.60f, 1.00f);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		myimgui.NewFrame();
		myimgui.Update(camera);
		myimgui.Render();

		myShader.use();

		// render model
		glm::mat4 projection = glm::perspective(glm::radians(camera->fov), (float)screen_width / (float)screen_height, 0.1f, 100.0f);

		glm::mat4 view = glm::lookAt( camera->getCameraPosition(), camera->getcameraTarget(), camera->getCameraUp() );

		myShader.setMat4("projection", projection);
		myShader.setMat4("view", view);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, glm::vec3(0.0f, 0.0f, 0.0f)); // translate it down so it's at the center of the scene
		model = glm::scale(model, glm::vec3(0.25f, 0.25f, 0.25f));	// it's a bit too big for our scene, so scale it down
		myShader.setMat4("model", model);
		myModel.Draw(myShader);


		glfwSwapBuffers(window);
		glfwPollEvents();

		
	}

	delete camera;
	myimgui.Shutdown();

	return 0;
}