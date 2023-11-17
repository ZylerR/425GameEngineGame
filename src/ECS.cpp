#include <iostream>
#include "spdlog/spdlog.h"
#include "ECS.h"
#include "Engine.h"
#include "Graphics.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
ECS::EntityID uniqueIDtotal = 0;
	//void Input::Startup() {
//ECS c;
using namespace GameEng;
ECS::EntityID ECS::Create()
{
	ECS::EntityID newID = uniqueIDtotal;
	//globalECS.Get<Position>(newID).x = 5;
	//c.Get<Graphics::Sprite>(newID);
	//c.Get<Velocity>(newID);
	//c.Get<Health>(newID);
	//c.Get<Gravity>(newID);
	//c.Get<Script>(newID);
	uniqueIDtotal++;
	return newID;
}
	//}
