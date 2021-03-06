//Stacks and Queues
//Copyright © 2016 TeamSQ. All rights reserved.

//Ball.cpp

#include "Ball.hpp"

Ball::Ball(int num, float x, float y, float vx, float vy, float radius, sf::Color color, sf::String label) {
    
    this->num = num;
    this->x = x;
    this->y = y;
    this->vx = vx;
    this->vy = vy;
    this->radius = radius;
    dia = radius*2;
    this->color = color;
    this->label = label;
    
    isActive = true;
    isMoving = false;
    isOnScreen = false;
    isPushed = false;
    isTopped = false;
    
    if(num == 0) isSelected = true;
    else isSelected = false;
    selectColor = sf::Color::Green;
    currDirection = 1;
    nextDirection = 1;
}

float Ball::getX() {
    return x;
}

void Ball::setX(float x) {
    this->x = x;
}

float Ball::getY() {
    return y;
}

float Ball::getRadius() {
    return radius;
}

string Ball::getLabel() {
    return label;
}

bool Ball::checkOnScreen() {
    if (x < -(radius) || y < -(radius) || x > RES_X + x || y > RES_Y + y) {
        return false;
    }
    return true;
}

void Ball::changeDirection(int nextDirection) {
    this->nextDirection = nextDirection;
}

void Ball::select() {
    isSelected = true;
}

void Ball::deselect() {
    isSelected = false;
}

void Ball::toggleisTopped() {
    if(isTopped) isTopped = false;
    else isTopped = true;
}

void Ball::ballOut() {
    move();
    isPushed = false;
    isTopped = false;
}

bool Ball::onPath(float x, float y) {
    for(int i=0; i<pathCoords.size(); i = i+5) {
        if(x >= pathCoords.at(i) && y >= pathCoords.at(i+1) && x <= pathCoords.at(i+2) && y <= pathCoords.at(i+3) && nextDirection == (int) pathCoords.at(i+4)) return true;
    }
    return false;
}

int Ball::searchPath(float x, float y) {
    for(int i=0; i<pathCoords.size(); i = i+5) {
        int pathCoordsi4 = (int)pathCoords.at(i+4);
        if(pathCoordsi4 != currDirection) {
            switch(pathCoordsi4) {
                case 1: if((x-radius) >= pathCoords.at(i) && y >= pathCoords.at(i+1) && (x-radius) <= pathCoords.at(i+2) && y <= pathCoords.at(i+3)) return 1;
                case 2: if(x >= pathCoords.at(i) && (y-radius) >= pathCoords.at(i+1) && x <= pathCoords.at(i+2) && (y-radius) <= pathCoords.at(i+3)) return 2;
                case 3: if(x >= pathCoords.at(i) && (y+radius) >= pathCoords.at(i+1) && x <= pathCoords.at(i+2) && (y+radius) <= pathCoords.at(i+3)) return 3;
            }
        }
    }
    return nextDirection;
}

//TODO: make more efficient?
void Ball::move() {
    //1 = left, 2 = up, 3 = down, can't go right
    //check for incomnig white first
    if(currDirection == nextDirection) {
        switch(currDirection) {
            case 1: if(!(onPath(x-radius, y))) { nextDirection = searchPath(x, y); } break;
            case 2: if(!(onPath(x, y-radius))) { nextDirection = searchPath(x, y); } break;
            case 3: if(!(onPath(x, y+radius))) { nextDirection = searchPath(x, y); } break;
            default: ; //do nothing
        }
    }
    
    if(currDirection != nextDirection) {
        //cout << "Ball " << num << " curr = " << currDirection << " next = " << nextDirection << "\n";
        //try turning
        switch(nextDirection) {
            case 1: if(onPath(x-dia, y)) currDirection = nextDirection; break;
            case 2: if(onPath(x, y-dia)) currDirection = nextDirection; break;
            case 3: if(onPath(x, y+dia)) currDirection = nextDirection; break;
            default: ; //do nothing
        }
    }
    switch(currDirection) {
        case 1: x -= vx; break;
        case 2: y -= vy; break;
        case 3: y += vy; break;
        default: ; //do nothing
    }
}
//TODO: make more efficient?

void Ball::update(bool status) {
    if(!isActive) return;
    
    isOnScreen = checkOnScreen();
    
    isMoving = status;
    if(isPushed || isTopped) isMoving = false;
    else isMoving = true;
    if(!isMoving) return;
    
    //cout << "from Ball.cpp: Ball " << num << " isPushed: " << isPushed << "isMoving" << isMoving << ".\n";
    move();
    
    if (x <= -(radius)) {
       isActive = false;
    }
}

void Ball::draw() {
    if(!isOnScreen || !isActive || (isPushed && !isTopped)) return;
    
    sf::Color drawColor;
    
    if(isSelected) drawColor = selectColor;
    else drawColor = color;
    
    sf::CircleShape ballCircle;
    ballCircle.setFillColor(drawColor);
    ballCircle.setRadius(radius);
    ballCircle.setPosition(x, y);
    ballCircle.setOrigin(radius, radius);
    
    //place label on ball
    // Declare and load a font
    sf::Font ballFont;
    ballFont.loadFromFile(rPath + "sansation.ttf");
    // Create a text
    sf::Text ballText(label, ballFont);
    ballText.setCharacterSize(dia);
    ballText.setStyle(sf::Text::Bold);
    ballText.setColor(sf::Color::White);
    ballText.setOrigin(ballCircle.getOrigin());
    ballText.setPosition(x + radius/2.0, y - radius/3.0);
    
    //cout << "Ball " << label << " at(" << x << ", " << y << ")\n";
    
    window->draw(ballCircle);
    window->draw(ballText);
}
