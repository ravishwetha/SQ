//Stacks and Queues
//Copyright © 2016 TeamSQ. All rights reserved.

//LevelScreen.h

#ifndef LevelScreen_h
#define LevelScreen_h

#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <list>

#include "Globals.hpp"

class LevelScreen
{
public:
    enum LevelSelect{Nothing, Exit, lvl1, lvl2, lvl3, Exitpage};
    
    struct ScreenItem
    {
    public:
        sf::Rect<float> rect;
        LevelSelect action;
    };
    //Types: 2 is level select screen, 3 is help page
    LevelSelect Show(sf::RenderWindow& window, int type);
    
private:
    int type;
    LevelSelect GetResponse(sf::RenderWindow& window);
    LevelSelect HandleClick(int x, int y);
    std::vector<ScreenItem> ScreenItems;
    
    void drawLocks(sf::RenderWindow& window);
};

#endif /* LevelScreen_h */
