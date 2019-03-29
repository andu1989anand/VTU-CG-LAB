#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
float x1,y11,x2,y2;
void Draw()
{

    GLfloat m,x,y,dx,dy,p,temp;
    glClear(GL_COLOR_BUFFER_BIT);
    m = (y2-y11) / (x2-x1);
    if(fabs(m)<1)
    {
        if(x1>x2)
        {
            temp = x1;
            x1 = x2;
            x2 = temp;

            temp = y11;
            y11 = y2;
            y2 = temp;
        }
        dx = fabs(x2 - x1);
        dy = fabs(y2 - y11);
        x=x1;
        y=y11;
        p = 2*dy-dx;
        while(x<=x2)
        {
        glBegin(GL_POINTS);
            glVertex2f(x,y);
        glEnd();
        printf("m less than 1  ");
        printf("%f %f\n",x,y);
        x=x+1;
        if(p>=0)
        {
            if(m>=1)
                y=y+1;
            else
                y=y-1;
            p = p + 2*dy-2*dx;
        }
        else
        {
            y=y;
            p = p + 2*dy;
        }
        }
    }
    if(fabs(m)>=1)
    {
        if(y11>y2)
        {
            temp = x1;            x1 = x2;            x2 = temp;
            temp = y11;            y11 = y2;            y2 = temp;
        }

        dx = fabs(x2 - x1);
        dy = fabs(y2 - y11);
        x=x1;
        y=y11;
        p = 2*dx-dy;
        while(y<=y2)
        {
        glBegin(GL_POINTS);
            glVertex2f(x,y);
        glEnd();
        printf("m greater than 1  ");
        printf("%f %f\n",x,y);
        y=y+1;
        if(p>=0)
        {
            if(m>=1)
                x=x+1;
            else
                x=x-1;
            p = p + 2*dx-2*dy;
        }
        else
        {
            x=x;
            p = p + 2*dx;
        }

        }
    }
    glFlush();
}

void MyInit()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-20,50,-20,50);
    //glMatrixMode(GL_MODELVIEW);
    glClearColor(1,1,1,1);
    glColor3f(1,0,0);
    glPointSize(14.0);
}

int main(int argC,char *argV[])
{
    printf("enter x1,y1,x2,y2:");
    scanf("%f%f%f%f",&x1,&y11,&x2,&y2);
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
