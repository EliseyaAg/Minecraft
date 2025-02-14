#pragma once

#include "VertexArray.hpp"
#include "IndexBuffer.hpp"
#include "ShaderProgram.hpp"

namespace RenderEngine {
	class Renderer
	{
	public:
		static void draw(const VertexArray& vertexArray, const IndexBuffer& indexBuffer, const ShaderProgram& shader);
		static void setClearColor(float r, float g, float b, float a);
		static void clear();
		static void setDepth(const bool enable);
		static void setViewport(unsigned int width, unsigned int height, unsigned int leftOffset = 0, unsigned int BottomOffset = 0);
	};
}