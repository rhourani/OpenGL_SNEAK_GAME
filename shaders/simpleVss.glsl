#version 330 core
layout (location = 0) in vec3 inPosition;

uniform vec3 uMove;//Uniforms are another way to pass data from our application on the CPU to the shaders on the GPU
uniform float uLength;

void main()
{
    vec4 arapozisyon =  vec4(inPosition+uMove, 1.0);

    arapozisyon.x*=uLength;
    arapozisyon.y*=uLength;
    arapozisyon.z*=uLength;

    gl_Position = arapozisyon;
}