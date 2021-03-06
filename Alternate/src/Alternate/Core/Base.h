#pragma once
#include <memory>

#ifdef ALT_PLATFORM_WINDOWS
#else
	#error Alternate only supports Windows!
#endif

#ifdef ALT_DEBUG
	#define ALT_ENABLE_ASSERTS
#endif

//TODO: Make this macro able to take no arguments
#ifdef ALT_ENABLE_ASSERTS
	#define ALT_ASSERT(x, ...) { if (!(x)) { ALT_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define ALT_CORE_ASSERT(x, ...) { if (!(x)) { ALT_CORE_ERROR("Assertion failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ALT_ASSERT(x, ...)
	#define ALT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define ALT_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace Alternate
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}