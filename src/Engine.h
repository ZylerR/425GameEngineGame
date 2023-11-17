#pragma once

#include "Graphics.h"
#include "Input.h"
#include "Resource.h"
#include "Scripts.h"
//#include "ECS.h"
#include <functional>

using namespace GameEng;
	class Engine {
	public:
		typedef std::function<void()> UpdateCallback;
		Graphics gManager;
		Input iManager;
		Resource rManager;
		Scripts sManager;
		//ECS ecs;
		void Startup(const UpdateCallback&);
		void ShutDown();
		void RunGameLoop(const UpdateCallback&);
	};
	inline Engine globalEngine;
