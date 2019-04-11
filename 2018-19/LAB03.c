//Draw a colour cube and spin it using OpenGL transformation matrices.

#include<windows.h>
#include<GL/glut.h>



float V[8][3]={{0,0,0},{0,0.5,0},{.5,.5,0},{.5,0,0},{0,0,.5},{0,.5,.5},{.5,.5,.5},{.5,0,.5}};
float color[8][3]={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,0,1},{0,0,0},{.5,0,.5}};
GLfloat d=0;

void spin()
{
d=d+0.0001;
if (d>360)
d=0;
glutPostRedisplay();
}



void drawpoly(int a,int b,int c, int d)
{

	glBegin(GL_POLYGON);
	//glColor3fv(color[a]);
	glVertex3fv(V[a]);
	//glColor3fv(color[b]);
	glVertex3fv(V[b]);
	//glColor3fv(color[c]);
	glVertex3fv(V[c]);
	//glColor3fv(color[d]);
	glVertex3fv(V[d]);
	glEnd();
	glFlush();

}

void draw()
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glRotatef(d,1,0,1);


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
        glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowPosition(100,100);
     glutInitWindowSize(500, 500);
     glutCreateWindow("Lab-8: Perspective Viewing with Camera");
     glutDisplayFunc(draw);
     glutIdleFunc(spin);
     glEnable(GL_DEPTH_TEST);
     glutMainLoop();
     return 0;

}
