//Stacks and Queues
//Copyright © 2016 TeamSQ. All rights reserved.

//tQueue.hpp

#ifndef tQueue_hpp
#define tQueue_hpp

#include <queue>

#include "Ball.hpp"

class tQueue {
private:
    std::queue<Ball> toolQueue;
    float x, y; /* Precondition: can't be RES_X or RES_Y2 */
    float width, height;
    
public:
    tQueue(float x, float y, float width, float height);
    
    //getters
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    
    int size();
    void push(Ball ball);
    void pop();
    Ball front();
    
    bool checkForSelect(float x, float y);
    void update();
    void draw();
};

#endif /* tQueue_hpp */
