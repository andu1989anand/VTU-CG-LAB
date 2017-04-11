#include<math.h>
#include<stdio.h>
#include<GL/glut.h>

int m,n;
void draw_pixel(GLint cx,GLint cy)
{
	//glColor3f(1.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}


void Cylinder_draw(int m)
{
	GLint xc=100,yc=100,r=50;
	GLint i;
	for(i=0;i<m;i++)
		circle_draw(xc,yc+i,r);
}

void parallelepiped(int x1,int x2,int y1,int y2)
{
	glPointSize(5.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(x1,y1);
	glVertex2i(x2,y1);
	glVertex2i(x2,y2);
	glVertex2i(x1,y2);
	glEnd();
}


void parallelepiped_draw(int n)
{
	int x1=160,x2=300,y1=100,y2=175;
	GLint i;
	glColor3f(0.0,0.0,1.0);
	for(i=0;i<n;i++)
		parallelepiped(x1+i,x2+i,y1+i,y2+i);
}

void init(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,400.0,0.0,300.0);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glPointSize(2.0);
	Cylinder_draw(m);
	parallelepiped_draw(n);
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	printf("enter number of cylinders and pipelines\n");
	scanf("%d %d",&m,&n);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,50);
	glutInitWindowSize(400,300);
	glutCreateWindow("Cylinder and parallelepiped Display by Extruding Circle and Quadrilaterl ");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
