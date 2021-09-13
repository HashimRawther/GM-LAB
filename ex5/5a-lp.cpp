#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;
int choice;

// Polygon
vector<int> pntX;
vector<int> pntY;

int transX, transY;
double scaleX, scaleY;
double angle, angleRad;

// Line
vector<int> lpntX;
vector<int> lpntY;

int ltransX, ltransY;
double lscaleX, lscaleY;
double langle, langleRad;


double round(double d)
{
	return floor(d + 0.5);
}

// line
void drawLine()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 2; i++)
	{
		glVertex2i(lpntX[i], lpntY[i]);
	}
	glEnd();
}


void drawLineTrans(int x, int y)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < 2; i++)
	{
		glVertex2i(lpntX[i] + x, lpntY[i] + y);
	}
	glEnd();
}

void drawLineScale(double x, double y)
{
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	for (int i = 0; i < 2; i++)
	{
		glVertex2i(round(lpntX[i] * x), round(lpntY[i] * y));
	}
	glEnd();
}

void drawLineRotation(double angleRad)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < 2; i++)
	{
		glVertex2i(round((lpntX[i] * cos(angleRad)) - (lpntY[i] * sin(angleRad))), round((lpntX[i] * sin(angleRad)) + (lpntY[i] * cos(angleRad))));
	}
	glEnd();
}

// Polygon
void drawPolygon()
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 1.0);
	for (int i = 0; i < 4; i++)
	{
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}

void drawPolygonTrans(int x, int y)
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < 4; i++)
	{
		glVertex2i(pntX[i] + x, pntY[i] + y);
	}
	glEnd();
}

void drawPolygonScale(double x, double y)
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	for (int i = 0; i < 4; i++)
	{
		glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
	}
	glEnd();
}

void drawPolygonRotation(double angleRad)
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < 4; i++)
	{
		glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
	}
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

    if(choice==0)
    {
        drawPolygon();
        drawPolygonTrans(transX, transY);
        if(scaleX > 1 || scaleY > 1)
        {
            drawPolygonScale(scaleX, scaleY);
            drawPolygon();
        }
        else
        {
            drawPolygonScale(scaleX, scaleY);	
        }
        drawPolygonRotation(angleRad);
    }
    else
    {
        drawLine();
        drawLineTrans(ltransX,ltransY);  
        if(lscaleX > 1 || lscaleY > 1)
        {
            drawLineScale(lscaleX, lscaleY);
            drawLine();
        }
        else
        {
            drawLineScale(lscaleX, lscaleY);	
        }
        drawLineRotation(langleRad);
    }
	glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(700, 0);
	glutInitWindowSize(750, 750);
	glutCreateWindow("5a-Geometic Transforamtion");
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);

    int i, pntX1, pntY1;
    freopen("in.txt", "r", stdin);
    cin>>choice;
    // POLYGON
    if(choice==0)
    {
        for (i = 0; i < 4; i++)
        {
            cin >> pntX1 >> pntY1;
            pntX.push_back(pntX1);
            pntY.push_back(pntY1);
        }

        cin >> transX >> transY;
        cin >> scaleX >> scaleY;
        cin >> angle;
        angleRad = angle * 3.1416 / 180;
    }
    else
    {
        for (i = 0; i < 2; i++)
        {
            cin >> pntX1 >> pntY1;
            lpntX.push_back(pntX1);
            lpntY.push_back(pntY1);
        }
            
        cin >> ltransX >> ltransY;
        cin >> lscaleX >> lscaleY;
        cin >> langle;
        langleRad = langle * 3.1416 / 180;
    }
	
	glutDisplayFunc(myDisplay);
	glutMainLoop();
	return 0;
}