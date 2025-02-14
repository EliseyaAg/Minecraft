#pragma once
#include "glm/vec2.hpp"
#include "Block.hpp"
#include <vector>
#include <string>

namespace RenderEngine
{
	class ShaderProgram;
	class Texture2D;
}

namespace Game
{
	class Chunk
	{
	public:
		Chunk(std::shared_ptr<RenderEngine::Texture2D> pTexture);

		void render(const glm::vec3& camera_position);
		void update(const uint64_t delta);

		static struct s_blocks_polygones { bool m_blocks_polygones[6]; };
		std::vector<s_blocks_polygones> m_blocks_polygones;

		void setPosition(glm::vec2 position);
		void setBlocksPolygones(std::vector<s_blocks_polygones> m_blocks_polygones);
		void setBlocksPositions(std::vector<std::string> blocks);

		bool getObjectsInArea(const glm::vec3& BottomLeftFront, const glm::vec3& TopRightFront, const glm::vec3& TopLeftBack);
		glm::vec3 getObjectsInArea() { return block_position_colide; };
	private:
		glm::vec2 m_position;
		std::shared_ptr<Block> block;
		std::vector<std::string> m_blocks;

		std::shared_ptr<RenderEngine::Texture2D> m_pTexture;

		glm::vec3 block_position_colide;
	};
}