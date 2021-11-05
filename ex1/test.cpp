#include<GL\glut.h>

void display() 
{	
	glClear(GL_COLOR_BUFFER_BIT);
	
	// glBegin(GL_POINTS);
	// glColor3f(1.0f,1.0f,1.0f);
	// glVertex2i(80,950);
	// glEnd();
	// glPointSize(10);
	
	// glBegin(GL_LINES);
	// glColor3f(1.0,0.0,0.0);
	// glVertex2i(20,900);
	// glVertex2i(140,900);
	// glEnd();
	
	// glBegin(GL_LINE_STRIP);
	// glColor3f(1.0,1.0,1.0);
	// glVertex2i(20,850);
	// glVertex2i(80,850);
	// glVertex2i(80,750);
	// glVertex2i(140,750);
	// glEnd();
	
	// glBegin(GL_LINE_LOOP);
	// glColor3f(2.0,0.0,1.0);
	// glVertex2i(20,700);
	// glVertex2i(140,700);
	// glVertex2i(140,650);
	// glVertex2i(20,650);
	// glEnd();
	
	
	// glBegin(GL_TRIANGLES);
	// glColor3f(0.6,1.0,0.0);
	// glVertex2i(500,650);
	// glVertex2i(550,650);
	// glVertex2i(525,700);
	// glEnd();
	
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0f, 0.99f, 1.0f);
	glVertex2i(500,800);
	glColor3f(1.0f, 0.99f, 0.0f);
	glVertex2i(550,800);
	glColor3f(0.0f, 0.99f, 1.0f);
	glVertex2i(500,850);
	glColor3f(1.0f, 1.1f, 0.0f);
	glVertex2i(600,850);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.6f, 1.0f);
	glVertex2i(300,600);
	glVertex2i(350,700);
	glVertex2i(400,650);
	glVertex2i(400,550);
	glVertex2i(350,500);
	glEnd();

	
	// glBegin(GL_QUADS);              
	// glColor3f(0.8f, 3.0f, 0.6f); 
	// glVertex2i(500,500);    
	// glVertex2i(550,500);
	// glVertex2i(550,550);
	// glVertex2i(500,550);
	// glEnd();
	
	// glBegin(GL_QUAD_STRIP);              
	// glColor3f(2.0f, 2.0f, 0.0f);
	// glVertex2i(250,700);
	// glVertex2i(250,1000); 
	// glVertex2i(300,800);  
	// glVertex2i(300,900);  
	// glVertex2i(350,800);
	// glVertex2i(350,900);
	// glVertex2i(400,700);
	// glVertex2i(400,1000);
	// glEnd();


	// glBegin(GL_POLYGON);              
	// glColor3f(1.5f, 3.0f, 1.0f); 
	// glVertex2i(650,500);
	// glVertex2i(675,450);    
	// glVertex2i(700,500);
	// glVertex2i(700,550);
	// glVertex2i(675,600);
	// glVertex2i(650,550);
	// glEnd();

	glFlush();
}

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(1000,1000);
	glutCreateWindow("EX1-Primitives");
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 1000, 0.0, 1000);
	glutDisplayFunc(display);
	glutMainLoop();
}
