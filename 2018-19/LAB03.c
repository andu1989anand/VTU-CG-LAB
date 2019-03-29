//Rotating Color cube

#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<stdio.h>


float V[][3]={{0,0,0},{0,0.5,0},{.5,.5,0},{.5,0,0},{0,0,.5},{0,.5,.5},{.5,.5,.5},{.5,0,.5}};
float color[][3]={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,0,1},{0,0,0},{.5,0,.5}};
GLfloat r,d=0;
char a;
int i;
float nV[8][3];

void spin()
{
    d=d+1;
    if (d>360)
        d=0;
    glutPostRedisplay();
}

void drawpoly(int a,int b,int c, int d)
{

	glBegin(GL_POLYGON);
	//glColor3fv(color[a]);
	glVertex3fv(nV[a]);
	//glColor3fv(color[b]);
	glVertex3fv(nV[b]);
	//glColor3fv(color[c]);
	glVertex3fv(nV[c]);
	//glColor3fv(color[d]);
	glVertex3fv(nV[d]);
	glEnd();
	glFlush();

}

void draw()
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

r = d*3.14/180;
    if(a=='x')
    {
       for(i=0;i<8;i++)
    {
        nV[i][0] = V[i][0];
        nV[i][1] = V[i][1]*cos(r)-V[i][2]*sin(r);
        nV[i][2] = V[i][1]*sin(r)+V[i][2]*cos(r);
    }
    }
    if(a=='y')
    {
    for(i=0;i<8;i++)
    {
        nV[i][0] = V[i][0]*cos(r) + V[i][2]*sin(r);
        nV[i][1] = V[i][1];
        nV[i][2] = -V[i][0]*sin(r) + V[i][2]*cos(r);
    }
    }

    if(a=='z')
    {

         for(i=0;i<8;i++)
        {
            nV[i][0] = V[i][0]*cos(r)-V[i][1]*sin(r);
            nV[i][1] = V[i][0]*sin(r)+V[i][1]*cos(r);
            nV[i][2] = V[i][2];
        }

    }

glColor3fv(color[0]);
drawpoly(0,1,2,3);
glColor3fv(color[1]);
drawpoly(6,2,3,7);
glColor3fv(color[2]);
drawpoly(5,6,7,4);
glColor3fv(color[3]);
drawpoly(5,1,0,4);
glColor3fv(color[4]);
drawpoly(5,1,2,6);
glColor3fv(color[5]);
drawpoly(4,0,3,7);

glutSwapBuffers();

}



int main(int argc,char**argv)
{
     printf("\nEnter the Axis of Rotation : ");
     scanf("%c",&a);
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowPosition(100,100);
     glutInitWindowSize(500, 500);
     glutCreateWindow("Lab-3 Rotation of Color Cube");
     glutDisplayFunc(draw);
     glutIdleFunc(spin);
     glEnable(GL_DEPTH_TEST);
     glutMainLoop();
     return 0;

}
