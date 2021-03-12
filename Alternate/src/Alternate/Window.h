#pragma once

#include "altpch.h"

#include "Alternate/Core.h"
#include "Alternate/Events/Event.h"

namespace Alternate
{
	struct WindowProps
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowProps(const std::string& title = "Alternate Engine",
			uint32_t width = 800,
			uint32_t height = 600)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	//// Interface representing a desktop system based Window
	//class ALTERNATE_API  Window
	//{
	//public:
	//	using EventCallbackFn = std::function<void(Event&)>;

	//	virtual ~Window() = default;

	//	virtual void OnUpdate() = 0;

	//	virtual uint32_t GetWidth() const = 0;
	//	virtual uint32_t GetHeight() const = 0;

	//	// Window attributes
	//	virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
	//	virtual void SetVSync(bool enabled) = 0;
	//	virtual bool IsVSync() const = 0;

	//	virtual void* GetNativeWindow() const = 0;

	//	static Window* Create(const WindowProps& props = WindowProps());
	//}; 
	//
	//struct WindowProps
	//{
	//	std::string Title;
	//	uint32_t Width;
	//	uint32_t Height;

	//	WindowProps(const std::string& title = "Hazel Engine",
	//		uint32_t width = 1600,
	//		uint32_t height = 900)
	//		: Title(title), Width(width), Height(height)
	//	{
	//	}
	//};

	// Interface representing a desktop system based Window
	class ALTERNATE_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;
		virtual void* GetGLContext() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
