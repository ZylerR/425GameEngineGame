#include <iostream>
#include "Engine.h"
#include <vector>
#include "Types.h"
#include "ECS.h"
#include "Scripts.h"
#include <cstdlib>

int d;
string bruh;
bool gameplay = false;
int speedUp;
int bulletNum = 0;
bool gtfo = false;
bool keepHorizontal5 = true;
bool keepHorizontal6 = true;
int menuDisplay = 1;
int cantPressEnt = 0;
int explosionDurationOne = 10;
int explosionDurationTwo = 10;
int explosionDurationThree = 10;
int explodePick = 0;


void callback()
{
    if (gameplay == false && menuDisplay == 1) {
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            //std::cout << globalECS.Get<SpriteEnt>(entity).name << " Name of sprite" << endl;
            if (globalECS.Get<SpriteEnt>(entity).name == "menu")
            {
                globalECS.Get<SpriteEnt>(entity).pos.x = 0;
            }
            });
        if (cantPressEnt < 10)
        {
            cantPressEnt++;
        }
        if (globalEngine.iManager.KeyIsPressed(257) == true && cantPressEnt == 10) //enter key
        {
            gameplay = true;
            menuDisplay = 0;
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                //std::cout << globalECS.Get<SpriteEnt>(entity).name << " Name of sprite" << endl;
                if (globalECS.Get<SpriteEnt>(entity).name == "menu")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 500;
                }
                });
            cantPressEnt = 0;
        }
    }
    if (gameplay == false && menuDisplay == 0) {
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

        if (globalEngine.iManager.KeyIsPressed(257) == true) //enter key
        {
            //gameplay = true;
            menuDisplay = 1;
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "bullet")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -30;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 200;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "bullet1")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -45;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 200;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "bullet2")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -55;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 200;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 0;
                    globalECS.Get<SpriteEnt>(entity).pos.y = -48;
                    globalECS.Get<SpriteEnt>(entity).vel.y = 0;
                    globalECS.Get<SpriteEnt>(entity).vel.x = 0;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo1")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -70;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -35;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 35;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo4")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 70;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -600;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 600;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "highRat1")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -1100;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "highRat2")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 1200;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 15;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "highRat3")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -1200;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 20;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "highRat4")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 1100;
                    globalECS.Get<SpriteEnt>(entity).pos.y = -48;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "bossRat1")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -80;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "bossRat2")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 80;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2500;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "explodeOne")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 0;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "explodeTwo")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 0;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                }
                if (globalECS.Get<SpriteEnt>(entity).name == "explodeThree")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 0;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                }
                //std::cout << globalECS.Get<SpriteEnt>(entity).name << " Name of sprite" << endl;
                if (globalECS.Get<SpriteEnt>(entity).name == "lose")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 1000;
                }
                });
        }
            });
    }
    else if (gameplay == true)
    {
        if (explosionDurationOne < 10)
        {
            explosionDurationOne += 1;
        }
        else
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "explodeOne")
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                });
        }
        if (explosionDurationTwo < 10)
        {
            explosionDurationTwo += 1;
        }
        else
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "explodeTwo")
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                });
        }
        if (explosionDurationThree < 10)
        {
            explosionDurationThree += 1;
        }
        else
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "explodeThree")
                    globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                });
        }
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
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo" && globalECS.Get<SpriteEnt>(entity).pos.x > -91.5)
                {
                    //std::cout << "does this run?" << endl;

                    //globalECS.Get<SpriteEnt>(entity).pos.x -= 10;
                    if (globalECS.Get<SpriteEnt>(entity).pos.x > -85) {
                        globalECS.Get<SpriteEnt>(entity).vel.x = -2 - speedUp;
                    }
                    else {
                        globalECS.Get<SpriteEnt>(entity).vel.x = -2;
                    }
                    //globalECS.Get<SpriteEnt>(entity).pos.y -= 10;
                }
                });
        }

        if (globalEngine.iManager.KeyIsPressed(66) == true) //B key
        {
            //std::cout << "\nThe 'A' Key has been pressed!" << endl;
        }

        if (globalEngine.iManager.KeyIsPressed(83) == true) //S key
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo" && globalECS.Get<SpriteEnt>(entity).pos.y > -50)
                {

                    if (globalECS.Get<SpriteEnt>(entity).pos.y > -45) {
                        globalECS.Get<SpriteEnt>(entity).vel.y = -2 - speedUp;
                    }
                    else {
                        globalECS.Get<SpriteEnt>(entity).vel.y = -2;
                    }
                }
                });
        }
        if (globalEngine.iManager.KeyIsPressed(68) == true) //D key
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo" && globalECS.Get<SpriteEnt>(entity).pos.x < 91.5)
                {

                    if (globalECS.Get<SpriteEnt>(entity).pos.x < 85) {
                        globalECS.Get<SpriteEnt>(entity).vel.x = 2 + speedUp;
                    }
                    else {
                        globalECS.Get<SpriteEnt>(entity).vel.x = 2;
                    }
                }
                });
        }
        if (globalEngine.iManager.KeyIsPressed(87) == true) //W key
        {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo" && globalECS.Get<SpriteEnt>(entity).pos.y < 50)
                {

                    if (globalECS.Get<SpriteEnt>(entity).pos.y < 45) {
                        globalECS.Get<SpriteEnt>(entity).vel.y = 2 + speedUp;
                    }
                    else {
                        globalECS.Get<SpriteEnt>(entity).vel.y = 2;
                    }
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

                if (bulletNum == 0 && globalECS.Get<SpriteEnt>(entity).name == "bullet" && globalECS.Get<SpriteEnt>(entity).pos.y > 105) {
                    std::cout << "was entereddddddddddddddddddddddddddddddddddddddddddddddddddddddddd" << endl;
                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet") {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }

                }
                else if (bulletNum == 1 && globalECS.Get<SpriteEnt>(entity).name == "bullet1" && globalECS.Get<SpriteEnt>(entity).pos.y > 105) {

                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet1") {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }

                }
                else {

                    if (globalECS.Get<SpriteEnt>(entity).name == "bullet2" && globalECS.Get<SpriteEnt>(entity).pos.y > 105) {
                        globalECS.Get<SpriteEnt>(entity).pos.y = yShip;
                        globalECS.Get<SpriteEnt>(entity).pos.x = xShip;
                    }

                }

                if (bulletNum == 2) {
                    bulletNum = 0;
                }
                else {
                    bulletNum++;
                }

                /*if (globalECS.Get<SpriteEnt>(entity).name == "bullet" && globalECS.Get<SpriteEnt>(entity).pos.y > 890) {
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
                }*/

                });


        }

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet" && globalECS.Get<SpriteEnt>(entity).pos.y < 110)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y += 3;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet1" && globalECS.Get<SpriteEnt>(entity).pos.y < 110)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y += 3;
            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "bullet2" && globalECS.Get<SpriteEnt>(entity).pos.y < 110)
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
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.15;

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.15;

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo4")
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.1;

            }
            });

        /////// enemy 5 and 6 movement
        if (keepHorizontal5) {
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
                    if (globalECS.Get<SpriteEnt>(entity).pos.x < -110) {
                        globalECS.Get<SpriteEnt>(entity).pos.x += 1;
                    }
                    else {
                        globalECS.Get<SpriteEnt>(entity).pos.x += 0.15;
                    }

                }

                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5" && globalECS.Get<SpriteEnt>(entity).pos.x > xShip){
                    keepHorizontal5 = false;
                }
                });
        }

        if (keepHorizontal6) {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

                int xShip = 0;

                //this gets ship's current position of frame
                globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                    if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                    {
                        xShip = globalECS.Get<SpriteEnt>(entity).pos.x;
                    }
                    });

                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6" && globalECS.Get<SpriteEnt>(entity).pos.x > xShip)
                {
                    if (globalECS.Get<SpriteEnt>(entity).pos.x > 110) {
                        globalECS.Get<SpriteEnt>(entity).pos.x -= 1;
                    }
                    else {
                        globalECS.Get<SpriteEnt>(entity).pos.x -= 0.15;
                    }

                }

                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6" && globalECS.Get<SpriteEnt>(entity).pos.x < xShip) {
                    keepHorizontal6 = false;
                }
                });
        }

        if (!keepHorizontal5) {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5")
                {
                    globalECS.Get<SpriteEnt>(entity).pos.y -= 0.35;

                }
                
                });
        }

        if (!keepHorizontal6) {
            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6")
                {

                    globalECS.Get<SpriteEnt>(entity).pos.y -= 0.35;

                }
                /*else if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5" && globalECS.Get<SpriteEnt>(entity).pos.x > -60)
                {
                    globalECS.Get<SpriteEnt>(entity).pos.y -= 0.35;
                }

                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5" && globalECS.Get<SpriteEnt>(entity).pos.y < -110)
                {
                    std::cout << "MT5 at 110" << endl;
                    globalECS.Get<SpriteEnt>(entity).pos.y = 65;
                    globalECS.Get<SpriteEnt>(entity).pos.x = -110;
                }
                */
                });
        }

        /////// enemy 5 and 6 movement end

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
            /*else if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6" && globalECS.Get<SpriteEnt>(entity).pos.x < 60)
            {
                globalECS.Get<SpriteEnt>(entity).pos.y -= 0.35;
            }

            if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6" && globalECS.Get<SpriteEnt>(entity).pos.y < -110)
            {
                std::cout << "MT6 at 110" << endl;
                globalECS.Get<SpriteEnt>(entity).pos.y = 65;
                globalECS.Get<SpriteEnt>(entity).pos.x = 110;
            }*/
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



        /*globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
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
            });*/

        ////

        ////highRat Movement begin
        //sync rat 1,4 ; 2,3

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

            if (globalECS.Get<SpriteEnt>(entity).name == "highRat1")
            {
                if (globalECS.Get<SpriteEnt>(entity).pos.x < -110) {
                    globalECS.Get<SpriteEnt>(entity).pos.x += 1;
                }
                else {
                    globalECS.Get<SpriteEnt>(entity).pos.x += 0.17;
                }

                if (globalECS.Get<SpriteEnt>(entity).pos.x > 110) {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -650;
                }

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

            if (globalECS.Get<SpriteEnt>(entity).name == "highRat2")
            {
                if (globalECS.Get<SpriteEnt>(entity).pos.x > 110) {
                    globalECS.Get<SpriteEnt>(entity).pos.x -= 1;
                }
                else {
                    globalECS.Get<SpriteEnt>(entity).pos.x -= 0.17;
                }

                if (globalECS.Get<SpriteEnt>(entity).pos.x < -110) {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 650;
                }

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

            if (globalECS.Get<SpriteEnt>(entity).name == "highRat3")
            {
                if (globalECS.Get<SpriteEnt>(entity).pos.x < -110) {
                    globalECS.Get<SpriteEnt>(entity).pos.x += 1;
                }
                else {
                    globalECS.Get<SpriteEnt>(entity).pos.x += 0.17;
                }

                if (globalECS.Get<SpriteEnt>(entity).pos.x > 110) {
                    globalECS.Get<SpriteEnt>(entity).pos.x = -750;
                }

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

            if (globalECS.Get<SpriteEnt>(entity).name == "highRat4")
            {
                if (globalECS.Get<SpriteEnt>(entity).pos.x > 110) {
                    globalECS.Get<SpriteEnt>(entity).pos.x -= 1;
                }
                else {
                    globalECS.Get<SpriteEnt>(entity).pos.x -= 0.17;
                }

                if (globalECS.Get<SpriteEnt>(entity).pos.x < -110) {
                    globalECS.Get<SpriteEnt>(entity).pos.x = 750;
                }

            }
            });

        ////highRat movement end


        ////bossRat movement begin
        
        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

            int xShip = 0;
            int yShip = 0;

            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    xShip = globalECS.Get<SpriteEnt>(entity).pos.x;
                    yShip = globalECS.Get<SpriteEnt>(entity).pos.y;
                }
                });

            if (globalECS.Get<SpriteEnt>(entity).name == "bossRat1")
            {
                if (globalECS.Get<SpriteEnt>(entity).pos.y > yShip) {
                    if (globalECS.Get<SpriteEnt>(entity).pos.y > 70) {
                        globalECS.Get<SpriteEnt>(entity).pos.y -= 1;
                    }
                    else {
                        globalECS.Get<SpriteEnt>(entity).pos.y -= 0.2;
                    }
                }
                else {
                    if (globalECS.Get<SpriteEnt>(entity).pos.y < yShip) {
                        globalECS.Get<SpriteEnt>(entity).pos.y += 0.18;
                    }
                }

                if (globalECS.Get<SpriteEnt>(entity).pos.x < xShip) {
                    if (globalECS.Get<SpriteEnt>(entity).pos.y < 60) {
                        globalECS.Get<SpriteEnt>(entity).pos.x += 0.2;
                    }
                }
                else
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x -= 0.18;
                }

            }
            });

        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {

            int xShip = 0;
            int yShip = 0;

            globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo")
                {
                    xShip = globalECS.Get<SpriteEnt>(entity).pos.x;
                    yShip = globalECS.Get<SpriteEnt>(entity).pos.y;
                }
                });

            if (globalECS.Get<SpriteEnt>(entity).name == "bossRat2")
            {
                if (globalECS.Get<SpriteEnt>(entity).pos.y > yShip) {
                    if (globalECS.Get<SpriteEnt>(entity).pos.y > 70) {
                        globalECS.Get<SpriteEnt>(entity).pos.y -= 1;
                    }
                    else {
                        globalECS.Get<SpriteEnt>(entity).pos.y -= 0.2;
                    }
                }
                else {
                    if (globalECS.Get<SpriteEnt>(entity).pos.y < yShip) {
                        globalECS.Get<SpriteEnt>(entity).pos.y += 0.24;
                    }
                }

                if (globalECS.Get<SpriteEnt>(entity).pos.x < xShip) {
                    if (globalECS.Get<SpriteEnt>(entity).pos.y < 60) {
                        globalECS.Get<SpriteEnt>(entity).pos.x += 0.2;
                    }
                }
                else
                {
                    globalECS.Get<SpriteEnt>(entity).pos.x -= 0.24;
                }

            }
            });
        ////bossRat movement end

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
        int collisionSpotX = 0;
        int collisionSpotY = 0;
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
            if ((globalECS.Get<SpriteEnt>(entity).scale.x == 6 && globalECS.Get<SpriteEnt>(entity).scale.y == 6) || globalECS.Get<SpriteEnt>(entity).scale.x == -6) //this is where enemies are hit
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
                if (globalECS.Get<SpriteEnt>(entity).pos.y < -70)
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
                        collisionSpotY = globalECS.Get<SpriteEnt>(entity).pos.y;
                        collisionSpotX = globalECS.Get<SpriteEnt>(entity).pos.x;
                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo1")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -70;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -35;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 35;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo4")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 70;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -480;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                            keepHorizontal5 = true;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 480;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                            keepHorizontal6 = true;
                        }
                        //globalECS.Get<SpriteEnt>(entity).pos.y = 2000;
                        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                            if (globalECS.Get<SpriteEnt>(entity).scale.x == 20)
                            {
                                if (explodePick == 0)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeOne")
                                    {
                                        explosionDurationOne = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                                else if (explodePick == 1)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeTwo")
                                    {
                                        explosionDurationTwo = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                                else if (explodePick == 2)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeThree")
                                    {
                                        explosionDurationThree = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                            }
                            });
                        if (explodePick < 2)
                        {
                            explodePick++;
                        }
                        else
                        {
                            explodePick = 0;
                        }
                        //globalECS.Get<SpriteEnt>(entity).pos.x globalECS.Get<SpriteEnt>(entity).pos.x
                }
                if ((abs(bTwoX - globalECS.Get<SpriteEnt>(entity).pos.x) < 10) && (abs(bTwoY - globalECS.Get<SpriteEnt>(entity).pos.y) < 10))
                {
                        collisionSpotY = globalECS.Get<SpriteEnt>(entity).pos.y;
                        collisionSpotX = globalECS.Get<SpriteEnt>(entity).pos.x;
                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo1")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -70;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -35;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 35;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo4")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 70;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -580;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                            keepHorizontal5 = true;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 580;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                            keepHorizontal6 = true;
                        }
                        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                            if (globalECS.Get<SpriteEnt>(entity).scale.x == 20)
                            {
                                if (explodePick == 0)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeOne")
                                    {
                                        explosionDurationOne = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                                else if (explodePick == 1)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeTwo")
                                    {
                                        explosionDurationTwo = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                                else if (explodePick == 2)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeThree")
                                    {
                                        explosionDurationThree = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                            }
                            });
                        if (explodePick < 2)
                        {
                            explodePick++;
                        }
                        else
                        {
                            explodePick = 0;
                        }
                }
                if ((abs(bThreeX - globalECS.Get<SpriteEnt>(entity).pos.x) < 10) && (abs(bThreeY - globalECS.Get<SpriteEnt>(entity).pos.y) < 10))
                {
                        collisionSpotY = globalECS.Get<SpriteEnt>(entity).pos.y;
                        collisionSpotX = globalECS.Get<SpriteEnt>(entity).pos.x;
                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo1")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -70;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo2")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -35;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo3")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 35;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo4")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 70;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 70;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo5")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = -400;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                            keepHorizontal5 = true;
                        }

                        if (globalECS.Get<SpriteEnt>(entity).name == "MarioTwo6")
                        {
                            globalECS.Get<SpriteEnt>(entity).pos.x = 400;
                            globalECS.Get<SpriteEnt>(entity).pos.y = 43;
                            keepHorizontal6 = true;
                        }
                        globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
                            if (globalECS.Get<SpriteEnt>(entity).scale.x == 20)
                            {
                                if (explodePick == 0)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeOne")
                                    {
                                        explosionDurationOne = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                                else if (explodePick == 1)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeTwo")
                                    {
                                        explosionDurationTwo = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                                else if (explodePick == 2)
                                {
                                    if (globalECS.Get<SpriteEnt>(entity).name == "explodeThree")
                                    {
                                        explosionDurationThree = 0;
                                        globalECS.Get<SpriteEnt>(entity).pos.x = collisionSpotX;
                                        globalECS.Get<SpriteEnt>(entity).pos.y = collisionSpotY;
                                    }
                                }
                            }
                            });
                        if (explodePick < 2)
                        {
                            explodePick++;
                        }
                        else
                        {
                            explodePick = 0;
                        }
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
    globalECS.Get<SpriteEnt>(bullet) = SpriteEnt{ "bullet", "./assets/spaceBullet.png", vec2(-30,200), vec2(0,0), vec2(4,4), 0 };
    ECS::EntityID bullet1 = globalECS.Create();
    //globulletTwo = bullet1;
    globalECS.Get<SpriteEnt>(bullet1) = SpriteEnt{"bullet1", "./assets/spaceBullet.png", vec2(-45,200), vec2(0,0), vec2(4,4), 0};
    ECS::EntityID bullet2 = globalECS.Create();
    //globulletThree = bullet2;
    globalECS.Get<SpriteEnt>(bullet2) = SpriteEnt{ "bullet2", "./assets/spaceBullet.png", vec2(-55,200), vec2(0,0), vec2(4,4), 0 };
    
    ECS::EntityID newIDTwo = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo) = SpriteEnt{ "MarioTwo", "./assets/shipFix.png", vec2(0,-48), vec2(0,0), vec2(6.5,6.5), 0}; //93.5 hori edge of screen, 54 bot vert edge
    globalECS.Get<Position>(newIDTwo).x = 10;
    d = globalECS.Get<SpriteEnt>(newID).z;
    
    //coolRatNoBG, 
    ECS::EntityID newIDTwo1 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo1) = SpriteEnt{ "MarioTwo1", "./assets/jRatNoBG.png", vec2(-70,70), vec2(0,0), vec2(6,6), 0 };
    ECS::EntityID newIDTwo2 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo2) = SpriteEnt{ "MarioTwo2", "./assets/jRatNoBG.png", vec2(-35,70), vec2(0,0), vec2(6,6), 0 };
    ECS::EntityID newIDTwo3 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo3) = SpriteEnt{ "MarioTwo3", "./assets/jRatNoBG.png", vec2(35,70), vec2(0,0), vec2(6,6), 0 };
    ECS::EntityID newIDTwo4 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo4) = SpriteEnt{ "MarioTwo4", "./assets/jRatNoBG.png", vec2(70,70), vec2(0,0), vec2(6,6), 0 };

    ECS::EntityID newIDTwo5 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo5) = SpriteEnt{ "MarioTwo5", "./assets/coolRatNoBG.png", vec2(-600,43), vec2(0,0), vec2(6,6), 0 };// make them spawn horizontally 35
    ECS::EntityID newIDTwo6 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo6) = SpriteEnt{ "MarioTwo6", "./assets/coolRatNoBG.png", vec2(600,43), vec2(0,0), vec2(6,6), 0 };

    ECS::EntityID newIDTwo7 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo7) = SpriteEnt{ "highRat1", "./assets/highRatNoBG.png", vec2(-1100,43), vec2(0,0), vec2(6,6), 0 };// make them spawn horizontally 35
    ECS::EntityID newIDTwo8 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo8) = SpriteEnt{ "highRat2", "./assets/highRatNoBG.png", vec2(1200,15), vec2(0,0), vec2(-6,6), 0 };
    ECS::EntityID newIDTwo9 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo9) = SpriteEnt{ "highRat3", "./assets/highRatNoBG.png", vec2(-1200,-20), vec2(0,0), vec2(6,6), 0 };// make them spawn horizontally 35
    ECS::EntityID newIDTwo10 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo10) = SpriteEnt{ "highRat4", "./assets/highRatNoBG.png", vec2(1100, -48), vec2(0,0), vec2(-6,6), 0 };

    ECS::EntityID newIDTwo11 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo11) = SpriteEnt{ "bossRat1", "./assets/bossRat.png", vec2(-80, 2000), vec2(0,0), vec2(6,6), 0 };
    ECS::EntityID newIDTwo12 = globalECS.Create();
    globalECS.Get<SpriteEnt>(newIDTwo12) = SpriteEnt{ "bossRat2", "./assets/bossRat.png", vec2(80, 2500), vec2(0,0), vec2(-6,6), 0 };

    ECS::EntityID explodeyOne = globalECS.Create();
    globalECS.Get<SpriteEnt>(explodeyOne) = SpriteEnt{ "explodeOne", "./assets/explodey.png", vec2(0,2000), vec2(0,0), vec2(20,20), 0 };
    ECS::EntityID explodeyTwo = globalECS.Create();
    globalECS.Get<SpriteEnt>(explodeyTwo) = SpriteEnt{ "explodeTwo", "./assets/explodey.png", vec2(0,2000), vec2(0,0), vec2(20,20), 0 };
    ECS::EntityID explodeyThree = globalECS.Create();
    globalECS.Get<SpriteEnt>(explodeyThree) = SpriteEnt{ "explodeThree", "./assets/explodey.png", vec2(0,2000), vec2(0,0), vec2(20,20), 0 };

    ECS::EntityID loseID = globalECS.Create();
    globalECS.Get<SpriteEnt>(loseID) = SpriteEnt{ "lose", "./assets/youlose.jpg", vec2(2000,0), vec2(0,0), vec2(100,100), 0 };

    ECS::EntityID menuID = globalECS.Create();
    globalECS.Get<SpriteEnt>(menuID) = SpriteEnt{ "menu", "./assets/Menu_black.png", vec2(-2000,0), vec2(0,0), vec2(50,50), 0 };

    globalECS.ForEach<SpriteEnt>([&](ECS::EntityID entity) {
        globalEngine.gManager.LoadAnImage(globalECS.Get<SpriteEnt>(entity).name, globalECS.Get<SpriteEnt>(entity).path);
        });
    globalEngine.sManager.LoadScript(globalECS.Get<Script>(newID).name, "./assets/firstScript.lua");
    globalEngine.RunGameLoop(callback);
    return 0;
}