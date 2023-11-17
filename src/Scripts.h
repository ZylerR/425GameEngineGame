#pragma once
#include <string>
#include "Types.h"
#include <unordered_map>
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>

using namespace GameEng;

	class Scripts {
	public:
		//struct Script { string name; };
		sol::state lua;
		std::unordered_map<string, sol::load_result> scriptMap;
		void Startup();
		void ShutDown();
		void Update();
		sol::load_result& LoadScript(const string& name, const string& path);
	};
