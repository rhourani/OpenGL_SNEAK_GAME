#ifndef shaderProgram_HPP
#define shaderProgram_HPP


#include <string>
#include<map>
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\vec3.hpp"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\vec4.hpp"
#include "C:\Users\Radwan\Downloads\Yazilim_Staji\StajProjesi\lib\glm\include\glm\glm.hpp"


class shaderProgram
{
    public:

        shaderProgram();
        
        unsigned int m_ProgramId;

        void attachShader(const char* filename,unsigned int shaderType);

        void link();

        void use();

        void addUniform(const std::string& varName);

        void setFloat(const std::string& varName, float value);

        void setvec3(const std::string& varName, const glm::vec3& value);

        void setvec4(const std::string& varName, const glm::vec4& value);

        void setMat4(const std::string &varName, const glm::mat4& mat);


        ~shaderProgram();

    private:

   

        std::string getShaderFromFile(const char* fileName);
        std::map<std::string,unsigned int> m_UniformVars;

};


#endif