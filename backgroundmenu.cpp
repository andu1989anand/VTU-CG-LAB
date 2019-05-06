//program to change background color using menu
#include<windows.h>
#define BLACK 0
#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>

float r=1,g=1,b=1;
void display()
{
glClearColor(r,g,b,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glutPostRedisplay();
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
    case 4: r=1;   g=1;    b=1;
    break;
    case 5: r=0;   g=0;    b=0;
    break;
    case 6: r=1;   g=1;    b=0;
    break;
}
glutPostRedisplay();
}

void createmenu()
{
    glutCreateMenu(demo);
    glutAddMenuEntry("RED",1);
    glutAddMenuEntry("GREEN",2);
    glutAddMenuEntry("BLUE",3);
    glutAddMenuEntry("WHITE",4);
    glutAddMenuEntry("BLACK",5);
    glutAddMenuEntry("YELLOW",6);


    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc,char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("simple menu");
	//myit();
	glutDisplayFunc(display);
    createmenu();
    glutMainLoop();
	return 0;
}
