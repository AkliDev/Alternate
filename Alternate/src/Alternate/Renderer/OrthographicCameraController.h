#pragma once
#include "Alternate/Renderer/Camera.h"
#include "Alternate/Core/Timestep.h"

#include "Alternate/Events/ApplicationEvent.h"
#include "Alternate/Events/MouseEvent.h"

namespace Alternate
{
	struct OrthographicCameraBounds
	{
		float Left, Right;
		float Bottom, Top;

		float GetWidth() { return Right - Left; }
		float GetHeight() { return Top - Bottom; }
	};

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void OnUpdate(Timestep ts);
		void OnEvent(Event& e);

		OrthographicCamera& GetCamera() { return m_Camera; }
		const OrthographicCamera& GetCamera() const { return m_Camera; }

		float GetZoomLevel() const { return m_ZoomLevel; }
		void SetZoomLevel(float level) { m_ZoomLevel = level; CalculateView(); }

		const OrthographicCameraBounds& GetBounds() const { return m_Bounds; }
	private:
		void CalculateView();

		bool OnMouseScrollEvent(MouseScrolledEvent& e);
		bool OnWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		OrthographicCameraBounds m_Bounds;
		OrthographicCamera m_Camera;

		bool m_Rotation = false;

		glm::vec3 m_CameraPostion = { 0.0f , 0.0f , 0.0f };
		float m_CameraRotation = 0.0f;

		float m_CameraTranslationSpeed = 5.0;
		float m_CameraRotationSpeed = 180.0;;
	};
}