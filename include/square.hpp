#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\vec3.hpp"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\vec4.hpp"
class Square
{
    public:
    enum DIRECTION
    {
        DIR_RIGHT = 1,
        DIR_LEFT = -1,
        DIR_UP = 2,
        DIR_DOWN = -2,



    };


        Square(float x, float y, float length);

        glm::vec3 getPosition();
        glm::vec4 getColor();

        DIRECTION getDirection();

        void setDirection(DIRECTION dir);

        void move();

    private:
       
        glm::vec3 m_Position;
        glm::vec4 m_Color;
       
        float     m_Length;

        DIRECTION m_Direction;
};


#endif