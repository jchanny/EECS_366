uniform mat4 gl_ModelViewMatrix;
uniform mat4 gl_ProjectionMatrix;
//uniform vec4 vEyePosition;

//incoming vertex being passed into the shader
//attribute = input to vertex shader
attribute vec4 gl_Vertex;
//transformed vertex (final output)
attribute vec4 gl_Position;
//gl_Color is whatever color the vertex is
attribute vec4 gl_Color;

//varying = out of vertex shader, input for frag shader
varying vec3 n;
//view vector
varying vec3 v;
//light direction
varying vec3 l;
varying vec4 gl_FrontColor;
varying vec4 gl_BackColor;

void main(void){
    gl_Position = ftransform();
    /*FOR TESTING ONLY*/
    gl_FrontColor = vec4(0.4,0.0,0.9,1.0);
    
    /*THIS IS THE ACTUAL CODE
      gl_FrontColor = gl_Color;*/

    //now perform actual coloring changes here
}

//returns ambient term
float ambientTerm(){
    return 0;
}

//returns diffuse term
float diffuseTerm(){
    return 0;
}

//returns specular term
float specularTerm(){
    return 0;
}
