uniform vec4 lightColor;
uniform vec3 lightPos;
uniform vec4 ambient;

varying vec3 vNorm;
varying vec3 lightVector;
varying vec4 vColor;
varying vec4 amb;
varying vec3 vPos;
varying vec4 lColor;

void main(){
    vec4 ambientProps = vec4(.19, .074, .023, 1.0);
    vec4 diffuseProps = vec4(.704,.270,.083,1.0);
    vec4 specularProps = vec4(.256,.138,.086,1.0);
    vec4 objColor = vec4(.755,.49,.095,1.0);
    gl_Position = ftransform();
    vec4 ambientTerm = ambientProps*ambient;

    vNorm = gl_NormalMatrix * gl_Normal;
    //transformed surface normal
    vec3 norm = normalize(vNorm);
    vec3 v = vec3(gl_ModelViewMatrix * gl_Vertex);
    vec3 l = normalize(lightPos -v);
    lightVector = l;
    vec3 e = normalize(-v);
    vec3 r = normalize(-reflect(l,norm));

    float nDh = dot(norm, e);
    float nDv = dot(norm, v);
    float vDh = dot(v, e);
    float nDl = dot(norm, l);
    float two = 2.0;
    float temp1 =(two*nDh*nDv);
    temp1 = temp1/ vDh;
    float temp2 = (two*nDh*nDl);
    temp2 = temp2/vDh;
    float gt = min(temp1, temp2);
    float g = min(1,gt);

    float four = 4.0;
    /* float rS = g/(four*nDl*nDv);  */

   amb = ambientProps;
    vPos = v;
    lightVector = l;
    lColor = lightColor;
    vec4 rD = vec4(.755,.49,.095,1.0);
    vec4 rS = 3.14*rD;

    float s = .1; 
    
    vec4 everythingElse = lightColor*nDl*(s*rD +(1.0-s)*rS); 
    vColor = objColor*(ambientTerm + everythingElse);
    gl_FrontColor = vColor;
} 
