uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec4 ambient;

varying vec3 vNorm;
varying vec3 lightVector;

void main(){
    gl_Position = ftransform();
    vNorm = gl_NormalMatrix * gl_Normal;
    vec4 transformVertex = gl_ModelViewMatrix * gl_Vertex;
    lightVector = lightPos;
 
    vec4 diffuseColor = lightColor;
    vec3 norm = normalize(vNorm);
    vec3 nlightVector = normalize(lightVector);
    float diffuse = clamp(dot(vNorm, lightVector), 0.0, 1.0);
    gl_FrontColor = ambient + (diffuseColor*diffuse);
}
