uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec4 ambient;

varying vec3 vNorm;
varying vec3 lightVector;
varying vec4 vColor;
//new additions
varying vec4 amb;
varying vec3 vPos;
varying vec4 lColor;

void main(){
    vec4 ambientColor = vec4(.19,.074,.023,1.0);
    vec4 ambientTerm = ambient*ambientColor;
    vec4 objColor = vec4(.755,.49,.095,1.0);
    
    gl_Position = ftransform();
    
    vNorm = gl_NormalMatrix * gl_Normal;
    //transformed surface normal
    vec3 norm = normalize(vNorm);
    //vertex in model view space
    vec3 v = vec3(gl_ModelViewMatrix * gl_Vertex);
    
    //light vector
    vec3 l = normalize(lightPos - v);
    vec3 e = normalize(-v);
    //reflect vector
    vec3 r = normalize(-reflect(l,norm));

    /*add to cook torance*/
    amb = ambientColor;
    vPos = v;
    lightVector = l;
    lColor = lightColor;
    /*END ADD*/
    
    //diffuse stuff
    vec4 diffuseProps = vec4(.704,.270,.083,1.0);
    vec4 diffuseTerm = lightColor*diffuseProps*max(dot(norm,l), 0.0);

    //specular
    vec4 specularProps = vec4(.256,.138,.086,1.0);
    vec4 specTerm = specularProps* pow(max(dot(r,e),0.0), 12.8);
    vColor = objColor*(ambientTerm+diffuseTerm+specTerm);
    gl_FrontColor = vColor;
}
