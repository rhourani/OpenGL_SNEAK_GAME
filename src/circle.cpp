#include <iostream>
#include "circle.hpp"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\include\glad\glad.h"
#include <fstream>
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\mat4x4.hpp"

//draw circle
//circle
float alfa=1;
float triAngCount=360/alfa; //üçgen sayısı
float vertexCount=triAngCount*3; //nokta sayısı
float lengthR=0.08;
glm::vec3 center(0.0, 0.0,0.0);
 float degtorad(float angle)
 {
     return angle * 3.141592653589793 / 180.0;

 }

//just to give draw points to us
void Circle::drawCircle()
{
    for(int i=0; i<triAngCount;i++)
    {
        float currentAng=degtorad(i*alfa); //1. nokta
        float x1=lengthR*cos(currentAng);
        float y1=lengthR*sin(currentAng);
       
        currentAng=degtorad((i+1)*alfa); //2. nokta
        float x2=lengthR*cos(currentAng);
        float y2=lengthR*sin(currentAng);

        vertices[i*3]=center;//3.nokta
        vertices[i*3+1] = glm::vec3(x1,y1,0.0); //1.nokta
        vertices[i*3+2] = glm::vec3(x2,y2,0.0); //2. nokta diziye eklendi

    }

}

Circle::Circle(float x, float y, float length)
{
    m_Position = glm::vec3(x,y,0.0f);

    m_Color.r   = (std::rand()%25/25.0);
    m_Color.g   = (std::rand()%25/25.0);

    m_Direction = DIR_RIGHT;

    m_Length    =length;
}



glm::vec3 Circle::getPosition()
{
    return m_Position;
}

glm::vec4 Circle::getColor()
{
    return m_Color;
}



void Circle::move()
{
    switch(m_Direction)
    {
        case DIR_LEFT:
            m_Position-=glm::vec3(m_Length,0.0f,0.0f);
        break;

        case DIR_RIGHT:
            m_Position+=glm::vec3(m_Length,0.0f,0.0f);
        break;

        case DIR_UP:
            m_Position+=glm::vec3(0.0f,m_Length, 0.0f);
        break;

        case DIR_DOWN:
            m_Position-=glm::vec3(0.0f,m_Length, 0.0f);
        break;
    }
}



    Circle::DIRECTION Circle::getDirection()
    {
        return m_Direction;
    }

 void Circle::setDirection(Circle::DIRECTION dir)
 {
     m_Direction = dir;
 }
