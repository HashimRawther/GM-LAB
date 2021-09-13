#include<GL/glut.h>
#include<iostream>
using namespace std;

int R, X, Y;
void pointplot(int x, int y)
{
    glBegin(GL_POINTS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2i(x+X, y+Y);
	glPointSize(10);
	glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x=0, y=R;
    int p=5/4-R;
    while(x<y)
    {
        x++;
        if(p<=0)
        {
            p += 2*x + 3;
        }
        else
        {
            y--;
            p += 2*x - 2*y + 5;
        }
        
        pointplot(x, y);
        pointplot(x, -y);
        pointplot(-x, y);
        pointplot(-x, -y);
        pointplot(y, x);
        pointplot(y, -x);
        pointplot(-y, x);
        pointplot(-y, -x);
    }
    glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(700, 0);
	glutInitWindowSize(750, 750);
	glutCreateWindow("EX4-Circle-Midpt");
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	freopen("in.txt", "r", stdin);
    std::cin>>R;
	std::cin>>X>>Y;
    glutDisplayFunc(display);
	glutMainLoop();
}