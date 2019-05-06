//program to show windmill rotation with menu selection
#include<windows.h>
#define BLACK 0
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>

float d=0,s=2;

float c[3]={0,0,0};//black color
void spin()
{
    d=d+0.1;
    if(d>360)
        d=0;



glutPostRedisplay();

//glutPostRedisplay();
}
void pillor()
{
    glColor3fv(c);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(-.10,-.75);
	glVertex2f(.10,-.75);
	glEnd();

	glColor3fv(c);
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

	glColor3f(0.0,0.0,0.0);
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
//glMatrixMode(GL_MODELVIEW);
//glLoadIdentity();

glPushMatrix();
pillor();
glPopMatrix();


glPushMatrix();
glRotatef(d,0,0,1);
draw();
glPopMatrix();


glPushMatrix();
glTranslated(.5,.4,0);
glScaled(s,3,0);
pillor();
glPopMatrix();


glPushMatrix();
glTranslated(.5,.4,0);
glScaled(s,3,0);
glRotatef(d,.5,0,1);
draw();
glPopMatrix();

glutSwapBuffers();
}
void demo(int id)
{
switch(id)
{
    case 1:
        c[0]=1;
        c[1]=0;
        c[2]=0;
    break;
    case 2:
        c[0]=0;
        c[1]=1;
        c[2]=0;
    break;
    case 3:
        c[0]=0;
        c[1]=0;
        c[2]=1;
    break;
    case 4: s=s+1;
    break;
    case 5: s=s-1;
    break;
    case 6: s=2;
    break;
}
glutPostRedisplay();
}

void createmenu()
{   int pil,size;
    pil=glutCreateMenu(demo);
    glutAddMenuEntry("RED",1);
    glutAddMenuEntry("GREEN",2);
    glutAddMenuEntry("BLUE",3);

    size=glutCreateMenu(demo);
    glutAddMenuEntry("Increase",4);
    glutAddMenuEntry("Decrease",5);
    glutAddMenuEntry("Normal",6);

    glutCreateMenu(demo);
    glutAddSubMenu("Pillor",pil);
    glutAddSubMenu("Wings",size);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
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
glFrustum(-1,1,-1,1,2,11);
    gluLookAt(0,1,7,0,0,0,0,1,0);
    createmenu();
	glutIdleFunc(spin);
    glutMainLoop();
	return 0;
}
