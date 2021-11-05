#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

int alpha=0, theta=0;
bool flag=true;

void init()
{
    glClearColor(0,0,0,1);
    glShadeModel(GL_SMOOTH);

    GLfloat mat_spec[] = {1.0,1.0,1.0,1.0};
    GLfloat mat_shin[] = {50.0};
    GLfloat light_pos[] = {1.0,1.0,1.0,1.0};

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_spec);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shin);
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void disp()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(flag)
    {
        glOrtho(-500, 500, -500, 500, -500, 500);
    }
    else
    {
        gluPerspective(100, 1, 0.1, 1000);
    }
    glMatrixMode(GL_MODELVIEW);
    glColor3f(1,1,1);
    glLoadIdentity();

    
    glRotatef(alpha, 0,1,0);

    glRotatef(theta, 1,0,0);
    // glutWireCube(100);
    // glutSolidCube(100);
    // sun
    gluLookAt(0,0,250, 0,0,0,0,1,0);
    glutSolidSphere(100, 10, 10);

    gluLookAt(0,0,-200, 50,0,80,0,1,0);
    glutSolidSphere(20, 10, 10);

    gluLookAt(0,0,400, -20,0,90,0,1,0);
    glutSolidSphere(70, 10, 10);

    gluLookAt(0,0,500, 90,0,-40,0,1,0);
    glutSolidSphere(40, 10, 10);

    gluLookAt(0,0,250, 0,0,0,0,1,0);
    // glutSolidCone(40, 100, 10, 10);
    glFlush();
}

void keypress(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_RIGHT:
        alpha++; break;

        case GLUT_KEY_LEFT:
        alpha--; break;

        case GLUT_KEY_UP:
        theta++; break;

        case GLUT_KEY_DOWN:
        theta--; break;

        case GLUT_KEY_HOME:
        flag=!flag;
    }
    glutPostRedisplay();
}

void timer(int)
{
    alpha++; theta++;
    glutPostRedisplay();
    glutTimerFunc(100, timer, 0);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_DEPTH | GLUT_RGB);
    glutInitWindowPosition(700,0);
    glutInitWindowSize(750,750);
    glutCreateWindow("3dcheck");
    // glClearColor(1,1,1,0);
    init();
    glutDisplayFunc(disp);
    // glutSpecialFunc(keypress);
    glutTimerFunc(100, timer, 0);
    glutMainLoop();
    return 0;
}