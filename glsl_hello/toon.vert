// simple toon vertex shader
// www.lighthouse3d.com

varying vec4 test;

varying vec3 normal, lightDir;

void main()
{	
	lightDir = normalize(vec3(gl_LightSource[0].position));
	normal = normalize(gl_NormalMatrix * gl_Normal);

        test = vec4(1,1,0.2,0.1);
	
	gl_Position = ftransform();
}
