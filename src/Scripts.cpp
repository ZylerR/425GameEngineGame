#include <iostream>
#include "spdlog/spdlog.h"
#include "Engine.h"
#include "Scripts.h"
#include "Types.h"
#include "ECS.h"
#include <string>
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#define SOL_ALL_SAFETIES_ON 1
#include <sol/sol.hpp>
#include <assert.h>

	void Scripts::Startup() {
		lua.open_libraries(sol::lib::base, sol::lib::math, sol::lib::table);
		lua.script("math.randomseed(0)");
		lua.new_enum("KEYBOARD", "A", GLFW_KEY_A);
		lua.set_function("KeyIsDown", [&](const int keycode) { return globalEngine.iManager.KeyIsPressed(keycode); });
		lua.set_function("Terminate", [&]() { return globalEngine.ShutDown(); });
		lua.set_function("Sprite", [&](ECS::EntityID entity) { return globalECS.Get<SpriteEnt>(entity); });
		lua.set_function("Position", [&](ECS::EntityID entity) { return globalECS.Get<Position>(entity); });
		lua.set_function("Velocity", [&](ECS::EntityID entity) { return globalECS.Get<Velocity>(entity); });
		lua.set_function("Gravity", [&](ECS::EntityID entity) { return globalECS.Get<Gravity>(entity); });
		lua.set_function("Health", [&](ECS::EntityID entity) { return globalECS.Get<Health>(entity); });
		lua.set_function("DropSprite", [&](ECS::EntityID entity) { return globalECS.Drop<SpriteEnt>(entity); });
		lua.set_function("DropPosition", [&](ECS::EntityID entity) { return globalECS.Drop<Position>(entity); });
		lua.set_function("DropVelocity", [&](ECS::EntityID entity) { return globalECS.Drop<Velocity>(entity); });
		lua.set_function("DropGravity", [&](ECS::EntityID entity) { return globalECS.Drop<Gravity>(entity); });
		lua.set_function("DropHealth", [&](ECS::EntityID entity) { return globalECS.Drop<Health>(entity); });
		lua.set_function("DropCreateEntity", [&](ECS::EntityID entity) { return globalECS.Create(); });

		lua.new_usertype<glm::vec2>("vec2",
			sol::constructors<glm::vec2(), glm::vec2(float), glm::vec2(float, float)>(),
			"x", &glm::vec2::x,
			"y", &glm::vec2::y
		);


		lua.new_usertype<Position>("Position",
			sol::constructors<Position()>(),
			"posX", &Position::x,
			"posY", &Position::y
		);
		lua.new_usertype<Velocity>("Velocity",
			sol::constructors<Velocity()>(),
			"velX", &Velocity::x,
			"velY", &Velocity::y
		);
		lua.new_usertype<Gravity>("Gravity",
			sol::constructors<Gravity()>(),
			"mps", &Gravity::meters_per_second
		);
		lua.new_usertype<Health>("Health",
			sol::constructors<Health()>(),
			"percent", &Health::percent
		);
		lua.new_usertype<SpriteEnt>("SpriteEnt",
			sol::constructors<SpriteEnt()>(),
			"name", &SpriteEnt::name,
			"path", &SpriteEnt::path,
			"pos", &SpriteEnt::pos,
			"scale", &SpriteEnt::scale,
			"z", &SpriteEnt::z
		);

	}
	void Scripts::ShutDown() {

	}
	sol::load_result& Scripts::LoadScript(const string& name, const string& path) {
		scriptMap[name] = lua.load_file(path);
		auto& script = scriptMap[name];
		if (!script.valid()) {
			std::cout << "Failed to load script!" << endl;
			exit(0);
		}
		return script;
	}
	void Scripts::Update() {
		globalECS.ForEach<Script>([&](ECS::EntityID entity) {
			scriptMap[globalECS.Get<Script>(entity).name](entity);
			});
	}
