#include<windows.h>
#include<GL/glut.h>
#include<string.h>

int ds=0;

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
    int i=0;
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

void menu()
{

	glClearColor(0.0,0.6,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,0.0,0.0);
	text(250,250,"PRESS!");
	text(250,200,"1:START QUIZ");
	text(250,150,"2:INSTRUCTIONS");
	text(250,100,"ESC:TO QUIT ANYTIME");
	glFlush();
	glutSwapBuffers();

}

void display()
{
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    if(ds==0)
    frontpage();
}

void key(unsigned char k, int x, int y)
{
	if(k==' '&&ds==0)
	{
		ds=1;
		menu();
	}
	glFlush();
	glutSwapBuffers();
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
