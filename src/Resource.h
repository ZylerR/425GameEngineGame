#pragma once
#include <string>
#include "Types.h"

using namespace GameEng;

	class Resource {
	public:
		void Startup();
		void ShutDown();
		std::string PathResolve(string path);
	};
