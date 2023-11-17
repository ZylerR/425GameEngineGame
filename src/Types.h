#pragma once
#define GLFW_INCLUDE_NONE
#include "glm/glm.hpp"
//#include <string>
#include <vector>

namespace GameEng {
	typedef double real;
	typedef std::string string;
	typedef int realInt;
	//class Engine;
	//class Graphics;
	typedef glm::vec2 vec2;
	typedef glm::vec3 vec3;
	typedef glm::vec4 vec4;
	struct Position { real x, y; }; // or: struct Position : public vec2 {};
	struct Velocity { real x, y; }; // or: struct Velocity : public vec2 {};
	struct Gravity { real meters_per_second; };
	struct Script { string name; };
	struct SpriteEnt {
		string name;
		string path; 
		vec2 pos;
		vec2 scale; //vec2
		int z;
	};
	struct Health { real percent; };
}

