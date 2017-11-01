uniform mat4 gl_ModelViewMatrix;
uniform mat4 gl_ProjectionMatrix;
//uniform vec4 vEyePosition;

//incoming vertex being passed into the shader
//attribute = input to vertex shader
attribute vec4 gl_Vertex;
//transformed vertex (final output)
attribute vec4 gl_Position;

//varying = out of vertex shader, input for frag shader
varying vec3 n;
//view vector
varying vec3 v;
//light direction
varying vec3 l;

void main(void){
    gl_Position = ftransform();
    
}

//returns ambient term
float ambientTerm(){
}

//returns diffuse term
float diffuseTerm(){
}

//returns specular term
float specularTerm(){
}
