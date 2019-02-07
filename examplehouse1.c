/*8. Program to draw a color cube and allow the user to move the camera suitably to experiment with perspective viewing. Use OpenGL functions.*/
#include<windows.h>
//#include<GL/gl.h>
//#include<GL/glu.h>
#include<GL/glut.h>

void display()
{

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1,0,0,0);
    //gluOrtho2D(-1,1,-1,4);
   // gluOrtho2D(-.5,5,-2,2);
    glBegin(GL_POLYGON); //base
    glColor3f(1,1,1);
    glVertex2f(0,0);
    glVertex2f(-.5,0);
    glVertex2f(-.5,-.5);
    glVertex2f(0,-.5);
    glEnd();

glBegin(GL_POLYGON); //door
    glColor3f(1,0,1);
    glVertex2f(-.15,-.5);
    glVertex2f(-.35,-0.5);
    glVertex2f(-.35,-.3);
    glVertex2f(-.15,-.3);
    glEnd();

    glBegin(GL_POLYGON); //roof
    glColor3f(0,1,0);
    glVertex2f(0,0);
    glVertex2f(-.25,.4);
    glVertex2f(-.5,0);
    glEnd();

	glFlush();

}



int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(10,10);
	glutInitWindowSize(400,800);
	glutCreateWindow("HOUSE");
	glutDisplayFunc(display);
	glutMainLoop();
}
