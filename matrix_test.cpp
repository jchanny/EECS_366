#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.14159265

void matrixMultiply(float matrix[][4], float coords[]);

void translateZ(float coords[], float translationAmt){
	
	float matrix[4][4];
	matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 0;
	matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0; matrix[1][3] = 0;
	matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1; matrix[2][3] = coords[2]+translationAmt;
	matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 1;

	matrixMultiply(matrix, coords);
}

void rotateX(float coords[], float angleDEG){
	//need #include <math.h> & #define PI 3.14159265
	//can change this later to adjust rotate amount
	float angle = angleDEG * PI / 180.0;


	float matrix[4][4];
	matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 0;
	matrix[1][0] = 0; matrix[1][1] = cos(angle); matrix[1][2] = (sin(angle)*-1); matrix[1][3]=0;
	matrix[2][0] = 0; matrix[2][1] = sin(angle); matrix[2][2] = cos(angle); matrix[2][3] = 0;
	matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] =1;
  
	matrixMultiply(matrix, coords);
  
}

void rotateY(float coords[], float angleDEG){
	float angle = angleDEG * PI / 180.0;


	float matrix[4][4];
	matrix[0][0] = cos(angle); matrix[0][1] = 0; matrix[0][2] = sin(angle); matrix[0][3] = 0;
	matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0; matrix[1][3] = 0;
	matrix[2][0] = (sin(angle)*-1); matrix[2][1] = 0; matrix[2][2] = cos(angle); matrix[2][3] = 0;
	matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 1;

	matrixMultiply(matrix, coords);
}

void rotateZ(float coords[], float angleDEG){
	float angle = angleDEG * PI / 180.0;

	float matrix [4][4];
	matrix[0][0] = cos(angle); matrix[0][1] = (sin(angle)*-1); matrix[0][2] = 0; matrix[0][3] = 0;
	matrix[1][0] = sin(angle); matrix[1][1] = cos(angle); matrix[1][2] = 0; matrix[1][3]=0;
	matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1; matrix[2][3] = 0;
	matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 1;

	matrixMultiply(matrix, coords);
}

//@param direction: 1 is for increase, 0 is for decrease
void scale(float coords[], float scaleAmt){

	float matrix[4][4];
	matrix[0][0] = scaleAmt; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 0;
	matrix[1][0] = 0; matrix[1][1] = scaleAmt; matrix[1][2] = 0; matrix[1][3] = 0;
	matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = scaleAmt; matrix[2][3] = 0;
	matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 1;

	matrixMultiply(matrix, coords);
}

void matrixMultiply(float matrix[][4], float coords[]){
	float x = coords[0];
	float y = coords[1];
	float z = coords[2];
	float d = coords[3];

	coords[0] = (x*matrix[0][0])+(y*matrix[0][1])+(z*matrix[0][2])+(d*matrix[0][3]);
	coords[1] = (x*matrix[1][0])+(y*matrix[1][1])+(z*matrix[1][2])+(d*matrix[1][3]);
	coords[2] = (x*matrix[2][0])+(y*matrix[2][1])+(z*matrix[2][2])+(d*matrix[2][3]);
	coords[3] = (x*matrix[3][0])+(y*matrix[3][1])+(z*matrix[3][2])+(d*matrix[3][3]);
  
}
					
int main(){
  
	float coord[4];
	coord[0] = 1; coord[1] = 1; coord[2] = 1; coord[3] = 1;
	scale(coord, .5);
	cout <<coord[0];
	cout <<"\n";
	cout <<coord[1];
	cout <<"\n";
	cout <<coord[2];
	cout <<"\n";
	cout <<coord[3];
	return 0;
}

void translateX(float coords[], float translationAmt){

	float matrix[4][4];
	matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = coords[0]+translationAmt;
	matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0; matrix[1][3] = 0;
	matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1; matrix[2][3] = 0;
	matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 1;

	matrixMultiply(matrix, coords);
}

void translateY(float coords[], float translationAmt){
	
	float matrix[4][4];
	matrix[0][0] = 1; matrix[0][1] = 0; matrix[0][2] = 0; matrix[0][3] = 0;
	matrix[1][0] = 0; matrix[1][1] = 1; matrix[1][2] = 0; matrix[1][3] = coords[1]+translationAmt;
	matrix[2][0] = 0; matrix[2][1] = 0; matrix[2][2] = 1; matrix[2][3] = 0;
	matrix[3][0] = 0; matrix[3][1] = 0; matrix[3][2] = 0; matrix[3][3] = 1;

	matrixMultiply(matrix, coords);
}
