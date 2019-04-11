//Draw a colour cube and spin it using OpenGL transformation matrices.

#include<windows.h>
#include<stdio.h>
#include <GL/glut.h>

GLfloat Xmin=10,Xmax=50,Ymin=10,Ymax=50;
GLfloat X1=5,Y1=2,X2=70,Y2=80;

int Left=1,Right=2,Bottom=4,Top=8;
int C1,C2;
int Flag = 0,ac=1;

int Get_Code(GLfloat x,GLfloat y)
{
    int C=0;

    if(x < Xmin)
        C = C | Left;

    if(x > Xmax)
        C = C | Right;

    if(y < Ymin)
        C = C | Bottom;

    if(y > Ymax)
        C = C | Top;

    return C;
}

void Clip()
{
    GLfloat X,Y;

    int C;
    float m;
    m=(Y2-Y1)/(X2-X1);
    if(C1)
        C = C1;
    else
        C = C2;

    if(C & Left)
    {
        X = Xmin;
        Y = Y1 + m* (Xmin - X1);
    }
 if(C & Top)
    {
        Y = Ymax;
        X = X1 + (Ymax - Y1) / m;
    }
    if(C & Right)
    {
        X = Xmax;
        Y = Y1 + m * (Xmax - X1);
    }

    if(C & Bottom)
    {
        Y = Ymin;
        X = X1 +(Ymin - Y1) / m;
    }



    if(C == C1)
    {
        X1 = X;
        Y1 = Y;

    }
    else
    {
        X2 = X;
        Y2 = Y;

    }
}

void draw()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glColor3f(1,0,0);
  glBegin(GL_LINE_LOOP);
	glVertex2f(Xmin,Ymin);
	glVertex2f(Xmax,Ymin);
	glVertex2f(Xmax,Ymax);
	glVertex2f(Xmin,Ymax);
	glEnd();

if(ac){
    glColor3f(0,0,1);
    glBegin(GL_LINES);
        glVertex2f(X1,Y1);
        glVertex2f(X2,Y2);
    glEnd();
}

     glFlush();


     while(1&&Flag){
        C1=Get_Code(X1,Y1);
        C2=Get_Code(X2,Y2);

        if((C1|C2) == 0)
        {
            ac=1;
            break;
        }
        else if((C1&C2) != 0)
        {
            ac=0;
            break;
        }
        else
            Clip();
        }
    }


void Key(unsigned char ch, int x, int y)
{
   if(ch=='c')
   {
    Flag = 1;
     glutPostRedisplay();
    }
}

void init()
{
	glClearColor(1,1,1,1);
	gluOrtho2D(0.0,100.0,0.0,100.0);
}


int main(int argC, char *argV[])
{

    printf("enter endpoints of line(x1,y1) and (x1,y1)\n");
	  scanf("%f%f%f%f",&X1,&Y1,&X2,&Y2);

    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(600,600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Lab5: Cohen-Sutherland Line Clipping");

    glutDisplayFunc(draw);
    glutKeyboardFunc(Key);
    init();
    glutMainLoop();
    return 0;
}
