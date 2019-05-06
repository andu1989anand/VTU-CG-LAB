//program to change background color and object color using menu
#include<windows.h>
#define BLACK 0
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>

float r=1,g=1,b=1,orr=1,og=0,ob=1;

void display()
{
glClearColor(r,g,b,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(orr,og,ob);
    glBegin(GL_POLYGON);
    glVertex2f(-.5,0);
    glVertex2f(0,-.5);
    glVertex2f(.5,0);
    glVertex2f(0,.5);
    glEnd();
glFlush();
glutSwapBuffers();
}
void demo(int id)
{
switch(id)
{
    case 1:
         r=1;   g=0;    b=0;
          break;

    case 2:
        r=0;   g=1;    b=0;
        break;

    case 3:
        r=0;   g=0;    b=1;
        break;

    case 4:
      r=1;   g=1;    b=1;
        break;

    case 5:
    r=0;   g=0;    b=0;
    break;

    case 6:
     r=1;   g=1;    b=0;
    break;

     case 7:
    orr=1;   og=0;    ob=0;
    break;

    case 8:
        orr=0;   og=1;    ob=0;
        break;

    case 9:
        orr=0;   og=0;    ob=1;
        break;

    case 10:
    orr=1;   og=1;    ob=1;
    break;

    case 11:
    orr=0;   og=0;    ob=0;
    break;

    case 12:
         orr=1;   og=1;    ob=0;
    break;

}
glutPostRedisplay();
}

void createmenu()
{
    int bg,obj;
    bg=glutCreateMenu(demo);
    glutAddMenuEntry("RED",1);
    glutAddMenuEntry("GREEN",2);
    glutAddMenuEntry("BLUE",3);
    glutAddMenuEntry("WHITE",4);
    glutAddMenuEntry("BLACK",5);
    glutAddMenuEntry("YELLOW",6);

    obj=glutCreateMenu(demo);
    glutAddMenuEntry("RED",7);
    glutAddMenuEntry("GREEN",8);
    glutAddMenuEntry("BLUE",9);
    glutAddMenuEntry("WHITE",10);
    glutAddMenuEntry("BLACK",11);
    glutAddMenuEntry("YELLOW",12);

    glutCreateMenu(demo);
    glutAddSubMenu("background_color",bg);
    glutAddSubMenu("object_color",obj);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("simple menu");
	glutDisplayFunc(display);
    createmenu();
    glutMainLoop();
    glEnable(GL_DEPTH_TEST);
	return 0;
}
