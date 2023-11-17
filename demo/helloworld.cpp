#include <iostream>
#include "Engine.h"
#include <vector>
#include "Types.h"
#include "ECS.h"
#include "Scripts.h"

int d;
string bruh;


void callback()
{
    if (globalEngine.iManager.KeyIsPressed(65) == true)
    {
        //std::cout << "\nThe 'A' Key has been pressed!" << endl;
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            //std::cout << globalECS.Get<SpriteEnt>(entity).name << " Name of sprite" << endl;
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
            {
                //std::cout << "does this run?" << endl;
                globalECS.Get<SpriteEnt>(entity).pos.x -= 10;
                //globalECS.Get<SpriteEnt>(entity).pos.y -= 10;
            }
            });
    }
    if (globalEngine.iManager.KeyIsPressed(83) == true)
    {
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 10;
            }
            });
    }
    if (globalEngine.iManager.KeyIsPressed(68) == true)
    {
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
            {
                globalECS.Get<SpriteEnt>(entity).pos.x += 10;
            }
            });
    }
    if (globalEngine.iManager.KeyIsPressed(87) == true)
    {
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y += 10;
            }
            });
    }
    if (globalEngine.iManager.KeyIsPressed(32) == true)
    {
        int xShip = 0;
        int yShip = 0;
        ECS::EntityID newBull = globalECS.Create();
        globalECS.Get<SpriteEnt>(newBull) = SpriteEnt{ "bulletNew", "./assets/bullet.png", vec2(0,0), vec2(20,20), 0 };
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bulletNew")
                globalEngine.gManager.sprites.push_back(globalECS.Get<SpriteEnt>(entity));//THIS PUTS SPRITES INTO VECTOR TO DISPLAY (UPDATE TO WORK DURING RUN)
            globalEngine.gManager.LoadAnImage(globalECS.Get<SpriteEnt>(entity).name, globalECS.Get<SpriteEnt>(entity).path);
            });
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
            {
                xShip = globalECS.Get<SpriteEnt>(entity).pos.x;
                yShip = globalECS.Get<SpriteEnt>(entity).pos.y;
            }
            });
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bulletNew")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
            }
            });
        
        
    }
    globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bulletNew")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y += 10;
            }
    });

    
        globalECS.ForEach<SpriteEnt, Velocity>([&](ECS::EntityID entity) {
            //std::cout << "Name of Sprite: " << globalECS.Get<SpriteEnt>(entity).name << endl;
            //std::cout << "Has Velocity: " << globalECS.Get<Velocity>(entity).x << endl;
            //globalECS.Get<SpriteEnt>(entity).name = "BRUH";

            //std::cout << "Z Val New: " << globalECS.Get<SpriteEnt>(entity).name << endl;
            });
    
}
int main(int argc, const char* argv[]) {
    globalEngine.Startup(callback);
    ECS::EntityID newID = globalECS.Create();
    globalECS.Get<Position>(newID).x = 5;
    globalECS.Get<Velocity>(newID).x = 100;
    globalECS.Get<SpriteEnt>(newID) = SpriteEnt{ "starBG", "./assets/stars.jpg", vec2(0,0), vec2(100,100), 0 };
    globalECS.Get<Script>(newID).name = "testScript";
    ECS::EntityID bullet = globalECS.Create();
    globalECS.Get<SpriteEnt>(bullet) = SpriteEnt{ "bullet", "./assets/bullet.png", vec2(1000,0), vec2(10,10), 0 };
    ECS::EntityID newIDTwo = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo) = SpriteEnt{ "MarioTwo", "./assets/ship.jpg", vec2(0,0), vec2(20,20), 0 };
    globalECS.Get<Position>(newIDTwo).x = 10;
    d = globalECS.Get<SpriteEnt>(newID).z;
    globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
        globalEngine.gManager.LoadAnImage(globalECS.Get<SpriteEnt>(entity).name, globalECS.Get<SpriteEnt>(entity).path);
        });
    globalEngine.sManager.LoadScript(globalECS.Get<Script>(newID).name, "./assets/firstScript.lua");
    globalEngine.RunGameLoop(callback);
    return 0;
}