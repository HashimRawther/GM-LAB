#include<GL/glut.h>
#include<iostream>
using namespace std;

int X1, Y1, X2, Y2;

void display() 
{	
	glClear(GL_COLOR_BUFFER_BIT);
	int dx = X2-X1, dy = Y2-Y1, x, y;
    x = X1; y = Y1;
    int d = 2*dy - dx;
	while(x<=8*X2/9)
	{
		glBegin(GL_POINTS);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2i(x, y);
		glPointSize(10);
		glEnd();
        if(d >= 0)
        {
            y++;
            d += 2*(dy-dx);
        }
        else
        {
            d += 2*dy;
        }
        x++;
	}
	while(x<=X2)
	{
		glBegin(GL_POINTS);
		glColor3f(0.5f, 0.3f, 1.0f);
		glVertex2i(x, y);
		glPointSize(10);
		glEnd();
        if(d >= 0)
        {
            y++;
            d += 2*(dy-dx);
        }
        else
        {
            d += 2*dy;
        }
        x++;
	}
	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(700, 0);
	glutInitWindowSize(750, 750);
	glutCreateWindow("EX3-Alphabet");
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	freopen("in.txt", "r", stdin);
    std::cin>>X1>>Y1;
	std::cin>>X2>>Y2;
    glutDisplayFunc(display);
	glutMainLoop();
}
