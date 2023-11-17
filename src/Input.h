#pragma once
#include "Types.h"

using namespace GameEng;
	class Input {
	public:
		void Startup();
		void ShutDown();
		void Update();
		bool KeyIsPressed(const int keyPress);
	};

