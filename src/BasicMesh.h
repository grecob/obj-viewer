
#pragma once

#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/mesh.h>
#include "Vertex.h"
#include "Texture.h"
#include "shader.h"

#include <glad/glad.h>
#include <glm/vec3.hpp>
#include <vector>

class BasicMesh
{
public:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	BasicMesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Texture> textures);
	
	void Draw(Shader &shader);
private:
	//#define INVALID_MATERIAL 0xFFFFFFFF
	unsigned int VAO, VBO, EBO;

	void InitMesh();
	

};