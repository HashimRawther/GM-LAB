#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

int x1, x2, Y1, Y2;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

   
    int i=0;
    float x=x1, y=Y1, steps, dx, dy;
    dx=x2-x1;
    dy=Y2-Y1;
    steps=abs(abs(dx)>abs(dy)?dx:dy);
    dx/=steps; dy/=steps;
    while(i<steps)
    {
        glBegin(GL_POINTS);
        glColor3f(0.2f, 0.6f, 0.7f);
        glVertex2f(x, y);
        x += dx; y+= dy;
        glEnd();
        i+=1;
    }
    

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750, 750);
    glutInitWindowPosition(700, 0);
    glutCreateWindow("INTLAB-prep");
    glClearColor(0, 0, 0, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
    freopen("in.txt", "r", stdin);
    std::cin>>x1>>Y1;
    std::cin>>x2>>Y2;
    glutDisplayFunc(display);
    glutMainLoop();
}