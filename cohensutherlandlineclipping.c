/*5. Program to implement the Cohen-Sutherland line-clipping algorithm. Make provision to specify the 
input line, window for clipping and view port for displaying the clipped image.*/

#include<GL/glut.h>
#include<stdio.h>
#define outcode int

float x0,y0,x1,y1;
float xmin=50.0,ymin=50.0,xmax=100.0,ymax=100.0;
float xvmin=200.0,yvmin=200.0,xvmax=300.0,yvmax=300.0;
const int bottom=1,left=2,top=4,right=8;

outcode compute(float x,float y)
{
	outcode code=0;

	if(y>ymax)
		code|=top;
	else if(y<ymin)
		code|=bottom;

	if(x>xmax)
		code|=right;
	else if(x<xmin)
		code|=left;

return code;
}

void cohen(float x0,float y0,float x1,float y1)
{
	outcode outcode0,outcode1,outcodeOut;
	int accept=0,done=0;

	outcode0=compute(x0,y0);
	outcode1=compute(x1,y1);

do
	{
		if(!(outcode0|outcode1))
		{
			accept=1;
			done=1;
		}
		else if(outcode0 & outcode1)
			done=1;
		else
		{
			outcodeOut=outcode0?outcode0:outcode1;
			float x,y;

			if(outcodeOut & top)
			{
				x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
				y=ymax;
			}
			else if(outcodeOut & bottom)
			{
				x=x0+(x1-x0)*(ymin-y0)/(y1-y0);
				y=ymin;
			}
			else if(outcodeOut & right)
			{
				y=y0+(y1-y0)*(xmax-x0)/(x1-x0);
				x=xmax;
			}
			else
			{
				y=y0+(y1-y0)*(xmin-x0)/(x1-x0);
				x=xmin;
			}

			if(outcodeOut==outcode0)
			{
				x0=x;
				y0=y;
			
	outcode0=compute(x0,y0);
			}
			else
			{
				x1=x;
				y1=y;
				outcode1=compute(x1,y1);
			}
		}
	}while(!done);

 if(accept)
{
	float sx,sy,vx0,vx1,vy0,vy1;

	sx=(xvmax-xvmin)/(xmax-xmin);
	sy=(yvmax-yvmin)/(ymax-ymin);

	vx0=xvmin+(x0-xmin)*sx;
	vy0=yvmin+(y0-ymin)*sy;
	vx1=xvmin+(x1-xmin)*sx;
	vy1=yvmin+(y1-ymin)*sy;

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xvmin,yvmin);
	glVertex2f(xvmax,yvmin);
	glVertex2f(xvmax,yvmax);
	glVertex2f(xvmin,yvmax);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(vx0,vy0);
	glVertex2f(vx1,vy1);
	glEnd();
}
}

void display()
{
	
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin,ymin);
	glVertex2f(xmax,ymin);
	glVertex2f(xmax,ymax);
	glVertex2f(xmin,ymax);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINES);
	glVertex2f(x0,y0);
	glVertex2f(x1,y1);
	glEnd();
	
	cohen(x0,y0,x1,y1);

	glFlush();
}


void init()
{
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,600.0,0.0,600.0);
}

int main(int argc,char **argv)
{
	 printf("enter the window positions(xmin,ymin,xmax,ymax)\n");
 	scanf("%f%f%f%f",&xmin,&ymin,&xmax,&ymax);	

	printf("enter endpoints of line(x0,y0,y1,y2)\n");
	scanf("%f%f%f%f",&x0,&y0,&x1,&y1);

	printf("enter the viewport values(xmin,ymin,xmax,ymax)\n");
 	scanf("%f%f%f%f",&xvmin,&yvmin,&xvmax,&yvmax);

	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Cohen Sutherland");

	glutDisplayFunc(display);
	init();
	glutMainLoop();
}
