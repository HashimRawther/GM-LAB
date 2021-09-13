#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;
int choice;
int xaxis=500, yaxis=500;
char ref;
double shear;

// Polygon
vector<int> pntX;
vector<int> pntY;

double scaleX, scaleY;
double angle, angleRad;
int fx, fy;

double round(double d)
{
	return floor(d + 0.5);
}

// Polygon
void drawPolygon()
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 4; i++)
	{
		glVertex2i(xaxis+pntX[i], yaxis+pntY[i]);
	}
	glEnd();
}

void drawPolygonRotationScale()
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
    double x, y, nx, ny;
	for (int i = 0; i < 4; i++)
	{
        x = pntX[i]*scaleX; y = pntY[i]*scaleY;
        nx = (x-fx)*cos(angleRad) - (y-fy)* sin(angleRad);
        ny = (x-fx)*sin(angleRad) + (y-fy)* cos(angleRad);
		glVertex2i(xaxis+ round(nx), yaxis + round(ny));
	}
	glEnd();
}

void drawPolygonReflectShear()
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
    double x, y, nx, ny;
    shear*=-1;
    if(ref=='x')
    {
        pntY[0] *=-1;
        pntY[1] *=-1;
        pntY[2] *=-1;
        pntY[3] *=-1;
        
    }
    else if(ref=='y')
    {
        pntX[0] *=-1;
        pntX[1] *=-1;
        pntX[2] *=-1;
        pntX[3] *=-1;   
    }
	glVertex2f(xaxis+pntX[0] , yaxis+pntY[0]);
	glVertex2f(xaxis+pntX[1] , yaxis+pntY[1]);
	glVertex2f(xaxis+pntX[2] + round(pntY[2]*shear), yaxis+pntY[2]);
	glVertex2f(xaxis+pntX[3] + round(pntY[3]*shear), yaxis+pntY[3]);
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);
		glVertex2f(500, 0);
		glVertex2f(500, 1000);
	glEnd();

	// X-axis
	glBegin(GL_LINES);
		glVertex2f(0, 500);
		glVertex2f(1000, 500);
	glEnd();

    drawPolygon();
    if(choice==0)
    {       
        drawPolygonRotationScale();
    }
    else
    {
        drawPolygonReflectShear();
    }
	glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(700, 0);
	glutInitWindowSize(750, 750);
	glutCreateWindow("6a-Composite Transforamtion");
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);

    int i, pntX1, pntY1;
    freopen("in.txt", "r", stdin);
    cin>>choice;
    for (i = 0; i < 4; i++)
    {
        cin >> pntX1 >> pntY1;
        pntX.push_back(pntX1);
        pntY.push_back(pntY1);
    }
    // Rotation and scaling
    if(choice==0)
    {
        cin >> angle;
        cin >> fx >> fy;
        cin >> scaleX >> scaleY;
        
        angleRad = angle * 3.1416 / 180;
    }
    else // Reflection and Shear
    {
        cin >> ref;
        cin >> shear;
    }
	
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}