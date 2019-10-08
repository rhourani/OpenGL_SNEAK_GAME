#ifndef BAIT_HPP
#define BAIT_HPP

#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\vec3.hpp"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\vec4.hpp"

class Bait
{
public:
    Bait();

    glm::vec3 get_position();
    glm::vec3 getNewPosition();
    glm::vec4 get_color();

private:
    glm::vec3 m_Position;
    glm::vec3 m_NewPosition;
    glm::vec4 m_Color;
};



#endif