#include <iostream>
#include "Engine.h"
#include <vector>
#include "Types.h"
#include "ECS.h"
#include "Scripts.h"
#include <cstdlib>

int d;
string bruh;
bool gameplay = true;
int speedUp;


void callback()
{
    if (gameplay == true)
    {
        speedUp = 0; 
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) { //Slow down naturally

            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo" && (globalECS.Get<SpriteEnt>(entity).vel.x > 0))
            {
                globalECS.Get<SpriteEnt>(entity).vel.x -= 0.5;
            }
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo" && (globalECS.Get<SpriteEnt>(entity).vel.y > 0))
            {
                globalECS.Get<SpriteEnt>(entity).vel.y -= 0.5;
            }
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo" && (globalECS.Get<SpriteEnt>(entity).vel.y < 0))
            {
                globalECS.Get<SpriteEnt>(entity).vel.y += 0.5;
            }
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo" && (globalECS.Get<SpriteEnt>(entity).vel.x < 0))
            {
                globalECS.Get<SpriteEnt>(entity).vel.x += 0.5;
            }
            });
        if (globalEngine.iManager.KeyIsPressed(76) == true) //L key (boost mechanic)
        {
            speedUp = 2;
            //std::cout << "does this run?" << endl;
        }
        if (globalEngine.iManager.KeyIsPressed(65) == true) //A key
        {
            //std::cout << "\nThe 'A' Key has been pressed!" << endl;
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                //std::cout << globalECS.Get<SpriteEnt>(entity).name << " Name of sprite" << endl;
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    //std::cout << "does this run?" << endl;

                    //globalECS.Get<SpriteEnt>(entity).pos.x -= 10;
                    globalECS.Get<SpriteEnt>(entity).vel.x = -2 - speedUp;
                    //globalECS.Get<SpriteEnt>(entity).pos.y -= 10;
                }
                });
        }
        if (globalEngine.iManager.KeyIsPressed(83) == true) //S key
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    globalECS.Get<SpriteEnt>(entity).vel.y = -2 - speedUp;
                }
                });
        }
        if (globalEngine.iManager.KeyIsPressed(68) == true) //D key
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    globalECS.Get<SpriteEnt>(entity).vel.x = 2 + speedUp;
                }
                });
        }
        if (globalEngine.iManager.KeyIsPressed(87) == true) //W key
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    globalECS.Get<SpriteEnt>(entity).vel.y = 2 + speedUp;
                }
                });
        }

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) { //Perform Speedup

            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
            {
                globalECS.Get<SpriteEnt>(entity).pos.x += globalECS.Get<SpriteEnt>(entity).vel.x;
                globalECS.Get<SpriteEnt>(entity).pos.y += globalECS.Get<SpriteEnt>(entity).vel.y;
            }
            });


        if (globalEngine.iManager.KeyIsPressed(32) == true) //Space key
        {
            std::cout << "spacebar entered" << endl;
            int xShip = 0;
            int yShip = 0;

            //This spawns a new bullet on ship
            /*ECS::EntityID newBull = globalECS.Create();
            globalECS.Get<SpriteEnt>(newBull) = SpriteEnt{ "bulletNew", "./assets/bullet.png", vec2(0,0), vec2(5,5), 0 };
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "bulletNew")
                    globalEngine.gManager.sprites.push_back(globalECS.Get<SpriteEnt>(entity));//THIS PUTS SPRITES INTO VECTOR TO DISPLAY (UPDATE TO WORK DURING RUN)
                globalEngine.gManager.LoadAnImage(globalECS.Get<SpriteEnt>(entity).name, globalECS.Get<SpriteEnt>(entity).path);
                });
            */

            //this gets ship's current position of frame
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    xShip = globalECS.Get<SpriteEnt>(entity).pos.x;
                    yShip = globalECS.Get<SpriteEnt>(entity).pos.y;
                }
                });

            //shoots bullet from current ship frame
            /*globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "bulletNew")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                    globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                }
                });
                */

            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) { // bullet's movement

                /*if (count == 0) {

                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet") {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }

                    count++;
                }
                else if (count == 1) {

                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet1") {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }

                    count++;
                }
                else {

                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet2") {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }

                    count = 0;
                }*/

                if (globalECS.Get<SpriteEnt>(entity).name == "bullet" && globalECS.Get<SpriteEnt>(entity).pos.y > 890) {
                    std::cout << "bullet bullet bulllet bullet bullet bullet" << endl;
                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet") {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }
                }
                else if (globalECS.Get<SpriteEnt>(entity).name == "bullet1" && globalECS.Get<SpriteEnt>(entity).pos.y > 1090) {
                    std::cout << "bullet1 bullet1 bullet1 bullet1 bullet1 bullet1 bullet1" << endl;
                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet1") {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }
                }
                else if (globalECS.Get<SpriteEnt>(entity).name == "bullet2" && globalECS.Get<SpriteEnt>(entity).pos.y > 1290) {
                    std::cout << "bullet2 bullet2 bullet2 bullet2 bullet2 bullet2" << endl;
                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet2") {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }
                }

                });


        }

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet" && globalECS.Get<SpriteEnt>(entity).pos.y < 900)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y += 3;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet1" && globalECS.Get<SpriteEnt>(entity).pos.y < 1100)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y += 3;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet2" && globalECS.Get<SpriteEnt>(entity).pos.y < 1300)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y += 3;
            }
            });

        /*globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet" && globalECS.Get<SpriteEnt>(entity).pos.y == 600)
            {
                std::cout << "bullet is at pixel 600, soon shot" << endl;
            }

            if (globalECS.Get<SpriteEnt>(entity).name == "bullet" && globalECS.Get<SpriteEnt>(entity).pos.y == 900)
            {
                std::cout << "bullet is at pixel 900" << endl;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet1" && globalECS.Get<SpriteEnt>(entity).pos.y == 600)
            {
                std::cout << "bullet1 is at pixel 600, soon shot" << endl;
            }
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet1" && globalECS.Get<SpriteEnt>(entity).pos.y == 1100)
            {
                std::cout << "bullet1 is at pixel 1100" << endl;
            }
            });
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet2" && globalECS.Get<SpriteEnt>(entity).pos.y == 600)
            {
                std::cout << "bullet2 is at pixel 600, soon shot" << endl;
            }
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet2" && globalECS.Get<SpriteEnt>(entity).pos.y == 1300)
            {
                std::cout << "bullet2 is at pixel 1300" << endl;
            }
            });*/

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo1")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.1;

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.1;

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.1;

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo4")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.1;

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5" && globalECS.Get<SpriteEnt>(entity).pos.x <= -60)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.1;

            }
            else if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5" && globalECS.Get<SpriteEnt>(entity).pos.x > -60)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.35;
            }

            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5" && globalECS.Get<SpriteEnt>(entity).pos.y < -110)
            {
                std::cout << "MT5 at 110" << endl;
                globalECS.Get<SpriteEnt>(entity).pos.y = 65;
                globalECS.Get<SpriteEnt>(entity).pos.x = -110;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6" && globalECS.Get<SpriteEnt>(entity).pos.x >= 60)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.1;

            }
            else if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6" && globalECS.Get<SpriteEnt>(entity).pos.x < 60)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.35;
            }

            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6" && globalECS.Get<SpriteEnt>(entity).pos.y < -110)
            {
                std::cout << "MT6 at 110" << endl;
                globalECS.Get<SpriteEnt>(entity).pos.y = 65;
                globalECS.Get<SpriteEnt>(entity).pos.x = 110;
            }
            });


        ////

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2" && (globalECS.Get<SpriteEnt>(entity).pos.y <= 35 && globalECS.Get<SpriteEnt>(entity).pos.y > 0))
            {
                globalECS.Get<SpriteEnt>(entity).pos.x += 0.1;
            }
            else if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2" && (globalECS.Get<SpriteEnt>(entity).pos.y <= 0 && globalECS.Get<SpriteEnt>(entity).pos.y > -35))
            {
                globalECS.Get<SpriteEnt>(entity).pos.x -= 0.1;
            }
            else if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2" && globalECS.Get<SpriteEnt>(entity).pos.y <= -35)
            {
                globalECS.Get<SpriteEnt>(entity).pos.x += 0.1;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3" && (globalECS.Get<SpriteEnt>(entity).pos.y <= 35 && globalECS.Get<SpriteEnt>(entity).pos.y > 0))
            {
                globalECS.Get<SpriteEnt>(entity).pos.x -= 0.1;
            }
            else if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3" && (globalECS.Get<SpriteEnt>(entity).pos.y <= 0 && globalECS.Get<SpriteEnt>(entity).pos.y > -35))
            {
                globalECS.Get<SpriteEnt>(entity).pos.x += 0.1;
            }
            else if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3" && globalECS.Get<SpriteEnt>(entity).pos.y <= -35)
            {
                globalECS.Get<SpriteEnt>(entity).pos.x -= 0.1;
            }
            });

        ////



        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo1" && globalECS.Get<SpriteEnt>(entity).pos.y < -110)
            {
                std::cout << "MT1 at 110" << endl;
                globalECS.Get<SpriteEnt>(entity).pos.y = 110;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2" && globalECS.Get<SpriteEnt>(entity).pos.y < -110)
            {
                std::cout << "MT2 at 110" << endl;
                globalECS.Get<SpriteEnt>(entity).pos.y = 110;
                globalECS.Get<SpriteEnt>(entity).pos.x = -35;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3" && globalECS.Get<SpriteEnt>(entity).pos.y < -110)
            {
                std::cout << "MT3 at 110" << endl;
                globalECS.Get<SpriteEnt>(entity).pos.y = 110;
                globalECS.Get<SpriteEnt>(entity).pos.x = 35;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo4" && globalECS.Get<SpriteEnt>(entity).pos.y < -110)
            {
                std::cout << "MT4 at 110" << endl;
                globalECS.Get<SpriteEnt>(entity).pos.y = 110;
            }
            });

        ////

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

            int xShip = 0;

            //this gets ship's current position of frame
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    xShip = globalECS.Get<SpriteEnt>(entity).pos.x;
                }
                });

            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5" && globalECS.Get<SpriteEnt>(entity).pos.x < xShip)
            {
                globalECS.Get<SpriteEnt>(entity).pos.x += 0.15;

            }

            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6" && globalECS.Get<SpriteEnt>(entity).pos.x > xShip)
            {
                globalECS.Get<SpriteEnt>(entity).pos.x -= 0.15;

            }

            });

        globalECS.ForEach<SpriteEnt, Velocity>([&](ECS::EntityID entity) {
            //std::cout << "Name of Sprite: " << globalECS.Get<SpriteEnt>(entity).name << endl;
            //std::cout << "Has Velocity: " << globalECS.Get<Velocity>(entity).x << endl;
            //globalECS.Get<SpriteEnt>(entity).name = "BRUH";

            //std::cout << "Z Val New: " << globalECS.Get<SpriteEnt>(entity).name << endl;
            });
        //Collision Checking
        int xShipPos = 0;
        int yShipPos = 0;
        int enemyXPos = 0;
        int enemyYPos = 0;

        //This spawns a new bullet on ship
        /*ECS::EntityID newBull = globalECS.Create();
        globalECS.Get<SpriteEnt>(newBull) = SpriteEnt{ "bulletNew", "./assets/bullet.png", vec2(0,0), vec2(5,5), 0 };
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bulletNew")
                globalEngine.gManager.sprites.push_back(globalECS.Get<SpriteEnt>(entity));//THIS PUTS SPRITES INTO VECTOR TO DISPLAY (UPDATE TO WORK DURING RUN)
            globalEngine.gManager.LoadAnImage(globalECS.Get<SpriteEnt>(entity).name, globalECS.Get<SpriteEnt>(entity).path);
            });
        */

        //this gets ship's current position of frame
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
            {
                xShipPos = globalECS.Get<SpriteEnt>(entity).pos.x;
                yShipPos = globalECS.Get<SpriteEnt>(entity).pos.y;
            }
            });
        //ECS::EntityID globulletOne;
        //ECS::EntityID globulletTwo;
        //ECS::EntityID globulletThree;
        int bOneX = 0;
        int bOneY = 0;
        int bTwoX = 0;
        int bTwoY = 0;
        int bThreeX = 0;
        int bThreeY = 0;
        int entCount = 0;
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).scale.x == 4 && globalECS.Get<SpriteEnt>(entity).scale.y == 4)
            {
                if (entCount == 0)
                {
                    std::cout << "BULL" << globalECS.Get<SpriteEnt>(entity).pos.y << endl;
                    bOneX = globalECS.Get<SpriteEnt>(entity).pos.x;
                    bOneY = globalECS.Get<SpriteEnt>(entity).pos.y;
                }
                if (entCount == 1)
                {
                    bTwoX = globalECS.Get<SpriteEnt>(entity).pos.x;
                    bTwoY = globalECS.Get<SpriteEnt>(entity).pos.y;
                }
                if (entCount == 2)
                {
                    bThreeX = globalECS.Get<SpriteEnt>(entity).pos.x;
                    bThreeY = globalECS.Get<SpriteEnt>(entity).pos.y;
                }
                entCount++;
            }
                //std::cout << "BULL" << globalECS.Get<SpriteEnt>(entity).pos.y << endl;
            });
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).scale.x == 6 && globalECS.Get<SpriteEnt>(entity).scale.y == 6)
            {
                //std::cout << "SCALE 5 5 LOLLLLLLLLL" << globalECS.Get<SpriteEnt>(entity).name << endl;
                if ((abs(xShipPos - globalECS.Get<SpriteEnt>(entity).pos.x) < 10) && (abs(yShipPos - globalECS.Get<SpriteEnt>(entity).pos.y) < 10))
                {
                    std::cout << "COLLISION!!!!! AHHHH" << globalECS.Get<SpriteEnt>(entity).name << endl;
                    //gameplay = false; 
                    globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                        if (globalECS.Get<SpriteEnt>(entity).name == "lose")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 0;
                        }
                    });
                    gameplay = false;
                }
                if (globalECS.Get<SpriteEnt>(entity).pos.y < -50)
                {
                    std::cout << "FALLOUT!!!!" << globalECS.Get<SpriteEnt>(entity).name << endl;
                    //gameplay = false; 
                    globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                        if (globalECS.Get<SpriteEnt>(entity).name == "lose")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 0;
                        }
                        });
                    gameplay = false;
                }
                if ((abs(bOneX - globalECS.Get<SpriteEnt>(entity).pos.x) < 10) && (abs(bOneY - globalECS.Get<SpriteEnt>(entity).pos.y) < 10))
                {
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                }
                if ((abs(bTwoX - globalECS.Get<SpriteEnt>(entity).pos.x) < 10) && (abs(bTwoY - globalECS.Get<SpriteEnt>(entity).pos.y) < 10))
                {
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                }
                if ((abs(bThreeX - globalECS.Get<SpriteEnt>(entity).pos.x) < 10) && (abs(bThreeY - globalECS.Get<SpriteEnt>(entity).pos.y) < 10))
                {
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                }

                //std::cout << "Bullet One Name: " << globalECS.Get<SpriteEnt>(globulletOne).pos.x << endl;

            }
            });
    }
    
    
}
int main(int argc, const char* argv[]) {
    globalEngine.Startup(callback);
    ECS::EntityID newID = globalECS.Create();
    globalECS.Get<Position>(newID).x = 5;
    globalECS.Get<Velocity>(newID).x = 100;
    globalECS.Get<SpriteEnt>(newID) = SpriteEnt{ "starBG", "./assets/stars.jpg", vec2(0,0), vec2(0,0), vec2(100,100), 0 };
    globalECS.Get<Script>(newID).name = "testScript";
    
    ECS::EntityID bullet = globalECS.Create();
    //globulletOne = bullet;
    globalECS.Get<SpriteEnt>(bullet) = SpriteEnt{ "bullet", "./assets/bullet.png", vec2(-30,70), vec2(0,0), vec2(4,4), 0 };
    ECS::EntityID bullet1 = globalECS.Create();
    //globulletTwo = bullet1;
    globalECS.Get<SpriteEnt>(bullet1) = SpriteEnt{ "bullet1", "./assets/bullet.png", vec2(-45,70), vec2(0,0), vec2(4,4), 0 };
    ECS::EntityID bullet2 = globalECS.Create();
    //globulletThree = bullet2;
    globalECS.Get<SpriteEnt>(bullet2) = SpriteEnt{ "bullet2", "./assets/bullet.png", vec2(-55,70), vec2(0,0), vec2(4,4), 0 };

    ECS::EntityID newIDTwo = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo) = SpriteEnt{ "MarioTwo", "./assets/shipFix.png", vec2(0,-40), vec2(0,0), vec2(10,10), 0};
    globalECS.Get<Position>(newIDTwo).x = 10;
    d = globalECS.Get<SpriteEnt>(newID).z;
    
    ECS::EntityID newIDTwo1 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo1) = SpriteEnt{ "MarioTwo1", "./assets/shipEnemy.png", vec2(-70,70), vec2(0,0), vec2(6,6), 0 };
    ECS::EntityID newIDTwo2 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo2) = SpriteEnt{ "MarioTwo2", "./assets/shipEnemy.png", vec2(-35,70), vec2(0,0), vec2(6,6), 0 };
    ECS::EntityID newIDTwo3 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo3) = SpriteEnt{ "MarioTwo3", "./assets/shipEnemy.png", vec2(35,70), vec2(0,0), vec2(6,6), 0 };
    ECS::EntityID newIDTwo4 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo4) = SpriteEnt{ "MarioTwo4", "./assets/shipEnemy.png", vec2(70,70), vec2(0,0), vec2(6,6), 0 };

    ECS::EntityID newIDTwo5 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo5) = SpriteEnt{ "MarioTwo5", "./assets/shipEnemy.png", vec2(-110,65), vec2(0,0), vec2(6,6), 0 };
    ECS::EntityID newIDTwo6 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo6) = SpriteEnt{ "MarioTwo6", "./assets/shipEnemy.png", vec2(110,65), vec2(0,0), vec2(6,6), 0 };

    ECS::EntityID loseID = globalECS.Create();
    globalECS.Get<SpriteEnt>(loseID) = SpriteEnt{ "lose", "./assets/youlose.jpg", vec2(2000,0), vec2(0,0), vec2(100,100), 0 };

    globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
        globalEngine.gManager.LoadAnImage(globalECS.Get<SpriteEnt>(entity).name, globalECS.Get<SpriteEnt>(entity).path);
        });
    globalEngine.sManager.LoadScript(globalECS.Get<Script>(newID).name, "./assets/firstScript.lua");
    globalEngine.RunGameLoop(callback);
    return 0;
}