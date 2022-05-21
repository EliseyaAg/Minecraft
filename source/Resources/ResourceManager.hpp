#pragma once

#include <string>
#include <memory>
#include <map>

#include <Renderer/ShaderProgram.hpp>
#include <Renderer/Texture2D.hpp>

namespace Game {
	class ResourceManager {
	public:
		ResourceManager(const std::string& executablePath);
		~ResourceManager() = default;

		ResourceManager(const ResourceManager&) = delete;
		ResourceManager(ResourceManager&&) = delete;
		ResourceManager& operator=(const ResourceManager&) = delete;
		ResourceManager& operator=(ResourceManager&&) = delete;

		std::shared_ptr<ShaderProgram> loadShader(const std::string& shaderName, const std::string& vertexPath, const std::string& fragmentPath);
		std::shared_ptr<ShaderProgram> getShader(const std::string& shaderName);
		std::shared_ptr<Texture2D> loadTexture(const std::string& textureName, const std::string& texturePath);
		std::shared_ptr<Texture2D> getTexture(const std::string& textureName);

	private:
		std::string getFileString(const std::string& relativeFilePath);

		typedef std::map<const std::string, std::shared_ptr<ShaderProgram>> ShaderProgramsMap;
		ShaderProgramsMap m_shaderPrograms;

		typedef std::map<const std::string, std::shared_ptr<Texture2D>> TexturesMap;
		TexturesMap m_textures;

		std::string m_path;
	};
}