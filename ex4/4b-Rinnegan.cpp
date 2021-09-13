#include<GL/glut.h>
#include<iostream>
using namespace std;

int R, X, Y;

void pointplot(int x, int y, float r=0.50, float g=0.0, float b=0.60)
{
    glBegin(GL_POINTS);
	glColor3f(r, g, b);
	glVertex2i(x+X, y+Y);
	glPointSize(10);
	glEnd();
}

void pattern(int r, int flag=0)
{
    int x=0, y=r;
    int p=5/4-r;
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
        if(flag == 1)
        {
            pointplot(x, y, 0.0, 0.0, 0.0);
            pointplot(x, -y, 0.0, 0.0, 0.0);
            pointplot(-x, y, 0.0, 0.0, 0.0);
            pointplot(-x, -y, 0.0, 0.0, 0.0);
            pointplot(y, x, 0.0, 0.0, 0.0);
            pointplot(y, -x, 0.0, 0.0, 0.0);
            pointplot(-y, x, 0.0, 0.0, 0.0);
            pointplot(-y, -x, 0.0, 0.0, 0.0);   
        }
        else
        {
            pointplot(x, y);
            pointplot(x, -y);
            pointplot(-x, y);
            pointplot(-x, -y);
            pointplot(y, x);
            pointplot(y, -x);
            pointplot(-y, x);
            pointplot(-y, -x);
        }     
    }
}


void display()
{
    int r=300, t;
    glClear(GL_COLOR_BUFFER_BIT);
    // purple
    while(R != 60)
    {
        pattern(R--);
    }
    // black ring
    while(r > 60)
    {
        r -= 30;
        t=r-10;
        while(r != t)
        {
            pattern(r--, 1);
        }
    }

    glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(700, 0);
	glutInitWindowSize(750, 750);
	glutCreateWindow("EX4-Rinnegan");
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	freopen("in.txt", "r", stdin);
    std::cin>>R;
	std::cin>>X>>Y;
    glutDisplayFunc(display);
	glutMainLoop();
}