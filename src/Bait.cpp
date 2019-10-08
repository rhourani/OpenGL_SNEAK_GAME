
#include <iostream>
#include "Bait.hpp"
#include <cstdlib>
#include <ctime>

Bait::Bait()
{
srand (static_cast <unsigned> (time(0)));
std::cout<<"yapici\n";
    m_Position = glm::vec3(0.3,0.2,0.0f);
    m_NewPosition = glm::vec3(0.0f,0.0f,0.0f);
    m_Color.r   = (std::rand()%15)/10.0;
    m_Color.g   = (std::rand()%15)/10.0;

}

glm::vec3 Bait::getNewPosition()
{
    //float x = (std::rand()%25)/14.0;
    //float y = (std::rand()%25)/14.0;
    float x = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    float y = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    m_NewPosition = glm::vec3(x/2,y/2,0.0f);
    m_Position = m_NewPosition;
}

glm::vec3 Bait::get_position()
{
    return m_Position;
}

glm::vec4 Bait::get_color()
{
    return m_Color;
}