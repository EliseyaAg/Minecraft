#pragma once
#include "../GameObjects/Chunk.hpp"
#include "../GameObjects/Cube.hpp"
#include "../../Resources/ResourceManager.hpp"
#include "glm/vec2.hpp"

#include <memory>
#include <vector>

namespace Renderer
{
	class ChunkRenderer
	{
	public:
		static void setTextureAtlas(std::shared_ptr<RenderEngine::Texture2D> pTexture);
		static void setShaderProgram(std::shared_ptr<RenderEngine::ShaderProgram> pShaderProgram);

		~ChunkRenderer() = delete;
		ChunkRenderer() = delete;
		ChunkRenderer(const ChunkRenderer&) = delete;
		ChunkRenderer(ChunkRenderer&&) = delete;
		ChunkRenderer& operator=(const ChunkRenderer&) = delete;
		ChunkRenderer& operator=(ChunkRenderer&&) = delete;

		static void render(const glm::vec3& camera_position, const glm::vec3& camera_rotation);
		static void generate_world(const int u, const int v);
		static void unload_world();
		static void saveworld();
		static void loadworld();

		static void generate_seed();
		static void update_world();

		static bool getObjectsInArea(const glm::vec3& BottomLeftFront, const glm::vec3& TopRightFront, const glm::vec3& TopLeftBack);
		static glm::vec3 getObjectsInArea() { return chunk->getObjectsInArea(); };

		static void deleteBlock(const glm::vec3& coords);
		static void placeBlock(const glm::vec3& coords, const std::string& type);

		static void update_blocks(std::pair<std::string, glm::vec3>);

	private:
		static std::vector<std::vector<Game::Chunk::s_blocks_polygones>> m_blocks_polygones;
		static std::vector<glm::vec2> chunks_coords;
		static std::unique_ptr<Game::Chunk> chunk;
		static std::vector<std::vector<std::string>> m_blocks;

		static std::shared_ptr<RenderEngine::Texture2D> m_pTexture;

		static unsigned long long int SEED;
	};
}