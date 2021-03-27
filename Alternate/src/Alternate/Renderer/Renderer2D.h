#pragma once
#include "Renderer2D.h"

#include "Alternate/Renderer/Camera.h"

#include "Alternate/Renderer/Texture.h"

namespace Alternate
{
	class Renderer2D
	{
	public:
		static void Init();
		static void ShutDown();

		static void BeginScene(const OrthographicCamera& camera);
		static void EndScene();

		//Primitives
		static void DrawQuad(const glm::vec2& position, const float rotation, const glm::vec2& scale, const glm::vec4& color);
		static void DrawQuad(const glm::vec3& position, const float rotation, const glm::vec2& scale, const glm::vec4& color);
		static void DrawQuad(const glm::vec2& position, const float rotation, const glm::vec2& scale, const Ref<Texture2D>& texture);
		static void DrawQuad(const glm::vec3& position, const float rotation, const glm::vec2& scale, const Ref<Texture2D>& texture);
	};
}