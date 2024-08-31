#pragma once

#include <glm/glm.hpp>
#include <glad/glad.h>

class Camera {
public:
	Camera();
	Camera(glm::vec3 cP, glm::vec3 cT, glm::vec3 cU, static float fov);

	glm::vec3 getCameraPosition() { return this->cameraPosition; };
	glm::vec3 getcameraTarget() { return this->cameraTarget; };
	glm::vec3 getCameraUp() { return this->cameraUp; };

	void setCameraPosition(glm::vec3 cP) { this->cameraPosition = cP; };
	void setCameraTarget(glm::vec3 cT) { this->cameraTarget = cT; };
	void setCameraUp(glm::vec3 cU) { this->cameraUp = cU; };

	static float fov;

private:
	static glm::vec3 cameraPosition;
	static glm::vec3 cameraTarget;
	static glm::vec3 cameraUp;
};