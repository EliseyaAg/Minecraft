#include "PhysicsEngine.hpp"
#include "../Game/GameObjects/Cube.hpp"
#include "../Player/Camera.hpp"
#include "../Game/Renderer/ChunkRenderer.hpp"

namespace Physics
{
	std::unordered_set<Player::Camera*> PhysicsEngine::m_dynamicObjects;

	void PhysicsEngine::init()
	{

	}

	void PhysicsEngine::shutdown()
	{
		m_dynamicObjects.clear();
	}

	void PhysicsEngine::update(const double delta)
	{
		for (auto& currentObject : m_dynamicObjects)
		{
			if (currentObject->getCurrentVelocity() != glm::vec3(0.f))
			{
				const auto newPosition = currentObject->get_camera_position()
					+ (currentObject->get_direction() * static_cast<float>(currentObject->getCurrentVelocity().x * delta / 100000000))
					+ (currentObject->get_right() * static_cast<float>(currentObject->getCurrentVelocity().y * delta / 100000000))
					+ (currentObject->get_up() * static_cast<float>(currentObject->getCurrentVelocity().z * delta / 100000000));
				const auto& colliders = currentObject->getColiders();
				if(!Renderer::ChunkRenderer::getObjectsInArea(newPosition - glm::vec3(0.5f, 1.f, 0.5f), newPosition + glm::vec3(0.5f, 1.f, -0.5f), newPosition + glm::vec3(-0.5f, 1.f, 0.5f)))
					currentObject->get_camera_position() = newPosition;
			}
		}
	}

	void PhysicsEngine::addDynamicGameObject(Player::Camera* pGameObject)
	{
		m_dynamicObjects.insert(std::move(pGameObject));
	}
}