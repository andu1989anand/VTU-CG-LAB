#include<windows.h>
#include<GL/glut.h>
#include<string.h>

int ds=0;
float x1=200,x2=100,x3=200,x4=300,y1=200,y2=300,y3=400,y4=300;
int le[500],re[500],flag=0;

void text(int x,int y, char *s)
{
    int len,i;
	glRasterPos2f(x,y);
	len=(int)strlen(s);
	for(i=0;i<len;i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,s[i]);
}

void frontpage()
{
    char *colg="MAHARAJA INSTITUTE OF TECHNOLOGY MYSORE";
    char *dept="DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
    char *lab="COMPUTER GRAPHICS LABORATORY WITH MINI PROJECT [15CSL68]";
    char *project="\"PROJECT TITLE\"";
    char *stu1="STUDENT 01\n [4MH16CS000]";
    char *stu2="STUDENT 02\n [4MH16CS000]";

    glColor3f(1,0,0);
    text(100,520,colg);
    glColor3f(0,1,0);
    text(82,475,dept);
    glColor3f(1,0,1);
    text(60,400,lab);
    glColor3f(0,0,0);
    text(250,300,project);
    glColor3f(0,0,1);
    text(50,200,"TEAM MEMEBERS");
    glColor3f(0,0,0);
    text(50,160,stu1);
    text(50,120,stu2);

    glColor3f(0,0,1);
    text(400,200,"Project Guide:");
    glColor3f(0,0,0);
    text(400,170,"Prof. ANANDA KUMAR HN");
    text(400,150,"Assistant Professor");
    text(400,130,"Dept. of CS&E");
    text(400,110,"MIT Mysore");

    glColor3f(1,0,0);
    text(250,50,"Press \"SPACE\" to continue");

    glFlush();
	glutSwapBuffers();
}


void edgedetect(float x1,float y1,float x2,float y2,int *le,int *re)
{
	float mx,x,temp;
	int i;
	if((y2-y1)<0)
	{
		temp=y1;y1=y2;y2=temp;
		temp=x1;x1=x2;x2=temp;
	}
	if((y2-y1)!=0)
		mx=(x2-x1)/(y2-y1);
	else
		mx=x2-x1;
	x=x1;
	for(i=y1;i<=y2;i++)
	{
		if(x<(float)le[i])
			le[i]=(int)x;
		if(x>(float)re[i])
			re[i]=(int)x;
		x+=mx;
	}
}

void scanfill()
{
	int i,y;
	for(i=0;i<500;i++)
	{
		le[i]=500;
		re[i]=0;
	}

	edgedetect(x1,y1,x2,y2,le,re);
	edgedetect(x2,y2,x3,y3,le,re);
	edgedetect(x3,y3,x4,y4,le,re);
	edgedetect(x4,y4,x1,y1,le,re);
	for(y=0;y<500;y++)
	{
		if(le[y]<=re[y])
			for(i=(int)le[y];i<(int)re[y];i++)
            {
                glColor3f(0.0,0.0,1.0);
                glBegin(GL_POINTS);
                glVertex2i(i,y);
                glEnd();
                glFlush();
            }
	}
}



void mymenu(int id)
{
switch(id)
{
case 1: flag=1;
	break;
case 2: flag=0;
	break;
case 3: exit(0);
}
glutPostRedisplay();
}

void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    if(ds==0)
    frontpage();
    if(ds){
        glPointSize(3.0);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	glVertex2f(x2,y2);
	glVertex2f(x3,y3);
	glVertex2f(x4,y4);
	glEnd();

	if(flag)
	scanfill();
	glFlush();
    }

}

void createmenu()
{
    int sub;
    sub=glutCreateMenu(mymenu);
	glutAddMenuEntry("YES",1);
	glutAddMenuEntry("NO",2);

	glutCreateMenu(mymenu);
	glutAddSubMenu("Polygon Fill",sub);
	glutAddMenuEntry("Exit",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}


void key(unsigned char k, int x, int y)
{
	if(k==' ' && ds==0)
	{
		ds=1;
		createmenu();
	}
	glFlush();
	glutSwapBuffers();
	glutPostRedisplay();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000.0,800.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("text");
    glutDisplayFunc(display);
    gluOrtho2D(0,600,0,600);
    glutKeyboardFunc(key);
    glutMainLoop();
}
