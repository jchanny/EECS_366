varying vec4 vColor;
varying vec3 vNorm;

void main(){
    if(gl_FrontFacing){
	gl_FragColor = vColor;
    }
    else
	gl_FragColor = gl_BackColor;
}
