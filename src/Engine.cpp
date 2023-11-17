#include <iostream>
#include "spdlog/spdlog.h"
#include "Engine.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include <thread>
#include <chrono>
#include <vector>
#include "Types.h"
#include "ECS.h"

using namespace GameEng;
using namespace std;
Graphics gManager;
Input iManager;
Resource rManager;
Scripts sManager;
    void Engine::Startup(const UpdateCallback& callback) {
        gManager.Startup();
        iManager.Startup();
        sManager.Startup();
        //std::cout << "bruh" << endl;
        //globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
        //    gManager.LoadAnImage(globalECS.Get<SpriteEnt>(entity).name, globalECS.Get<SpriteEnt>(entity).path);
        //    });
        //gManager.LoadAnImage("Mario", "./assets/mariotwo.jpg");
        //RunGameLoop(callback);
    }
    void Engine::ShutDown() {

        iManager.ShutDown();
        gManager.ShutDown();
        exit(0);
    }
    void Engine::RunGameLoop(const UpdateCallback& callback)
    {
        int frames = 1;
        double frameTime = 1 / 120.0;//Changed from 60.0 to 120.0 because game engine was running at 30FPS. It now runs at 60. 
        ////Graphics::Sprite hero = { "Mario", vec2(0,0), vec2(0, 0), 0 };
        //std::vector<Graphics::Sprite> vecSprites = {};
        ////gManager.vecSprites.push_back(hero);
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            gManager.sprites.push_back(globalECS.Get<SpriteEnt>(entity));//THIS PUTS SPRITES INTO VECTOR TO DISPLAY (UPDATE TO WORK DURING RUN)
            // inside the loop
            });

        while (true) {
                double startTime = glfwGetTime();
                iManager.Update();
                sManager.Update();
                //std::cout << "bruh" << endl;
                //gManager.Draw(globalEngine.gManager.vecSprites);
                gManager.Draw();
                callback();
                if (iManager.KeyIsPressed(256) == true)
                {
                    break;
                }
                //std::cout << "\nClose?: " << glfwWindowShouldClose(globalEngine.gManager.window);
                if (glfwWindowShouldClose(globalEngine.gManager.window) == 1)
                {
                    glfwSetWindowShouldClose(globalEngine.gManager.window, true);
                    break;
                }
                frames++;
                //spdlog::info("startTime: {0}", startTime);
                //gManager.Draw();
                double execTime = glfwGetTime() - startTime;
                std::this_thread::sleep_for(std::chrono::duration<double>(frameTime - execTime));
            }
        
    }
    