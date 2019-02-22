#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
float x1=250,y11=250,r=100;
void circle(int x, int y)
{
    glBegin(GL_POINTS);
        glVertex2f(x1+x,y11+y);
        glVertex2f(x1-x,y11+y);
        glVertex2f(x1+x,y11-y);
        glVertex2f(x1-x,y11-y);
        glVertex2f(x1+y,y11+x);
        glVertex2f(x1-y,y11+x);
        glVertex2f(x1+y,y11-x);
        glVertex2f(x1-y,y11-x);
    glEnd();
}
void Draw()
{

    GLfloat m,x,y,dx,dy,p,temp;
    glClear(GL_COLOR_BUFFER_BIT);
   p=3-2*r;
   x=0;
   y=r;

        while(x<=y)
        {
        circle(x,y);

        if(p>=0)
        {
            p=p+4*(x-y)+10;
            x=x+1;
            y=y-1;
        }
        else
        {
            p = p + 4*x+6;
            x=x+1;
        }

        }


    glFlush();
}

void MyInit()
{
   //glMatrixMode(GL_PROJECTION);
   //glLoadIdentity();
    gluOrtho2D(0,500,0,500);
    //glMatrixMode(GL_MODELVIEW);
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
   glPointSize(4.0);
}

int main(int argC,char *argV[])
{
   // printf("enter x1,y1,r:");
  //  scanf("%f%f%f",&x1,&y11,&r);
    glutInit(&argC,argV);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("Check");
    MyInit();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
