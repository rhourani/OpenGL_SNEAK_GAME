#include"shaderProgram.hpp"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\include\glad\glad.h"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\glm.hpp"

#include <fstream>
#include <iostream>

shaderProgram::shaderProgram()
{
    m_ProgramId=glCreateProgram();
}
shaderProgram::~shaderProgram()
{
    glDeleteProgram(m_ProgramId);
}
void shaderProgram::link()
{
    glLinkProgram(m_ProgramId);
    int ISLINKED;
    char log[512];
    glGetShaderiv(m_ProgramId,GL_LINK_STATUS,&ISLINKED);

    if(!ISLINKED)
    {
        glGetProgramInfoLog(m_ProgramId,512,0,log);
        std::cout<<"Program Linking Error:"<<std::endl<<log<<std::endl;
    }
}
void shaderProgram::use()
{
    glUseProgram(m_ProgramId);
}

void shaderProgram::addUniform(const std::string& varName)
{
    m_UniformVars[varName] = glGetUniformLocation(m_ProgramId,varName.c_str());
}

void shaderProgram::setFloat(const std::string& varName, float value)
{
    glUniform1f(m_UniformVars[varName],value);
}

void shaderProgram::setvec3(const std::string& varName, const glm::vec3& value)
{
    glUniform3f(m_UniformVars[varName],value.x,value.y,value.z);
}

void shaderProgram::setvec4(const std::string& varName, const glm::vec4& value)
{
    glUniform4f(m_UniformVars[varName],value.r,value.g,value.b,value.a);
}

void shaderProgram::setMat4(const std::string& varName, const glm::mat4& mat)
{
        glUniformMatrix4fv(m_UniformVars[varName], 1, GL_FALSE, &mat[0][0]);
}

void shaderProgram::attachShader(const char *fileName,unsigned int shaderType)
{
    unsigned int shaderId = glCreateShader(shaderType);
    
    std::string sourceCode = getShaderFromFile(fileName);

    const char* chSourceCode= &sourceCode[0];

    glShaderSource(shaderId,1,&chSourceCode,NULL);

    glCompileShader(shaderId);

    int isCompiled;
    char log[512];
    glGetShaderiv(shaderId,GL_COMPILE_STATUS,&isCompiled);

    if(!isCompiled)
    {
        glGetShaderInfoLog(shaderId,512,0,log);
        std::cout<<"shader Type:"<<shaderType<<std::endl<<log<<std::endl;

    }

    glAttachShader(m_ProgramId,shaderId);

    glDeleteShader(shaderId);

}
std::string shaderProgram::getShaderFromFile(const char*  fileName)
{
    std::ifstream file(fileName);

    std::string data;

    if(file.is_open())
    {
      
        char readChar;
        while((readChar=file.get())!=EOF)
        {
            data+=readChar;
        }
       
        file.close();
    }
    else
        std::cout<<"file couldnt open";
    
    return data;
    
}