

#include <iostream>
#include <vector>
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\include\glad\glad.h"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glfw\include\GLFW\glfw3.h"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\mat4x4.hpp"

#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\glm.hpp"

#include "square.hpp"
#include "circle.hpp"
#include "Bait.hpp"
#include <windows.h>
#include <cmath> 
#include "shaderProgram.hpp"



using namespace std;

void addToSnakeTail();
void sleep(unsigned milliseconds)
    {
        Sleep(milliseconds);
    }

std::vector<Circle*> snakeList;


unsigned int VBO;
unsigned int VAO;
unsigned int EBO;
float lengthRm=0.05;//important for drawing circle the same variable at circle.cpp please make sure to notice and be the two variable same always.
Bait b;


/*float lenght = 0.08;
//kare
float verticess[] = {
    -lenght/2,  lenght/2,0.0f,
    -lenght/2, -lenght/2,0.0f,
     lenght/2, -lenght/2,0.0f,

    -lenght/2,  lenght/2,0.0f,
     lenght/2, -lenght/2,0.0f,
     lenght/2,  lenght/2,0.0f

};*/
void SnakesBait(shaderProgram& program)
{
        
        program.setvec3("uMove",b.get_position());
        program.setvec4("uColor", b.get_color());
        glDrawArrays(GL_TRIANGLES, 0, 1080);
}

void CollisionTest()
{
    for(int i=1;i<snakeList.size()-1;i++)
   {
       if(snakeList[0]->getPosition() == snakeList[i]->getPosition() )
       {
          MessageBox(NULL, "Game Over!", "Example", 0);
             exit(0); // gameover
       }

   }
    glm::vec3 windowPos= glm::vec3(0.75,0.75,0.0);
    glm::vec3 windowNeg= glm::vec3(-0.75,-0.75,0.0);
    
    
    if(snakeList[0] -> getPosition().x >= windowPos.x ||
       snakeList[0] -> getPosition().x <= windowNeg.x || 
       snakeList[0] -> getPosition().y >= windowPos.y ||
       snakeList[0] -> getPosition().y <= windowNeg.y )
    {
        MessageBox(NULL, "Game Over!", "Example", 0);
        exit(0);
    }

    if(   abs(snakeList[0] -> getPosition().x - b.get_position().x) <  0.09   &&
        abs(snakeList[0] -> getPosition().y - b.get_position().y) <  0.09      )
    {
        addToSnakeTail();
        b.getNewPosition();
        
    }

}

void moveSnake()
{
    CollisionTest();
    for(auto next:snakeList)
      {
        next->move();
      } 

    for(int i=snakeList.size()-1;i>0;i--)
    {
        snakeList[i]->setDirection(snakeList[i-1]->getDirection());
    }

}

void drawSnake(shaderProgram& program)
{

    for(auto next:snakeList)
    {
        program.setvec3("uMove",next->getPosition());
        program.setvec4("uColor",next->getColor());
        program.setFloat("uLength",1);
        glDrawArrays(GL_TRIANGLES, 0, 1080);
    }

}

void addToSnakeTail()
{
    int elementCount = snakeList.size();

    if(elementCount==0)
        {
            snakeList.push_back(new Circle(0.0f,0.0f,lengthRm));
        }
    else
    {
        Circle* lastCircle = snakeList[elementCount-1];

        glm::vec3 pos = lastCircle->getPosition();

        Circle::DIRECTION dir=lastCircle->getDirection();

        switch(dir)
        {
            
            case Circle::DIR_RIGHT:
           
                 pos-=glm::vec3(lengthRm, 0.0f, 0.0f);
                 break;

            case Circle::DIR_LEFT:
                pos+=glm::vec3(lengthRm, 0.0f, 0.0f);
                break;

            case Circle::DIR_UP:
                pos-=glm::vec3(0.0f, lengthRm, 0.0f);
                 break;

            case Circle::DIR_DOWN:
                pos+=glm::vec3(0.0f, lengthRm, 0.0f);
                break;
        }

        Circle* newCircle = new Circle(pos.x,pos.y,lengthRm);

        newCircle->setDirection(dir);

        snakeList.push_back(newCircle);
    }
}



void key_callback(GLFWwindow* window, int key, int scancde, int action, int mods)
{
    if (key==GLFW_KEY_ESCAPE)
        glfwTerminate();

        if(action==GLFW_PRESS)
        {
            if(snakeList.size()!=0)
            {
                Circle* first = snakeList[0];

                if(key==GLFW_KEY_LEFT)
                {
                   first->setDirection(Circle::DIR_LEFT);
                }
                if(key==GLFW_KEY_RIGHT)
                {
                    first->setDirection(Circle::DIR_RIGHT);
                }

                if(key==GLFW_KEY_UP)
                {
                    first->setDirection(Circle::DIR_UP);
                }

                if(key==GLFW_KEY_DOWN)
                {
                    first->setDirection(Circle::DIR_DOWN);
                }
            }

            /*if(key==GLFW_KEY_SPACE)
                addToSnakeTail();*/
        }
}

int main(int argc,char**argv)
{
    Circle circleObj(0.0f,0.0f,lengthRm);
    // glfw: initialize and configure
    // ------------------------------
    if (!glfwInit())
      return -1;
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    // glfw window creation
    // --------------------
    // settings
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 800;
    GLFWwindow* window=glfwCreateWindow(SCR_WIDTH,SCR_HEIGHT,"İlk Programım",NULL,NULL);
    if(window==NULL)
    {
        cout<<"Pencere Olusturulamadı"<<endl;
        glfwTerminate();//closing the window
        return -1;
    }

    glfwSetKeyCallback(window,key_callback);
    glfwMakeContextCurrent(window);
    
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        cout<<"Failed to initialize GLAD"<<endl;
        return -1;
    }

        addToSnakeTail();
        addToSnakeTail();
        addToSnakeTail();

        Circle arkaPlan(0.0f,0.0f,lengthRm);
        

    shaderProgram program;
    program.attachShader("./shaders/simpleVss.glsl",GL_VERTEX_SHADER);
    program.attachShader("./shaders/simpleFss.glsl",GL_FRAGMENT_SHADER);
    program.link();

    circleObj.drawCircle();

    program.addUniform("uMove");
    program.addUniform("uColor");
    program.addUniform("uLength");



  //program nesnesi hazır--------------------
    glGenVertexArrays(1, &VAO);
  //vertex buffer nesnesi olusturuldu
    glGenBuffers(1,&VBO);
    
 // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);


    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);//vertex buffer nesnesi aktif edildi.
    glBufferData(GL_ARRAY_BUFFER,sizeof(circleObj.vertices),circleObj.vertices,GL_STATIC_DRAW);//vertex buffer'a nokta bilgileri yollaniyour


    //position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);




    while(!glfwWindowShouldClose(window))
    {

        //resim Boyaniyour
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

       // draw our first triangle
        program.use();

        glBindVertexArray(VAO);// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

        program.setvec4("uColor", arkaPlan.getColor());
        program.setvec3("uMove",arkaPlan.getPosition());
        program.setFloat("uLength",10);
        glDrawArrays(GL_TRIANGLES, 0, 1080);
        
        drawSnake(program);
        SnakesBait(program);
        moveSnake();
sleep(70);
       /* if(snakeList.size()<10)
        {
            sleep(300);
        }
        else if(snakeList.size()<20)
        {
            sleep(250);
        }
        else if(snakeList.size()<30)
        {
            sleep(200);
        }
        else if(snakeList.size()<40)
        {
            sleep(150);
        }
        else
        {
            sleep(100);
        }*/
        

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
       
    }

}