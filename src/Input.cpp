#include <iostream>
#include "spdlog/spdlog.h"
#include "Input.h"
#include "Engine.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

	void Input::Startup() {

	}
	void Input::Update() {
		glfwPollEvents();
	}
	void Input::ShutDown() {

	}
	bool Input::KeyIsPressed(const int keyPressed) {
		//if (glfwGetKey(globalEngine.gManager.window, keyPressed) == true)
		//{
		//	std::cout << "\n'A' Key Pressed: ";
		//}
		return glfwGetKey(globalEngine.gManager.window, keyPressed);
	}

