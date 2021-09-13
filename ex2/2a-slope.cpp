#include<GL/glut.h>
#include<iostream>
using namespace std;

int X1, Y1, X2, Y2;

void display() 
{	
	glClear(GL_COLOR_BUFFER_BIT);
	float dx = X2-X1, dy = Y2-Y1, x, y;
	float steps = (abs(dx)>abs(dy))?dx:dy;
	steps = abs(steps);
	int i=0;
	dx/=steps; dy/=steps;
	x = X1; y = Y1;
	while(i<8*steps/9)
	{
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);
		// glColor3f(a, b, c);
		glVertex2i(x, y);
		glPointSize(10);
		glEnd();
		x += dx;
		y += dy;
		i++;
		// a+=0.01; b+=0.01; c+=0.02;
	}
	while(i<steps)
	{
		glBegin(GL_POINTS);
		glColor3f(0.5f, 0.3f, 1.0f);
		glVertex2i(x, y);
		glPointSize(10);
		glEnd();
		x += dx;
		y += dy;
		i++;
	}
	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(700, 0);
	glutInitWindowSize(750, 750);
	glutCreateWindow("EX2-LineSlope");
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	freopen("in.txt", "r", stdin);
    std::cin>>X1>>Y1;
	std::cin>>X2>>Y2;
    glutDisplayFunc(display);
	glutMainLoop();
}
