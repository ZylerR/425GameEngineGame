#pragma once
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "Types.h"
//#include "ECS.h"
#include <webgpu/webgpu.h>
#include <glfw3webgpu.h>
#include <unordered_map>
//#include "glm/glm.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace GameEng {
class Graphics{
	public:
		//ECS ecs;
		struct Images {
			int width;
			int height;
			WGPUTexture texture;

		};
		/*struct Sprite {
			string name;
			vec2 pos;
			vec2 scale; //vec2
			int z;
			//Images imgSaved;

		} spr;*/
		std::unordered_map<std::string, Images> imageSave;
		GLFWwindow* window;
		int window_width = 1000;
		int window_height = 1000;
		std::vector<SpriteEnt> sprites;
		char* window_name; 
		bool window_fullscreen;
		void Startup();
		void ShutDown();
		//void Draw(std::vector<Sprite>& sprites);
		void Draw();
		//void Draw();
		bool LoadAnImage(const std::string& name, const std::string& path);
};
}