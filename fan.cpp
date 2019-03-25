//simple fan
#include<windows.h>
#define BLACK 0
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>

float d=0;
float a[2][2]={{0.0,0.0},{.75,.75}};
void spin()
{
    d=d+0.00001;
    if(d>360)
        d=0;



glutPostRedisplay();
glutSwapBuffers();
//glutPostRedisplay();
}
void pillor()
{
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(-.10,-.75);
	glVertex2f(.10,-.75);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0.7,0.7);
	glVertex2f(.8,.7);
	glVertex2f(.8,.9);
	glVertex2f(.7,.9);
	glEnd();

}

void draw()
{

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(.25,.25);
	glVertex2f(0,0.5);
	glEnd();

    glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(-.25,.25);
	glVertex2f(-.5,0);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(-.25,-.25);
	glVertex2f(0,-.5);
	glEnd();

	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(.25,-.25);
	glVertex2f(.5,0);
	glEnd();


	glFlush();


}
void myit()
{
     glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);



glPushMatrix();
glRotatef(d,0,0,1);
draw();

//glPopMatrix();


//glRotatef(d,1,0,1);
pillor();



}


int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Filling a Polygon using Scan-line Algorithm");
	//myit();
	glutDisplayFunc(myit);

	glutIdleFunc(spin);
    glutMainLoop();
	return 0;
}
