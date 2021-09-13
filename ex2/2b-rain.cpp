#include<GL/glut.h>
#include<iostream>
using namespace std;

void rainRandom(int X1, int Y1, int X2, int Y2)
{
    float dx = X2-X1, dy = Y2-Y1, x, y;
	float steps = (abs(dx)>abs(dy))?dx:dy;
	steps = abs(steps);
	int i=0;
	dx/=steps; dy/=steps;
	x = X1; y = Y1;
	while(i<steps)
	{
		glBegin(GL_POINTS);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2i(x, y);
		glPointSize(10);
		glEnd();
		x += dx;
		y += dy;
		i++;
	}
}
void display() 
{	
	glClear(GL_COLOR_BUFFER_BIT);
    int i=0, X1=30, Y1=30, X2=100, Y2=150;
    while(i != 20)
    {
        // rainRandom((X1+rand())%200, (Y1+rand())%200, 200+(X2+rand())%600, 200+(Y2+rand())%600);
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
	glutCreateWindow("EX2-Rain");
	glClearColor(0.7,0.7,0.7,0.5);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);
    glutDisplayFunc(display);
	glutMainLoop();
}
