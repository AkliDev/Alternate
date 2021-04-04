#include "Sandbox2D.h"

#include <imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CamaraController(1280.0f / 720.0f, true)
{
}

void Sandbox2D::OnAttach()
{
	ALT_PROFILE_FUNCTION();
	m_CheckerBoardTexture = Alternate::Texture2D::Create("assets/textures/Test.png");
	m_TransparantTexture = Alternate::Texture2D::Create("assets/textures/Goombah.png");
}

void Sandbox2D::OnDetach()
{
	ALT_PROFILE_FUNCTION();
}

void Sandbox2D::OnUpdate(Alternate::Timestep ts)
{
	ALT_PROFILE_FUNCTION();

	m_CamaraController.OnUpdate(ts);

	Alternate::Renderer2D::ResetStats();
	{
		ALT_PROFILE_SCOPE("Render Prep");
		Alternate::RenderCommand::SetClearColor({ 0.1, 0.1, 0.1, 1 });
		Alternate::RenderCommand::Clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 500.0f;
		ALT_PROFILE_SCOPE("Render Draw");
		Alternate::Renderer2D::BeginScene(m_CamaraController.GetCamera());
		Alternate::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerBoardTexture, 10.0f);
		Alternate::Renderer2D::DrawRotatedQuad({ 0.0f, -2.0f , 0.2f }, { 1.0f, 1.5f }, glm::radians(45.0f), m_Square2Color);
		Alternate::Renderer2D::DrawRotatedQuad({ 0.0f, 0.0f , 0.2f }, { 2.0f, 0.5f }, glm::radians(20.0f), m_SquareColor);
		Alternate::Renderer2D::DrawRotatedQuad({ 2.0f, 2.5f, 0.2f }, { 3.0f, 3.0f }, glm::radians(rotation), m_TransparantTexture);
		Alternate::Renderer2D::DrawRotatedQuad({ -2.0f, 2.5f , 0.2f }, { 3.0f, 3.0f }, glm::radians(-rotation), m_TransparantTexture);
		Alternate::Renderer2D::EndScene();

		Alternate::Renderer2D::BeginScene(m_CamaraController.GetCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10, 0.4f, (y + 5.0f) / 10, 0.75f };
				Alternate::Renderer2D::DrawQuad({ x, y , 0.1f }, { 0.45f, 0.45f }, color);
			}
		}
		Alternate::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	ALT_PROFILE_FUNCTION();

	ImGui::Begin("Settings");

	auto stats = Alternate::Renderer2D::GetStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quad Count: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.GetTotalVertexCount());
	ImGui::Text("Indices: %d", stats.GetTotalIndexCount());


	ImGui::ColorEdit4("Square Color2D", glm::value_ptr(m_SquareColor));
	ImGui::ColorEdit4("Square2 Color2D", glm::value_ptr(m_Square2Color));
	ImGui::End();
}

void Sandbox2D::OnEvent(Alternate::Event& e)
{
	m_CamaraController.OnEvent(e);
}