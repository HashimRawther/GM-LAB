#include<bits/stdc++.h>
#include<GL/glut.h>

int bx=250, by=250,ang=30;
void drawpt(float x, float y)
{
    glBegin(GL_POINTS);
    glVertex2f(x,y);
    glEnd();
}

void dda(float X1, float Y1, float X2, float Y2)
{
    float dx=X2-X1, dy=Y2-Y1, x=X1, y=Y1;
    float i=0, steps=abs(dx)>abs(dy)?abs(dx):abs(dy);
    dx/=steps; dy/=steps;
    while(i<steps)
    {
        glColor3f(0.3, 0.5, 0.1);
        drawpt(x,y);
        x+=dx; y+=dy;
        i++;
    }
}

void midpt(float X, float Y, float R)
{
    float x=0, y=R, p=5/4-R;
    glColor3f(0.6,0.5,0.2);
    while(x<y)
    {
        x++;
        if(p<=0)
        {
            p+=2*x+3;
        }
        else
        {
            y--;
            p+=2*x-2*y+5;
        }
        drawpt(X+x,Y+y);
        drawpt(X-x,Y+y);
        drawpt(X+x,Y-y);
        drawpt(X-x,Y-y);
        drawpt(X+y,Y+x);
        drawpt(X-y,Y+x);
        drawpt(X+y,Y-x);
        drawpt(X-y,Y-x);

    }
}

void bres(float X1, float Y1, float X2, float Y2)
{
    float x=X1, y=Y1, e, dx=X2-X1, dy=Y2-Y1, incx, incy, inc1, inc2;
    incx=X2>X1?1:-1; incy=Y2>Y1?1:-1;
    glColor3f(0.4, 0.2, 0.0);
    if(dx>dy)
    {
        drawpt(x,y);
        e=2*dy-dx;
        inc1=2*(dy-dx);
        inc2=2*dy;
        for(int i=0; i<dx; i++)
        {
            if(e>=0)
            {
                y+=incy;
                e+=inc1;
            }
            else
            {
                e+=inc2;
            }
            x+=incx;
            drawpt(x,y);
        }
        
    }
    else
    {
        drawpt(x,y);
        e=2*dx-dy;
        inc1=2*(dx-dy);
        inc2=2*dx;
        for(int i=0; i<dy; i++)
        {
            if(e>=0)
            {
                x+=incx;
                e+=inc1;
            }
            else
            {
                e+=inc2;
            }
            y+=incy;
            drawpt(x,y);
        }
        
    }
}

void splkey(int key, int x, int y)
{
    float rad=3.14*ang/180;
    switch(key)
    {
        case GLUT_KEY_LEFT:
        bx=250*cos(rad)-250*sin(rad);
        by=250*sin(rad)+250*cos(rad);
        break;

        case GLUT_KEY_RIGHT:
        bx=250*cos(-rad)-250*sin(-rad);
        by=250*sin(-rad)+250*cos(-rad);
        break;
    }
    ang+=5;
    glutPostRedisplay();
}

void timer(int)
{
    ang+=5;
    float rad=3.14*ang/180;

    bx=250*cos(rad)-250*sin(rad);
    by=250*sin(rad)+250*cos(rad);
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

void disp()
{
    glClear(GL_COLOR_BUFFER_BIT);
    midpt(0,0,70);
    dda(0,0,bx,by);
    dda(0,0,bx,-by);
    dda(0,0,-bx,-by);
    dda(0,0,-bx,by);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(700,0);
    glutInitWindowSize(750, 750);
    glutCreateWindow("ttt");
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-500,500,-500,500);
    glutDisplayFunc(disp);
    glutSpecialFunc(splkey);
    // glutTimerFunc(100,timer,0);
    glutMainLoop();
    return 0;
}