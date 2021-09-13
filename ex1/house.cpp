#include<GL\glut.h>

void display() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	// Grass
	glBegin(GL_QUADS);              
	glColor3f(0.54f, 0.8f, 0.4f); 
	glVertex2i(0,0);    
	glVertex2i(0,300);
	glVertex2i(1000,300);
	glVertex2i(1000,0);
	glEnd();

	// Walls
	glBegin(GL_QUADS);              
	glColor3f(0.79f, 0.25f, 0.3f); 
	glVertex2i(300,300);    
	glVertex2i(600,300);
	glVertex2i(600,600);
	glVertex2i(300,600);
	glEnd();

	// Step
	glBegin(GL_QUADS);              
	glColor3f(0.79f, 0.5f, 0.3f); 
	glVertex2i(270,280);    
	glVertex2i(630,280);
	glVertex2i(630,300);
	glVertex2i(270,300);
	glEnd();

	// Door
	glBegin(GL_QUADS);              
	glColor3f(0.79f, 0.64f, 0.44f); 
	glVertex2i(400,300);    
	glVertex2i(500,300);
	glVertex2i(500,500);
	glVertex2i(400,500);
	glEnd();

	// Doorknob
	glBegin(GL_POINTS);
	glColor3f(0.0f,0.0f,0.0f);
	glVertex2i(410,400);
	glEnd();
	glPointSize(100);

	// Window L
	glBegin(GL_QUADS);              
	glColor3f(0.5f,0.5f,0.5f); 
	glVertex2i(325,450);    
	glVertex2i(375,450);
	glVertex2i(375,500);
	glVertex2i(325,500);
	glEnd();

	// Grills
	glBegin(GL_LINES);
	glColor3f(0.1,0.1,0.1);
	glVertex2i(350,450);
	glVertex2i(350,500);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.1,0.1,0.1);
	glVertex2i(325,475);
	glVertex2i(375,475);
	glEnd();

	// Window R
	glBegin(GL_QUADS);              
	glColor3f(0.5f,0.5f,0.5f); 
	glVertex2i(525,450);    
	glVertex2i(575,450);
	glVertex2i(575,500);
	glVertex2i(525,500);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.1,0.1,0.1);
	glVertex2i(550,450);
	glVertex2i(550,500);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0.1,0.1,0.1);
	glVertex2i(525,475);
	glVertex2i(575,475);
	glEnd();

	// Roof
	glBegin(GL_POLYGON);              
	glColor3f(0.88f, 0.64f, 0.5f); 
	glVertex2i(225,600);    
	glVertex2i(675,600);
	glVertex2i(600,700);
	glVertex2i(300,700);
	glEnd();

	// Chimney
	glBegin(GL_QUADS);              
	glColor3f(0.79f, 0.25f, 0.3f); 
	glVertex2i(525,700);    
	glVertex2i(575,700);
	glVertex2i(575,770);
	glVertex2i(525,770);
	glEnd();

	glBegin(GL_QUADS);              
	glColor3f(0.5f, 0.5f, 0.5f); 
	glVertex2i(515,770);    
	glVertex2i(585,770);
	glVertex2i(585,795);
	glVertex2i(515,795);
	glEnd();

	glFlush();
}



int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500, 0);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("EX1-House");
	glClearColor(0.53, 0.7, 0.98, 1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	glutDisplayFunc(display);
	glutMainLoop();
}
