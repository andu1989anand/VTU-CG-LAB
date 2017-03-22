#include<GL/glut.h>
GLfloat vertices[8][3]={{-1.0,-1.0,-1.0},
{1.0,-1.0,-1.0},
{1.0,1.0,-1.0},
{-1.0,1.0,-1.0},
{-1.0,-1.0,1.0},
{1.0,-1.0,1.0},
{1.0,1.0,1.0},
{-1.0,1.0,1.0}};
GLfloat colors[8][3]={
{0.0,0.0,1.0},
{0.0,1.0,0.0},
{0.0,1.0,1.0},
{1.0,0.0,0.0},
{1.0,0.0,1.0},
{1.0,1.0,0.0},
{1.0,1.0,1.0},
{1.0,0.5,0.0}};
static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;
static GLdouble viewer[]={0,0,5};
GLfloat r,g,b;
int Submenu1,Submenu2,Submenu3;

void polygon(int a,int b,int c,int d)
{

glBegin(GL_POLYGON);
glColor3fv(colors[a]);
glVertex3fv(vertices[a]);
glColor3fv(colors[b]);
glVertex3fv(vertices[b]);
glColor3fv(colors[c]);
glVertex3fv(vertices[c]);
glColor3fv(colors[d]);
glVertex3fv(vertices[d]);
glEnd();
}


void colorcube()
{
polygon(0,1,2,3);
polygon(4,5,6,7);
polygon(0,4,7,3);
polygon(1,5,6,2);
polygon(0,1,5,4);
polygon(3,2,6,7);
}


void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glLoadIdentity();
gluLookAt(viewer[0],viewer[1],viewer[2],0,0,0,0,1,0);
glRotatef(theta[0],1.0,0.0,0.0);
glRotatef(theta[1],1.0,1.0,0.0);
glRotatef(theta[2],0.0,0.0,1.0);
glClearColor(r,g,b,0);
colorcube();
glFlush();
glutSwapBuffers();
glutPostRedisplay();
}


void mouse(int btn,int state,int x,int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
axis=0;
if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
axis=1;
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
axis=2;
theta[axis]+=2.0;
if(theta[axis]>360.0)
theta[axis]=360.0;
display();
}


void keys(unsigned char key,int x,int y)
{
if(key=='x') viewer[0]-=1;
if(key=='X') viewer[0]+=1;
if(key=='y') viewer[1]-=1;
if(key=='Y') viewer[1]+=1;
if(key=='z') viewer[2]-=1;
if(key=='Z') viewer[2]+=1;
display();
}


void reshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glFrustum(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,2.0,20.0);
else
glFrustum(-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,-2.0,2.0,2,20.0);
glMatrixMode(GL_MODELVIEW);
}


void color(int id)
{
switch(id)
{
 case 1:
        r=1;g=0;b=0;
        break; 

case 2:
        r=0;g=1;b=0;
        break; 

case 3:
        r=0;g=0;b=1;
        break; 
case 4:
        r=0;g=1;b=1;
        break; 
case 5:
        r=1;g=0;b=1;
        break; 
case 6:
        r=1;g=1;b=0;
        break; 
case 7:
       exit(0); 

}

}


int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutCreateWindow("cube");
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutKeyboardFunc(keys);
glutMouseFunc(mouse);
glEnable(GL_DEPTH_TEST);

Submenu1=glutCreateMenu(color);
    glutAddMenuEntry("RED",1);
    glutAddMenuEntry("GREEN",2);
    glutAddMenuEntry("BLUE",3);

Submenu2=glutCreateMenu(color);
     glutAddMenuEntry("CYAN",4);
     glutAddMenuEntry("MAGNETA",5);
     glutAddMenuEntry("YELLOW",6);
    

Submenu3=glutCreateMenu(color);
     glutAddSubMenu("RGB",Submenu1);
     glutAddSubMenu("CMY",Submenu2);
 


glutCreateMenu(color);
glutAddSubMenu("color",Submenu3);
    glutAddMenuEntry("EXIT",7);
glutAttachMenu(GLUT_RIGHT_BUTTON);
glutMainLoop();
}
