#include "Camera.h"

float Camera::fov = 60.0f;
glm::vec3 Camera::cameraPosition = glm::vec3(0.0f, 0.0f, 0.0f);
glm::vec3 Camera::cameraTarget = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 Camera::cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

Camera::Camera()
{
}

Camera::Camera(glm::vec3 cP, glm::vec3 cT, glm::vec3 cU, float fov)
{
	this->cameraPosition = cP;	// Camera position
	this->cameraTarget = cT;	// Camera target (center of the scene)
	this->cameraUp = cU;		// Up vector;
	this->fov = fov;
}