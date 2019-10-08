#ifndef CIRCLE_HPP   
#define CIRCLE_HPP
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\vec3.hpp"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\vec4.hpp"
#include <string>
#include<map>

class Circle
{
public:

enum DIRECTION
    {
        DIR_RIGHT = 1,
        DIR_LEFT = -1,
        DIR_UP = 2,
        DIR_DOWN = -2,
    };


Circle(float x, float y, float length);

        glm::vec3 getPosition();
        glm::vec4 getColor();

        DIRECTION getDirection();

        void setDirection(DIRECTION dir);

        void move();

        void drawCircle();
        
        glm::vec3 vertices[1080]; 


    private:
       
        glm::vec3 m_Position;
        glm::vec4 m_Color;

       
        float     m_Length;

        DIRECTION m_Direction;

     
};






#endif